#include <stdio.h>

int factorial(int num_Para);
int main(){
	int num, facto;
	printf("Introduzca un numero: ");
	scanf("%d", &num);
	facto = factorial(num);
	printf("El factorial de %d es: %d\n", num, facto);
	return 0;
}

int factorial(int num_Para){
	int total;
	total = 1;
	for(num_Para; num_Para >= 1; num_Para--){
		total = total * num_Para; 
	}
	return total;
}
