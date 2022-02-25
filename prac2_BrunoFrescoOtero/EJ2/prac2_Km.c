#include <stdio.h>
int main(void)
{
	float Km, Millas, Yardas, Pies;
	printf("Escriba el valor de kilometros a pasar: "),
	scanf("%f", &Km);
	Millas = Km / 1.60;
	Pies = Km * 100000 / 30.48;
	Yardas = Km * 100000 / 91.44;
	printf("Las millas son: %f \nLos pies son: %f \nLas yardas son: %f \nFin del programa.\n", Millas, Pies, Yardas); 	
}
