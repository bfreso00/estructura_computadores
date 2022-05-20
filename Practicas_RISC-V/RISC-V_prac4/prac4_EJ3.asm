	.data
cad1: .asciz "Introduzca un numero:\n"
cad2: .asciz "Introduzca un numero mayor al previo:\n"
cad3: .asciz "\nNº de numeros impares entre ellos:\n"
cad4: .asciz "\nNº de numeros pares entre ellos;\n"
	.globl main
	.text
main:
	li a7, 4
	la a0, cad1
	ecall
	
	li a7, 5
	ecall
	
	mv t0, a0
	
	li a7, 4
	la a0, cad2
	ecall
	
	li a7, 5
	ecall
	
	mv t1, a0
	
	jal x1, calculoparidad
	
	mv t0, a0
	mv t1, a1
	
	li a7, 4
	la a0, cad3
	ecall
	
	li a7, 1
	mv a0, t1
	ecall
	
	li a7, 4
	la a0, cad4
	ecall
	
	li a7, 1
	mv a0, t0
	ecall
	
	li a7, 10
	ecall
	
calculoparidad:
	li t2, 0
	li t3, 0
	li t4, 2
bucle:
	addi t0, t0, 1
	beq t0, t1, fin
	remu t5, t0, t4
	beq t5, zero, espar
	addi t3, t3, 1
	j bucle
espar:
	addi t2, t2, 1
	j bucle
fin:
	mv a0, t2
	mv a1, t3
	ret