#include <stdio.h>

int main(){
	int num1, num2, resto;
	do{
		printf("Introduzca el primer número:");
		scanf("%d", &num1);
		printf("Introduzca el segundo número:");
		scanf("%d", &num2);
		if(num1 >= num2) {
			printf("El primer número debe ser menor que el segundo.\n");
		} else {
			while(num2 >= num1){
				resto = num2 % 2;
				if(resto == 0){
					printf("Numero par encontrado: %d\n", num2);
				}
				num2 = num2 - 1;
			}
			return 0;
			}
	} while(num1 >= num2);		
}

