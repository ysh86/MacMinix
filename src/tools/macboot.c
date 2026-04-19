#include <mac/Events.h>
#include <mac/Windows.h>
#include <mac/Dialogs.h>
#include <mac/Resources.h>
#include <mac/Memory.h>
#include <mac/Fonts.h>
#include <mac/Packages.h>
#include <mac/Files.h>
#include <mac/BCD.h>
#include <mac/StdFile.h>
#include <mac/Segments.h>
#include <mac/Menus.h>
#include <mac/OSEvents.h>

#include "../kernel/setup.h"

#define KERNEL "kernel"
#define MM     "mm"
#define FS     "fs"
#define INIT   "init"

#define ROUND_UP_TO_CLICK(amt)   (((amt) + 0xffL) & 0xffffff00L)
#define ROUND_DOWN_TO_CLICK(amt) ((amt) & 0xffffff00L)

/*
 *  Boot kernel, mm, fs, and init.
 *  Joe Pickert 10/10/88
 */

static long gsize[8];

extern char *ApplLimit;
extern char *HeapEnd;
extern char *ApplZone;
extern char *CurrentA5;
extern char *CurStackBase;

static void center( Rect *r, WindowPtr w );
static void inform( char *s, int font, int size, int face, int skip );
static void putc( char c, int font, int size, int face );
static void hex( unsigned long i, int ndig );
static void warn( char *s1, char *s2, char *s3, char *s4, int fatal );
static long load( char *w, long *left, char *name, char *file, int idx );

extern long relocate( long *hdrp, char *txt, unsigned long segsizes[] );
extern void setup( struct config *cf, short dbox, short warn );
extern void seta7( char *newa7 );

static
void center(
Rect *r,
WindowPtr w
){
    int th = (qd->thePort->portRect.right  - qd->thePort->portRect.left
                - (r->right  - r->left))/2;
    int tv = (qd->thePort->portRect.bottom - qd->thePort->portRect.top
                - (r->bottom - r->top)) /2;
    MoveWindow(w, th, tv, 1);
}

static
void inform(
char *s,
int font,
int size,
int face,
int skip
){
    static WindowPtr w = 0;
    static ypos = 0;
    Rect r;
    GrafPtr oldp;
    EventRecord e;

    if (s == 0) {
        if (w) CloseWindow(w);
        return;
    }

    GetPort(&oldp);
    if (w == 0) {
        SetRect(&r, 0, 0, 400, 135);
        w = NewWindow(0L, &r, "", 0, altDBoxProc, (WindowPtr)-1, 0, 0L);
        if (w == 0) return;
        center(&r, w);
        GetNextEvent(0, &e);
        ShowWindow(w);
        SetPort(w);
    } else {
        SetPort(w);
    }

    if (skip) {
        ypos = ypos + skip;
        MoveTo(20, ypos);
    }
    TextFont(font);
    TextSize(size);
    TextFace(face);
    DrawString(s);

    SetPort(oldp);
}

static
void putc(
char c,
int font,
int size,
int face
){
    char s[2];

    s[0] = c;
    s[1] = 0;
    inform(s, font, size, face, 0);
}

static
void hex(
unsigned long i,
int ndig
){
    int j;

    putc('0', monaco, 9, normal);
    putc('x', monaco, 9, normal);
    for (j = ndig*4; j >= 0; j -= 4)
        putc("0123456789ABCDEF"[(i >> j) & 0xf], monaco, 9, normal);
}

static
void warn(
char *s1,
char *s2,
char *s3,
char *s4,
int  fatal
){
    ParamText(s1, s2, s3, s4);
    if (fatal) {
        StopAlert(128, 0L);
        ExitToShell();
    } else {
        CautionAlert(128, 0L);
    }
}

static
long load(
char *w,
long *left,
char *name,
char *file,
int idx
){
    Handle  h;
    unsigned long sizes[3];
    unsigned long need, tsize;
    long *hdr;
    char *loadat, *src, *p;
    long relocsize, i;

    if ((h = GetNamedResource((ResType)"BOOT", file)) == (Handle)0)
        warn("Can't find ", file, "", "", 1);
    HLock(h);

    hdr = (long *)*h;
    src = *h;
    src += 0x20;
    loadat = w;

    relocsize = GetHandleSize(h) - 0x20L - hdr[2] - hdr[3];
    need = hdr[2] + hdr[3] + hdr[4] + relocsize;
    if (need > *left)
        warn("Not enough memory left to load ", file, "", "", 1);
    BlockMove(src, w, hdr[2] + hdr[3]);

    src += hdr[2] + hdr[3];
    w += hdr[2] + hdr[3];
    for (p = w, i = 0; i < hdr[4]; i++)
        *p++ = 0;
    w += hdr[4];
    BlockMove(src, w, relocsize);

    if (relocate(hdr, loadat, sizes) < 0)
        warn(file, ": Error in relocation", "", "", 1);

    HUnlock(h);
    ReleaseResource(h);

    inform(name, monaco, 9, bold, 12);
    inform(" at ", monaco, 9, normal, 0);
    hex((unsigned long)loadat, 5);
    inform(" : ", monaco, 9, normal, 0);
    hex(sizes[0], 5);
    putc('+', monaco, 9, normal);
    hex(sizes[1], 5);
    putc('+', monaco, 9, normal);
    hex(sizes[2], 5);

    tsize = ROUND_UP_TO_CLICK(sizes[0] + sizes[1] + sizes[2]);
    gsize[idx] = sizes[0];
    gsize[idx+1] = tsize - gsize[idx];
    *left = *left - tsize;

    return tsize;
}

int main(int argc, char *argv[])
{
    char *mem;
    long sleft, left;
    int (*save)();
    Handle h;
    long g;
    struct config conf;

    InitGraf((Ptr)&qd->thePort);
    InitFonts();
    InitWindows();
    InitMenus();
    TEInit();
    InitDialogs(0L);
    InitCursor();
    FlushEvents((short)-1, (short)0);

    setup(&conf, Button() == 1, 0);

    inform("   MacMINIX 1.5 Copyright ", systemFont, 12, normal, 40);
    putc((char)0xa9, systemFont, 12, normal);
    inform(" 1991 Prentice-Hall Inc.", systemFont, 12, normal, 0);

    /*
     * Get as much memory as is reasonable.  It is allocated on the 
     * STACK!
     */
    MaxMem(&g);
    SetApplLimit((char *)((long)ApplZone + ((long)conf.heap * 1024L)));
    if (HeapEnd > ApplLimit)
        SetApplLimit(HeapEnd);
    mem = (char *)ROUND_DOWN_TO_CLICK((long)ApplLimit + (long)(32*1024L));
    save = (int (*)())mem;
    left = ROUND_UP_TO_CLICK((long)CurStackBase - (long)mem);
    seta7(mem);
    sleft = left;

    /*
     * load & relocate kernel, mm, fs, and init
     */
    inform("", monaco, 9, normal, 15);
    mem += load(mem, &left, "    kernel ", KERNEL, 0);
    mem += load(mem, &left, "    mm     ", MM, 2);
    mem += load(mem, &left, "    fs     ", FS, 4);
    mem += load(mem, &left, "    init   ", INIT, 6);
    inform(0L, monaco, 9, normal, 0);

    (*save)(qd, (long)CurrentA5, (long)save, sleft,
            gsize[0], gsize[1], gsize[2], gsize[3],
            gsize[4], gsize[5], gsize[6], gsize[7]);

    return 0;
}
