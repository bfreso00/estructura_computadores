#include <stdio.h>
#include <stdlib.h>
//#include <time.h> => libreria para generar la seed aleatoria

void ini_Matriz(int matriz_Para[3][6]);
void suma(int matriz_Para[3][6], int vector_Para[6]);
int main(){
	int matriz[3][6], vector[6], result, i, j;
	i = 0;
	j = 0;
	srand(5);
	//srand(time(NULL)); => intanciacion de la seed aleatoria
	ini_Matriz(matriz);
	suma(matriz,vector);
	for(i; i<3; i++){
		for(j; j<6; j++){
			printf("%d  ", matriz[i][j]);
		}
		j = 0;
		printf("\n");
	}
	for(j; j<6; j++){
		printf("La suma de los valores de la columna %d es: %d\n", j+1, vector[j]);
	}
	return 0;
}

void ini_Matriz(int matriz_Para[3][6]){
	int num_Ran, i, j;
	j = 0;
	i = 0;
	for(i; i<3; i++) {
		for(j; j<6; j++){
			matriz_Para[i][j] = (rand() % 10) + 1;
		}
		j = 0;
	}
	return;
}

void suma(int matriz_Para[3][6], int vector_Para[6]){
	int resultado, i, j;
	j = 0;
	i = 0;
	resultado = 0;
	for(j; j<6; j++){
		for(i; i<3; i++){
			resultado = resultado + matriz_Para[i][j];
		}
		vector_Para[j] = resultado;
		resultado = 0;
		i = 0;
	}
	return;
}
