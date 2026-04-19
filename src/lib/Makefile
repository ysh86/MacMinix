
CHIP = mac/crt
ORDER  = LIBORDER
AR	= ar
ARFLAGS	= r

SRC	= /usr/src/lib

SUB	= ansi posix other $(CHIP) mac/libmac
OBJ	= head.o crtmac.o crtso.o end.o relocate.o
LIB	= libc.a
ALL	= $(OBJ) $(LIB)

MACORDER = LIBMACORDER
MACLIB = libmac.a

all:	sub $(ALL) $(MACLIB)

sub:
	for i in $(SUB); do cd $$i; $(MAKE) all; cd $(SRC); done

$(LIB):	$(SUB) $(ORDER)
	rm -f $(LIB)
	while read x; do $(AR) $(ARFLAGS) $(LIB) $$x; done < $(ORDER)

$(MACLIB):	$(SUB) $(MACORDER)
	rm -f $(MACLIB)
	while read x; do $(AR) $(ARFLAGS) $(MACLIB) $$x; done < $(MACORDER)

$(OBJ):
	cd $(CHIP); $(MAKE) $@; cp $@ $(SRC)/

clean:
	for i in $(SUB); do cd $$i; $(MAKE) $@; cd $(SRC); done

clobber:
	rm -f $(OBJ) $(LIB) $(MACLIB)
