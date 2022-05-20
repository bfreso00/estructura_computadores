ej1.out:
	gcc EJ1/sum_Num_Ran.c -o ej1.out

ej2.out:
	gcc EJ2/matriz_Id.c -o ej2.out
	
ej3.out:
	gcc EJ3/password.c -o ej3.out	
	
ej4.out:
	gcc EJ4/matriz.c -o ej4.out
	
ej5.out:
	gcc EJ5/suma.c -o ej5.out
	
ej6.out:
	gcc EJ6/sumaColumnas.c -o ej6.out

ej7.out:
	gcc EJ7/producto.c -o ej7.out

clean:
	rm ej1.out ej2.out ej3.out ej4.out ej5.out ej6.out ej7.out
	
test1: ej1.out
	bash EJ1/test.sh

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
	bash EJ7/test.sh
	
test:
	make test1 test2 test3 test4 test5 test6 test7
