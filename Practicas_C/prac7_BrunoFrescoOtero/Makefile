ej1.out:
	gcc EJ1/copia.c -o ej1.out

ej2.out:
	gcc EJ2/cadena.c -o ej2.out
	
ej3.out:
	gcc EJ3/cadenaInver.c -o ej3.out	

clean:
	rm ej1.out ej2.out ej3.out
	
test1: ej1.out
	bash EJ1/test.sh

test2: ej2.out
	bash EJ2/test.sh
	
test3: ej3.out
	bash EJ3/test.sh
	
test:
	make test1 test2 test3
