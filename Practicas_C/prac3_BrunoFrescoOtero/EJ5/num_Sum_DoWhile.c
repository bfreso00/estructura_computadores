#include <stdio.h>
int main()
{
	int num, total, i;
	printf("Escriba los números a sumar: ");
	scanf("%d", &num);
	total = 0;
	i = 1;
	if(num > 0) {
		do{
			total = total + i;
			i = i + 1;
		}while(i <= num);
		printf("La suma es: %d \n", total);
	} else {
		printf("Debe introducir un numero mayor que 0.\n");
	}
	printf("Fin del algoritmo.\n");
	return 0;
}
