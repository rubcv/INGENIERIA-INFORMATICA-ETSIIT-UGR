.section .data
	.macro linea
	 #	.int 1,1,1,1
	 # 	.int 2,2,2,2
	 # 	.int 1,2,3,4
	 # 	.int -1,-1,-1,-1
	 # 	.int 0xffffffff,0xffffffff,0xffffffff,0xffffffff
	 # 	.int 0x08000000,0x08000000,0x08000000,0x08000000
	 #	.int 0x10000000,0x20000000,0x40000000,0x80000000
	.endm
lista:	.irpc i,12345678
		linea
	.endr
