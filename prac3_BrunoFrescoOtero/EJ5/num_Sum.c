#include <stdio.h>
int main()
{
	int num, total, i;
	printf("Escriba los números a sumar: ");
	scanf("%d", &num);
	total = 0;
	i = 1;
	if(num >= 1){
		while(i <= num) {
			total = total + i;
			i = i + 1;
		}
		printf("La suma es: %d\n", total);
	} else {
		printf("Introduzca un numero mayor o igual a 1.\n");
	}
	return 0;
}
