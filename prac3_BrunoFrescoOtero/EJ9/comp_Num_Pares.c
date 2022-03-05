#include <stdio.h>
int main(){
	char cadena;
	int num1, num2, cal_par;
	do{
		printf("Introduzca el primer número:");
		scanf("%d", &num1);
		printf("Introduzca el segundo número:");
		scanf("%d", &num2);
		if(num1 >= num2) {
			printf("El primer número debe ser menor que el segundo.\n");
		} else {
			for(num2; num2>=num1; num2--){
				cal_par = num2 % 2 ;
				if(cal_par = 0){
					cadena += num2;
				}
			}
			printf("Los numeros pares (de mayor a menor) entre los números introducidos son: %c\n", cadena);
			return 0;
		}
	} while(num1>=num2);
}
