#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

int minimoFilas(int *pPara, int *cNumPara, int filPara, int ColPara);
void iniMatriz(int *pPara, int filPara, int colPara);
int main(){
	int *p, *c;
	int fil, col, i, j;
	i = 0;
	j = 0;
	//srand(time(NULL));
	srand(5);
	printf("Introduzca el numero de filas:");
	scanf("%d", &fil);
	printf("Introduzca el numero de columnas:");
	scanf("%d", &col);
	p = (int *)malloc(fil*col*sizeof(int));
	c = (int *)malloc(fil*sizeof(int));
	iniMatriz(p, fil, col);
	minimoFilas(p, c, fil, col);
	for(i; i<fil; i++){
		for(j; j<col; j++){
			printf("%d  ", *(p+i*col+j));
		}
		j = 0;
		printf("\n");
	}
	i = 0;
	for(i; i<fil; i++){
		printf("El minimo de la fila %d es: %d\n", i+1, *(c+i));
	}
	return 0;	
}

int minimoFilas(int *pPara, int *cNumPara, int filPara, int colPara){
	int i, j, minimo;
	i = 0;
	j = 0;
	for(i; i < filPara; i++){
		minimo=10;		
		for(j; j < colPara; j++){
			if(*(pPara+i*colPara+j) < minimo){
				minimo = *(pPara+i*colPara+j);
				
			}
		}
		j = 0;	
		*(cNumPara+i) = minimo;
	}
	return minimo;
}

void iniMatriz(int *pPara, int filPara, int colPara){
	int i, j;
	i = 0;
	j = 0;
	for(i; i < filPara; i++){
		for(j; j < colPara; j++){
			*(pPara+i*colPara+j) = (rand() % 20) - 10;
		}
		j = 0;	
	}
	return;
}
