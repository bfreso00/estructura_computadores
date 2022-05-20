	.data
cad1: .asciz "Introduzca un número:\n"
cad2: .asciz "\nNumero de 1's en su representacion binaria:\n"
	.globl main
	.text
main:
	li a7, 4
	la a0, cad1
	ecall
	
	li a7, 5
	ecall
	
	mv t0, a0
	
	jal x1, calculounos
	
	mv t0, a0
	
	li a7, 4
	la a0, cad2
	ecall
	
	li a7, 1
	mv a0, t0
	ecall
	
	li a7, 10
	ecall
	
calculounos:
	li t1, 0
	li t2, 2
	li t3, 1

divisiones:
	remu t4, t0, t2
	bne t4, zero, contador
	divu t0, t0, t2
	beq t0, t3, fin
	j divisiones
	
contador:
	addi t1, t1, 1
	divu t0, t0, t2
	beq t0, t3, fin
	j divisiones
fin:
	addi t1, t1, 1
	mv a0, t1
	ret