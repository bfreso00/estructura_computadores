	.data
cad1: .asciz "\nIntroduzca un numero:\n"
cad2: .asciz "\nNumero de divisores del numero introducido:\n"
cad3: .asciz "\nEl numero de divisores del numero introducido es par.\n"
cad4: .asciz "\nEl numero de divisores del numero introducido es impar.\n"
error: .asciz "\nEl numero introducido debe ser positivo mayor que 1.\n"

	.globl main
	.text
main:
	li a7, 4
	la a0, cad1
	ecall
	
	li a7, 5
	ecall
	
	mv t0, a0
	li t1, 1
	
	jal x1, compr
	
	jal x1, sub1
	
	mv t0, a0
	mv t1, a1
	
	li a7, 4
	la a0, cad2
	ecall
	
	li a7, 1
	mv a0, t0
	ecall
	
	beq t1, zero, espar
	
	li a7, 4
	la a0, cad4
	ecall
	
	li a7, 10
	ecall

espar:
	li a7, 4
	la a0, cad3
	ecall
	
	li a7, 10
	ecall
 
sub1:
	jal x2, sub2
	mv t0, a0
	li t1, 2
	remu t2, t0, t1
	mv a0, t0
	mv a1, t2
	ret
sub2:
	li t1, 0
	li t2, 2
	jal x3, divisiones
	jalr x0, 0(x2)
	
divisiones:
	beq t2, t0, fin
	remu t3, t0, t2
	beq t3, zero, contador
	bne t3, zero, siguiente

contador:
	addi t1, t1, 1
	divu t0, t0, t2
	j divisiones
	
siguiente:
	addi t2, t2, 1
	mv t0, a0
	j divisiones

fin:
	addi t1, t1, 2
	mv a0, t1
	jalr x0, 0(x3)
	
	
compr:
	beq t0, t1, esnegoo1
	blt t0, zero, esnegoo1
	ret

esnegoo1:
	li a7, 4
	la a0, error
	ecall
	
	li a7, 4
	la a0, cad1
	ecall
	
	li a7, 5
	ecall
	
	mv t0, a0
	
	j compr