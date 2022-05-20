#include <stdio.h>
int main()
{
	int base, exponente, pot, i;
	printf("Escriba un número(base): ");
	scanf("%d", &base);
	printf("Escriba un número(exponente): ");
	scanf("%d", &exponente);
	if((base >= 1) && (exponente >= 1)){
		pot = 1;
		i = 1;
		do{
			pot = pot * base;
			exponente = exponente - 1;
		} while (exponente >= 1);
		printf("La potencia es: %d\n", pot);	
	} else {
		printf("La base y el exponente han de ser mayores o iguales a 1.");
	}
	return 0;
}
