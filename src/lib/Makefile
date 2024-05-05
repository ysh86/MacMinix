ORDER  = LIBORDER
AR	= ar
ARFLAGS	= r

SRC	= /usr/src/lib

CHIP = mac/crt
SUB	= ansi posix other $(CHIP)
OBJ	= head.o crtmac.o crtso.o end.o relocate.o
LIB	= libc.a

all:	sub $(OBJ) $(LIB)

sub:
	for i in $(SUB); do cd $$i; $(MAKE) all; cd $(SRC); done

clean:
	for i in $(SUB); do cd $$i; $(MAKE) $@; cd $(SRC); done

$(LIB):	$(SUB) $(ORDER)
	rm -f $(LIB)
	while read x; do $(AR) $(ARFLAGS) $(LIB) $$x; done < $(ORDER)

$(OBJ):
	cd $(CHIP); $(MAKE) $@; cp $@ $(SRC)/

$(ORDER):
	@ls other/*.o ansi/*.o posix/*.o >$@

clobber:
	rm -f $(OBJ) $(LIB)
	rm -f $(ORDER)
