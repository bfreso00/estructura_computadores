ej1.out:
	gcc EJ1/muestra3.c -o ej1.out

ej2.out:
	gcc EJ2/eva_Nota.c -o ej2.out
	
ej3.out:
	gcc EJ3/eva_Nota2.c -o ej3.out	
	
ej4.out:
	gcc EJ4/selec_Mes.c -o ej4.out
	
ej5.out:
	gcc EJ5/num_Sum.c -o ej5.out
	
ej6.out:
	gcc EJ6/potencia.c -o ej6.out
	
ej7.out:
	gcc EJ7/calc_Volu.c -o ej7.out

ej8.out:
	gcc EJ8/calc_Volu_Cond.c -o ej8.out

ej9.out:
	gcc EJ9/comp_Num_Pares.c -o ej9.out
	
clean:
	rm ej1.out ej2.out ej3.out ej4.out ej5.out ej6.out ej7.out ej8.out ej9.out
	
test1: ej1.out
	bash EJ1/test1.sh
	
test1_2: ej1.out
	bash EJ1/test2.sh

test2: ej2.out
	bash EJ2/test.sh
	
test3: ej3.out
	bash EJ3/test.sh
	
test4: ej4.out
	bash EJ4/test.sh
	
test5: ej5.out
	bash EJ5/test.sh
	
test6: ej6.out
	bash EJ6/test.sh
	
test7: ej7.out
	bash EJ7/test1.sh
	
test7_2: ej7.out
	bash EJ7/test2.sh

test8: ej8.out
	bash EJ8/test1.sh
	
test8_2: ej8.out
	bash EJ8/test2.sh
	
test9: ej9.out
	bash EJ9/test.sh
	
test:
	make test1 test1_2 test2 test3 test4 test5 test6 test7 test7_2 test8 test8_2 test9
