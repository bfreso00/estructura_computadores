#include <stdio.h>

int potencia(int base_para, int expo_para);
int main(){
	int base, exponente;
	do{
		printf("Introduzca la base: ");
		scanf("%d", &base);
		printf("Introduzca el exponente: ");
		scanf("%d", &exponente);
		if(base > 0 && exponente > 0) {
			potencia(base, exponente);
			return 0;
		} else {
			printf("Debe introducir valores enteros positivos mayores que 0.");
		}
	} while(base <= 0 || exponente <= 0);
}

int potencia(int base_para, int expo_para){
	int pot, i;
	pot = 1;
	i = 1;
	while(expo_para >= 1){
		pot = pot * base_para;
		expo_para = expo_para - 1;
	}
	printf("La potencia es: %d\n", pot);
}
