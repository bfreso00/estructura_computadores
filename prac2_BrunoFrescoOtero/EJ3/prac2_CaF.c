#include <stdio.h>
int main(void)
{
	float C, F;
	printf("Escriba un valor en grados C: ");
	scanf("%f", &C);
	F = C * 9/5 + 32;
	printf("El valor en grados F de la cantidad introducida es: %f", F);
	printf("\nFin del programa.\n");
	return 0;
}
