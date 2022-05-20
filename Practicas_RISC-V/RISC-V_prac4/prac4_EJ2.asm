	.data
cad1: .asciz "Introduzca una cadena:\n"
cadPara:.space 100
cadResul: .space 100
cad2: .asciz "Copia de la cadena:\n"
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
	
	la a0, cadPara
	la a1, cadResul
	jal x1, strcpy
	
	li a7, 4
	la a0, cad2
	ecall
	
	li a7, 4
	la a0, cadResul
	ecall
	
	li a7, 10
	ecall
	
strcpy:
	lb t0, (a0)
	lb t1, (a1)
	beq t0, x0, fin
	add t1, t1, t0
	sb t1, (a1)
	addi a0, a0, 1
	addi a1, a1, 1
	j strcpy
fin:
	addi t1, t1, 10
	sb t1, (a1)
	li t1, 0
	addi a1, a1, 1
	sb t1, (a1)
	ret	
