#
! public labels
	.define	begtext
	.define	begdata
	.define	begbss
	.define	_exit
	.define	_data_org
! external references
	.extern	_main
	.extern	_stackpt
#ifdef ACK
	.sect	.text
	.sect	.rom
	.sect	.data
	.sect	.bss
#endif ACK

	.sect	.text
begtext:
	move.l	_stackpt,sp
	jsr	_main
_exit:
	bra	_exit		! this will never be executed

	.define	_start_click
_start_click:
	move.l	_data_org+2,d0
	rts

	.sect	.data
begdata:
	! fs needs to know where build stuffed table
_data_org:
	! 0xDADA is magic number for build
	.data2	0xDADA,0,0,0,0,0,0,0
	.data2	0,0,0,0,0,0,0,0

	.sect	.bss
begbss:
