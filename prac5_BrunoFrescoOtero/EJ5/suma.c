#include <stdio.h>
#include <stdlib.h>
//#include <time.h> => libreria para generar la seed aleatoria

void ini_Matriz(int matriz_Para[6][6]);
int suma(int matriz_Para[6][6]);
int main(){
	int matriz[6][6], result, i, j;
	i = 0;
	j = 0;
	srand(5);
	//srand(time(NULL)); => instanciacion de la seed aleatoria
	ini_Matriz(matriz);
	result = suma(matriz);
	for(i; i<6; i++){
		for(j; j<6; j++){
			printf("%d  ", matriz[i][j]);
		}
		j = 0;
		printf("\n");
	}
	printf("El valor de la suma de todas las posiciones es: %d\n", result);
	return 0;
}

void ini_Matriz(int matriz_Para[6][6]){
	int num_Ran, i, j;
	j = 0;
	i = 0;
	for(i; i<6; i++) {
		for(j; j<6; j++){
			matriz_Para[i][j] = (rand() % 10) + 1;
		}
		j = 0;
	}
	return;
}

int suma(int matriz_Para[6][6]){
	int resultado, i, j;
	j = 0;
	i = 0;
	resultado = 0;
	for(i; i<6; i++){
		for(j; j<6; j++){
			resultado = resultado + matriz_Para[i][j];
		}
		j = 0;
	}
	return resultado;
}
