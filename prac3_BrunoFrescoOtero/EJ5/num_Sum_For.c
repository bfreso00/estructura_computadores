#include <stdio.h>
int main()
{
	int num, total, i;
	printf("Escriba los números a sumar: ");
	scanf("%d", &num);
	total = 0;
	i = 1;
	if(num > 0){
		for(i; i<=num; i++){
			total = total + i;
		}
		printf("La suma es: %d \n", total);
	} else {
		printf("Debe introducir un numero mayor que 0.\n");
	}
	return 0;
}
