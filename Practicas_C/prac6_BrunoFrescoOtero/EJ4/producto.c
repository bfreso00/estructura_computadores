#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

void ini_Matriz(int *pPara, int filPara, int colPara);
void producto(int *p1Para, int *p2Para, int *pResultado, int filPara, int colPara);
void mostrar_Matriz(int *pPara, int filPara, int colPara);
int main(){
	int *p1, *p2, *pResult, n;
	//srand(time(NULL));
	srand(5);
	printf("Introduzca el numero de filas y columnas de las matrices:");
	scanf("%d", &n);
	p1 = (int *)malloc(n*n*sizeof(int));
	p2 = (int *)malloc(n*n*sizeof(int));
	pResult = (int *)malloc(n*n*sizeof(int));
	ini_Matriz(p1, n, n);
	ini_Matriz(p2, n, n);
	producto(p1, p2, pResult, n, n);
	printf("Matriz 1:\n");
	mostrar_Matriz(p1, n, n);
	printf("Matriz 2:\n");
	mostrar_Matriz(p2, n, n);
	printf("Matriz resultado del producto:\n");
	mostrar_Matriz(pResult, n, n);
	free(p1);
	free(p2);
	free(pResult);
	return 0;
}

void ini_Matriz(int *pPara, int filPara, int colPara){
	int i, j;
	j = 0;
	i = 0;
	for(i; i<filPara; i++) {
		for(j; j<colPara; j++){
			*(pPara+i*colPara+j) = (rand() % 10) + 1;
		}
		j = 0;
	}
	return;
}
void mostrar_Matriz(int *pPara, int filPara, int colPara){
	int i, j;
	i = 0;
	j = 0;
	for(i; i<filPara; i++){
		for(j; j<colPara; j++){
			printf("%d  ", *(pPara+i*colPara+j));
		}
		printf("\n");
		j = 0;
	}
	return;
}
void producto(int *p1Para, int *p2Para, int *pResultado, int filPara, int colPara){
	int i, j, k, suma;
	suma = 0;
	i = 0;
	j = 0;
	k = 0;
	for(i; i<colPara; i++){
		for(j; j<filPara; j++){
			suma = 0;
			for(k; k<colPara; k++){
				suma += *(p1Para+j*colPara+k) * (*(p2Para+k*colPara+i));
			}
			k = 0;
			*(pResultado+j*colPara+i) = suma;
		}
		j = 0;
	}
	return;
}
