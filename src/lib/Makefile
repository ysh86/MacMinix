
CHIP = mac/crt
ORDER  = LIBORDER
AR	= ar
ARFLAGS	= r

SUB	= ansi posix other $(CHIP)
OBJ	= head.o crtmac.o crtso.o end.o relocate.o
LIB	= libc.a
ALL	= $(OBJ) $(LIB)

all:	sub $(ALL)

sub:
	for i in $(SUB); do cd $$i; $(MAKE) all; cd ..; done

$(LIB):	$(SUB) $(ORDER)
	rm -f $(LIB)
	while read x; do $(AR) $(ARFLAGS) $(LIB) $$x; done < $(ORDER)

$(OBJ):
	cd $(CHIP); $(MAKE) $@; cp $@ ..

clean:
	for i in $(SUB); do cd $$i; $(MAKE) $@; cd ..; done

clobber:
	rm -f $(OBJ) $(LIB)
