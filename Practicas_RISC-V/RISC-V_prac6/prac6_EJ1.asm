	.data
cad1: .asciz "\nIntroduzca un caracter en el MMIO.\n"
cad2: .asciz "\nEstado de la cadena guardada en memoria:\n"
cadResul: .space 11
	.data 0xFFFF0000
controlT: .space 1
	.data 0xFFFF0004
datosT: .space 1
	.data 0xFFFF0008
controlP: .space 1
	.data 0xFFFF000C
datosP: .space 1
	.globl main
	.text
main:
	la a1, cadResul
	la a2, controlT
	jal x1, imprChar
	
	li a7, 4
	la a0, cad2
	ecall
	
	li a7, 4
	la a0, cadResul
	ecall
	
	li a7, 10
	ecall

imprChar:
	li t0, 0
	li t1, 10
bucle:
	li a7, 4
	la a0, cad1
	ecall
	
comprueba_estado:
	lb t2, (a2)
	andi t2, t2, 1
	beq t2, zero, comprueba_estado
	
	la a2, datosT
	lb t2, (a2)
	sb t2, (a1)
	addi a1, a1, 1
	sb zero, (a1)
	addi t0, t0, 1
	bne t0, t1, bucle
	ret