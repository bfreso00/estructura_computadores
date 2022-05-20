#include <stdio.h>

void calculo_Pares(int num1_Para, int num2_Para);
int main(){
	int num1, num2;
	do{
		printf("Introduzca el primer número:");
		scanf("%d", &num1);
		printf("Introduzca el segundo número:");
		scanf("%d", &num2);
		if(num1 >= num2) {
			printf("El primer número debe ser menor que el segundo.\n");
		} else {
			calculo_Pares(num1, num2);
			return 0;
			}
	} while(num1 >= num2);		
}

void calculo_Pares(int num1_Para, int num2_Para){
	int resto;
	while(num2_Para >= num1_Para){
		resto = num2_Para % 2;
		if(resto == 0){
			printf("Numero par encontrado: %d\n", num2_Para);
		}
			num2_Para = num2_Para - 1;
	}
	return;
}
