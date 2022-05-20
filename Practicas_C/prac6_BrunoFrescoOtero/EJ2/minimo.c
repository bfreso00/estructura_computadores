#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

int calculaMinimo(int *pPara, int filPara, int colPara);
void iniMatriz(int *pPara, int filPara, int colPara);
int main(){
	int fil,col,min, i, j, *p;
	i = 0;
	j = 0;
	//srand(time(NULL));
	srand(5);
	printf("Introduzca el numero de filas:");
	scanf("%d", &fil);
	printf("Introduzca el numero de columnas:");
	scanf("%d", &col);
	p = (int *)malloc(fil*col*sizeof(int));
	iniMatriz(p, fil, col);
	min = calculaMinimo(p, fil, col);
	for(i; i < fil; i++){
		for(j; j < col; j++){
			printf("%d  ", *(p+i*col+j));
		}
		printf("\n");
		j = 0;
	}
	printf("El minimo de los numeros de la matriz es: %d\n", min);
	free(p);
	return 0;	
}

int calculaMinimo(int *pPara, int filPara, int colPara){
	int i, j, minimo, *min;
	i = 0;
	j = 0;
	min = (int *) malloc (filPara*sizeof(int));
	for(i; i < filPara; i++){
		minimo=10;		
		for(j; j < colPara; j++){
			if(*(pPara+i*colPara+j) < minimo){
				minimo = *(pPara+i*colPara+j);	
			}
		}
		j = 0;	
		*(min+i) = minimo;
	}
	i = 0;
	minimo = 10;
	for(i; i < filPara; i++){
		if(*(min+i) < minimo){
			minimo = *(min+i);
		}
	}
	return minimo;
}

void iniMatriz(int *pPara, int filPara, int colPara){
	int i, j;
	i = 0;
	j = 0;
	for(i; i < filPara; i++){
		for(j; j < colPara; j++){
			*(pPara+i*colPara+j) = (rand() % 10) + 1;
		}
		j = 0;	
	}
	return;
}
