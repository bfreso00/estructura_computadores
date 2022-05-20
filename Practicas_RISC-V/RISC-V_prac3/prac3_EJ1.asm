	.data
cad1: .asciz "\nIntroduzca una cadena:"
cad2: .space 100
cad3: .asciz "\nLa suma de los valores ASCII de la cadena es: \n"
cad4: .asciz "\nLa cadena tiene un total de caracteres de: \n"
	.globl main
	.text
main:
	li a7, 4
	la a0, cad1
	ecall
	
	li a7, 8
	la a0, cad2
	li a1, 100
	ecall
	
	la a0, cad2
	jal x1, funcion
	
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
	
funcion:
	li t0, 0
	li t1, 0
bucle:
	lb t2, (a0)
	beq t2, x0, fin
	addi t0, t0, 1
	add t1, t1, t2
	addi a0, a0, 1
	j bucle
fin:
	mv a0, t0
	addi t1, t1, 10
	mv a1, t1
	ret
