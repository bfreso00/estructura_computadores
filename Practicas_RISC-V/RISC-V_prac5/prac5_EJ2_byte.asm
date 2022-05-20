	.data
datos: .space 10
       .space 10
cad1:  .align 1
	.asciz "\nIntroduzca un numero:\n"

	.globl main
	.text
main:
	la t0, datos
	li a1, 10
	li a2, 0
impr:
	li a7, 4
	la a0, cad1
	ecall
	
	li a7, 5
	ecall
	
	mv t1, a0
	
	sb t1, (t0)
	addi t0, t0, 1
	addi a2, a2, 1
	beq a2, a1, apilar
	j impr

apilar:
	la t0, datos
subapilar:
	lb t1, (t0)
	addi sp, sp, -1
	sb t1, (sp)
	addi t0, t0, 1
	addi a2, a2, -1
	beq a2, zero, desapilar
	j subapilar
	
desapilar:
	lb t2, (sp)
	addi sp, sp, 1
	sb t2, (t0)
	addi t0, t0, 1
	addi a2, a2, 1
	beq a2, a1, fin
	j desapilar
fin:	
	li a7, 10
	ecall