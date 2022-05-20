#include <stdio.h>
#include <stdlib.h>

int calculaMaximo(int *pPara, int tam);
int main(){
	int tam, i, *p;
	i = 0;
	printf("Introduce cuantos numeros se van a analizar:");
	scanf("%d", &tam);
	p = (int *)malloc(tam*sizeof(int));
	for(i; i<tam; i++){
		printf("Introduzca un numero: ");
		scanf("%d", &*(p+i));
	}
	int max = calculaMaximo(p,tam);
	printf("El maximo de los numeros introducidos es: %d\n", max);
	free(p);
	return 0;	
}

int calculaMaximo(int *pPara, int tam){
	int i, max;
	i = 0;
	for(i; i < tam; i++){
		if(*(pPara+i) > *(pPara+(i+1))){
			max = *(pPara+i);
		}	
	}
	return max;	
}
