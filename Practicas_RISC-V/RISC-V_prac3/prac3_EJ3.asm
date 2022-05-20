	.data
datos1: .half 4, 7, 2
	.align 2
	.word 1, -5
	.byte 4
	.align 1
	.half 3
	.align 2
	.word -3
	.space 2
	.byte 'c'
datos2: .byte 2, 3, 5, 7
cad1: .align 1
	.asciz "\nResultado del registro:\n"
cad2: .asciz "\n(Operación 2)Comprobacion del registro:\n"
cadResul: .space 10
	.globl main
	.text

main:
	la t0, datos1
	lw t1, 8(t0)
	lh t2, 18(t0)
	add t3, t2, t1
	sb t3, 24(t0)
	
	li a7, 4
	la a0, cad1
	ecall
	
	li a7, 1
	mv a0, t3
	ecall
	
	la t0, datos2
	lb t1, (t0)
	lb t2, -1(t0)
	add t2, t2, t1
	sh t2, -11(t0)

	li a7, 4
	la a0, cad1
	ecall
	
	li a7, 1
	mv a0, t2
	ecall
	
	li a7, 10
	ecall
	
	
	
	

