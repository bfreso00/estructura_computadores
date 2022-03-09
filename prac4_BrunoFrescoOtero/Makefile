ej1.out:
	gcc EJ1/calcula_Nota.c -o ej1.out

ej2.out:
	gcc EJ2/suma_N_Numeros.c -o ej2.out
	
ej3.out:
	gcc EJ3/potencia.c -o ej3.out	
	
ej4.out:
	gcc EJ4/calc_Volu.c -o ej4.out
	
ej5.out:
	gcc EJ5/comp_Num_Pares.c -o ej5.out
	
ej6.out:
	gcc EJ6/factorial.c -o ej6.out

clean:
	rm ej1.out ej2.out ej3.out ej4.out ej5.out ej6.out
	
test1: ej1.out
	bash EJ1/test.sh

test2: ej2.out
	bash EJ2/test.sh
	
test3: ej3.out
	bash EJ3/test.sh
	
test4: ej4.out
	bash EJ4/test1.sh
	
test4_2: ej4.out
	bash EJ4/test2.sh
	
test5: ej5.out
	bash EJ5/test.sh
	
test6: ej6.out
	bash EJ6/test.sh
	
test:
	make test1 test2 test3 test4 test4_2 test5 test6 
