ej1.out:
	gcc EJ1/cadenas.c -o ej1.out

ej2.out:
	gcc EJ2/info.c -o ej2.out	

clean:
	rm ej1.out ej2.out
	
test1: ej1.out
	bash EJ1/test.sh

test2: ej2.out
	bash EJ2/test.sh
	
test:
	make test1 test2
