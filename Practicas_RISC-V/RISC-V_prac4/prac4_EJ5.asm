	.data
cad1: .asciz "Introduzca una cadena:\n"
cadPara: .space 100
cad2: .asciz "\nIntroduzca un numero:\n"
cad3: .asciz "\nIntroduzca un numero mayor que el previo:\n"
cadResul: .space 100
cad4: .asciz "\nCadena resultante:\n"
error: .asciz "\nLos numeros deben ser ambos positivos.\n"
	.globl main
	.text
main:
	li a7, 4
	la a0, cad1
	ecall
	
	li a7, 8
	la a0, cadPara
	li a1, 100
	ecall
	
	li a7, 4
	la a0, cad2
	ecall
	
	li a7, 5
	ecall
	
	mv t0, a0
	
	li a7, 4
	la a0, cad3
	ecall
	
	li a7, 5
	ecall
	
	mv t1, a0
	
	jal x1, compr
	
	addi t0, t0, -1
	addi t1, t1, -1
	li t2, 0
	la a0, cadPara
	la a1, cadResul
	jal x1, subcadena
	
	li a7, 4
	la a0, cad4
	ecall
	
	li a7, 4
	la a0, cadResul
	ecall
	
	li a7, 10
	ecall
	
subcadena:
	beq t2, t0, bucle
	addi a0, a0, 1
	addi t2, t2, 1
	j subcadena
	
bucle:
	lb t3, (a0)
	lb t4, (a1)
	add t4, t4, t3
	sb t4, (a1)
	addi a1, a1, 1
	beq t2, t1, fin
	addi a0, a0, 1
	addi t2, t2, 1
	j bucle
	
fin:
	lb t4, (a1)
	addi t4, t4, 10
	sb t4, (a1)
	addi a1, a1, 1
	lb t4, (a1)
	addi t4, t4, 0
	sb t4, (a1)
	ret

compr:
	blt t0, zero, esneg
	blt t1, zero, esneg
	ret

esneg:
	li a7, 4
	la a0, error
	ecall
	
	li a7, 4
	la a0, cad2
	ecall
	
	li a7, 5
	ecall
	
	mv t0, a0
	
	li a7, 4
	la a0, cad3
	ecall
	
	li a7, 5
	ecall
	
	mv t1, a0
	
	j compr
