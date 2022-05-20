ej1.out:
	gcc EJ1/maximo.c -o ej1.out

ej2.out:
	gcc EJ2/minimo.c -o ej2.out
	
ej3.out:
	gcc EJ3/minimoFilas.c -o ej3.out	
	
ej4.out:
	gcc EJ4/producto.c -o ej4.out

clean:
	rm ej1.out ej2.out ej3.out ej4.out
	
test1: ej1.out
	bash EJ1/test.sh

test2: ej2.out
	bash EJ2/test.sh
	
test3: ej3.out
	bash EJ3/test.sh
	
test4: ej4.out
	bash EJ4/test.sh
	
test:
	make test1 test2 test3 test4
