	.data
datos1: .byte 4
	.align 2
	.word -1
	.byte 3
	.align 1
	.space 2
	.half 8
	.align 2
	.word -3
	.byte 'b'
	
datos2: .byte 6
cad1: .align 2
	.asciz "\nValor final del registro:\n"
	.globl main
	.text

main:
	la t0, datos1
	lw t1, 4(t0)
	lh t2, 12(t0)
	add t1, t1, t2
	sb t1, 14(t0)
	
	li a7, 4
	la a0, cad1
	ecall
	
	li a7, 1
	mv a0, t1
	ecall
	
	la t0, datos2
	lb t1, (t0)
	lb t3, -13(t0)
	add t3, t3, t2
	mul t3, t3, t1
	sb t3, -21(t0)
	
	li a7, 4
	la a0, cad1
	ecall
	
	li a7, 1
	mv a0, t3
	ecall
	
	li a7, 10
	ecall
