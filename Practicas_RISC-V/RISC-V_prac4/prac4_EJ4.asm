	.data
cad1: .asciz "Introduzca una cadena:\n"
cad2: .asciz "\nIntroduzca un caracter contenido en la cadena:\n"
char: .space 3
cadPara: .space 100
cadResul: .space 100
cad3: .asciz "\nCadena original:\n"
cad4: .asciz "\nCadena resultante:\n"
cad5: .asciz "\nCarácteres eliminados:\n"
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
	
	li a7, 8
	la a0, char
	li a1, 3
	ecall
	
	la a0, cadPara
	la a1, cadResul
	la a2, char
	jal x1, quitachar
	
	mv t0, a0
	
	li a7, 4
	la a0, cad3
	ecall
	
	li a7, 4
	la a0, cadPara
	ecall
	
	li a7, 4
	la a0, cad4
	ecall
	
	li a7, 4
	la a0, cadResul
	ecall
	
	li a7, 4
	la a0, cad5
	ecall
	
	li a7, 1
	mv a0, t0
	ecall
	
	li a7, 10
	ecall
	
quitachar:
	li t0, 0
bucle:
	lb t1, (a0)
	lb t2, (a1)
	lb t3, (a2)
	beq t1, zero, fin
	beq t1, t3, contador
	add t2, t2, t1
	sb t2, (a1)
	addi a0, a0, 1
	addi a1, a1, 1
	j bucle
contador:
	addi t0, t0, 1
	addi a0, a0, 1
	j bucle
fin:
	addi t2, t2, 10
	sb t2, (a1)
	addi a1, a1, 1
	lb t2, (a1)
	addi t2, t2, 0
	sb t2, (a1)
	mv a0, t0
	ret 