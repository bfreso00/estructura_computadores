#include <stdio.h>

int suma_num(int num_par);
int main(){
	int num;
	do{
		printf("Introduzca los números a sumar: ");
		scanf("%d", &num);
		if(num > 0){
			suma_num(num);
			return 0;
		} else {
			printf("Debe introducir valores enteros positivos.");
		}
	} while(num <= 0);
}

int suma_num(int num_par){
	int total, i;
	total = 0;
	i = 1;
	while(i <= num_par) {
		total = total + i;
		i = i + 1;
	}
	printf("La suma es: %d\n", total);
	return total;
}
