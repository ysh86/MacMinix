#
	.define	_send
	.define	_receive
	.define	_sendrec
#ifdef ACK
	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
#endif ACK
! =====================================================================
!                           send and receive                          =
! =====================================================================
! send(), receive(), sendrec() destroy d0, d1, and a0.

! See ../h/com.h for C definitions
SEND	= 1
RECEIVE	= 2
BOTH	= 3

	.sect	.text

_send:	move.l	#SEND,d0	! send(dest, ptr)
	bra	L0

_receive:
	move.l	#RECEIVE,d0	! receive(src, ptr)
	bra	L0

_sendrec:
	move.l	#BOTH,d0	! sendrec(srcdest, ptr)
L0:				! d0 = SEND/RECEIVE/BOTH
	move.l	4(sp),d1	! d1 = dest-src
	move.l	8(sp),a0	! a0 = message pointer
	trap	#0		! trap to the kernel
	rts			! return
