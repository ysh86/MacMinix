
CHIP = mac/crt
ORDER  = LIBORDER
AR	= ar
ARFLAGS	= r

SRC	= /usr/src/lib

SUB	= ansi posix other $(CHIP)
OBJ	= head.o crtmac.o crtso.o end.o relocate.o
LIB	= libc.a
ALL	= $(OBJ) $(LIB)

all:	sub $(ALL)

sub:
	for i in $(SUB); do cd $$i; $(MAKE) all; cd $(SRC); done

$(LIB):	$(SUB) $(ORDER)
	rm -f $(LIB)
	while read x; do $(AR) $(ARFLAGS) $(LIB) $$x; done < $(ORDER)

$(OBJ):
	cd $(CHIP); $(MAKE) $@; cp $@ $(SRC)/

clean:
	for i in $(SUB); do cd $$i; $(MAKE) $@; cd $(SRC); done

clobber:
	rm -f $(OBJ) $(LIB)
