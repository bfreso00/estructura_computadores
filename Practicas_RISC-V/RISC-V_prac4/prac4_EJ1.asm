	.data
cad1: .asciz "Introduzca un número:"
cad2: .asciz "\nEl factorial del número introducido es:"
	.globl main
	.text
main:
	li a7, 4
	la a0, cad1
	ecall
	
	li a7, 5
	ecall
	
	mv t0, a0
	
	jal x1, factorial
	
	mv t0, a0
	
	li a7, 4
	la a0, cad2
	ecall
	
	li a7, 1
	mv a0, t0
	ecall
	
	li a7, 10
	ecall
	
factorial:
	li t1, 0
	addi t1, t0, 0
	li t2, 1
bucle:
	addi t1, t1, -1
	mul t0, t0, t1
	beq t1, t2, fin
	j bucle
fin:
	mv a0, t0
	ret
