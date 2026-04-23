/* This file contains the C startup code for Minix on the Macintosh. */
#include <minix/boot.h>
#include "kernel.h"
#include "proc.h"
#include "setup.h"

#include <mac/Quickdraw.h>
#include <mac/Events.h>
#include <mac/Dialogs.h>
#include <mac/Windows.h>
#include <mac/Menus.h>
#include <mac/Fonts.h>
#include <mac/Other.h>

PUBLIC  char k_stack[8192];
PUBLIC  phys_clicks sizes[8];
PUBLIC  phys_bytes free_bytes, mem_bytes;

PUBLIC struct qd *qd;
extern int *ROMBase;

/* start.s */
void setksp(void);

/*===========================================================================*
 *                                  cstart                                   *
 *===========================================================================*/
PUBLIC void cstart(
struct qd *q, long a5, long memat, long size,
long kc, long kd, long mc, long md, long fc, long fd, long ic, long id
) {
  /* Perform initializations. */
  phys_clicks *mm_data, *fs_data;
  struct config conf;

  qd = q;

  /* Record kernel and mem info */
  code_base = memat;
  data_base = memat+kc;
  mem_bytes = (phys_bytes)memat + size;
  free_bytes = mem_bytes - (kc + kd + mc + md + fc + fd + ic + id);

  /* Initialize macintosh */
  InitGraf((Ptr)&qd->thePort);
  InitFonts();
  InitWindows();
  InitMenus();
  TEInit();
  InitDialogs(0L);
  InitCursor();
  FlushEvents(everyEvent, 0);

  /* record sizes */
  sizes[1] = (kc+kd) >> CLICK_SHIFT; sizes[0] = 0;
  sizes[3] = (mc+md) >> CLICK_SHIFT; sizes[2] = 0;
  sizes[5] = (fc+fd) >> CLICK_SHIFT; sizes[4] = 0;
  sizes[7] = (ic+id) >> CLICK_SHIFT; sizes[6] = 0;

  /* set up fs data */
  fs_data = (phys_clicks *)(memat + kc + kd + mc + md + fc);
  if (fs_data[0] != 0xDADA)
    ExitToShell();
  fs_data[2] = ((memat + kc + kd + mc + md + fc + fd) >> CLICK_SHIFT);
  fs_data[3] = sizes[6];
  fs_data[4] = sizes[7];

  /* set up mm data */
  mm_data = (phys_clicks *)(memat + kc + kd + mc);
  if (mm_data[0] != 0xDADA)
    ExitToShell();
  mm_data[1] = memat >> CLICK_SHIFT;

  setup(&conf, 0, 0);
  if (conf.ram) {
    BOOT_DEV = DEV_FD0;
    ROOT_DEV = DEV_RAM;
  } else {
    BOOT_DEV = DEV_HD0;
    ROOT_DEV = DEV_HD0;
  }
  boot_parameters.bp_processor = FALSE; /* FS needs to know */

  set_exceptions(0);

  setksp();
  main();
}
