#include <stdio.h>
#include <stdlib.h>
//#include <time.h> => libreria para generar la seed aleatoria

void ini_Matriz(int matriz_Para[3][3]);
void producto(int matriz_Para1[3][3], int matriz_Para2[3][3], int matriz_Resultado[3][3]);
void mostrar_Matriz(int matriz_Para[3][3]);
int main(){
	int matriz1[3][3], matriz2[3][3], matriz_Result[3][3];
	srand(5);
	//srand(time(NULL)); => instanciacion de la seed aleatoria
	ini_Matriz(matriz1);
	ini_Matriz(matriz2);
	producto(matriz1, matriz2, matriz_Result);
	printf("Matriz 1:\n");
	mostrar_Matriz(matriz1);
	printf("Matriz 2:\n");
	mostrar_Matriz(matriz2);
	printf("Matriz resultado del producto:\n");
	mostrar_Matriz(matriz_Result);
	return 0;
}

void ini_Matriz(int matriz_Para[3][3]){
	int num_Ran, i, j;
	j = 0;
	i = 0;
	for(i; i<3; i++) {
		for(j; j<3; j++){
			matriz_Para[i][j] = (rand() % 5) + 1;
		}
		j = 0;
	}
	return;
}
void mostrar_Matriz(int matriz_Para[3][3]){
	int i, j;
	i = 0;
	j = 0;
	for(i; i<3; i++){
		for(j; j<3; j++){
			printf("%d  ", matriz_Para[i][j]);
		}
		printf("\n");
		j = 0;
	}
	return;
}
void producto(int matriz_Para1[3][3], int matriz_Para2[3][3], int matriz_Resultado[3][3]){
	//FILA 1 COLUMNA 1
	matriz_Resultado[0][0] = (matriz_Para1[0][0] * matriz_Para2[0][0]) + (matriz_Para1[0][1] * matriz_Para2[1][0]) + 					+ (matriz_Para1[0][2] * matriz_Para2[2][0]);
	//FILA 1 COLUMNA 2
	matriz_Resultado[0][1] = (matriz_Para1[0][0] * matriz_Para2[0][1]) + (matriz_Para1[0][1] * matriz_Para2[1][1]) + 					+ (matriz_Para1[0][2] * matriz_Para2[2][1]);
	//FILA 1 COLUMNA 3
	matriz_Resultado[0][2] = (matriz_Para1[0][0] * matriz_Para2[0][2]) + (matriz_Para1[0][1] * matriz_Para2[1][2]) + 					+ (matriz_Para1[0][2] * matriz_Para2[2][2]);
	//FILA 2 COLUMNA 1
	matriz_Resultado[1][0] = (matriz_Para1[1][0] * matriz_Para2[0][0]) + (matriz_Para1[1][1] * matriz_Para2[1][0]) + 					+ (matriz_Para1[1][2] * matriz_Para2[2][0]);
	//FILA 2 COLUMNA 2
	matriz_Resultado[1][1] = (matriz_Para1[1][0] * matriz_Para2[0][1]) + (matriz_Para1[1][1] * matriz_Para2[1][1]) + 					+ (matriz_Para1[1][2] * matriz_Para2[2][1]);
	//FILA 2 COLUMNA 3
	matriz_Resultado[1][2] = (matriz_Para1[1][0] * matriz_Para2[0][2]) + (matriz_Para1[1][1] * matriz_Para2[1][2]) + 					+ (matriz_Para1[1][2] * matriz_Para2[2][2]);
	//FILA 3 COLUMNA 1
	matriz_Resultado[2][0] = (matriz_Para1[2][0] * matriz_Para2[0][0]) + (matriz_Para1[2][1] * matriz_Para2[1][0]) + 					+ (matriz_Para1[2][2] * matriz_Para2[2][0]);
	//FILA 3 COLUMNA 2
	matriz_Resultado[2][1] = (matriz_Para1[2][0] * matriz_Para2[0][1]) + (matriz_Para1[2][1] * matriz_Para2[1][1]) + 					+ (matriz_Para1[2][2] * matriz_Para2[2][1]);
	//FILA 3 COLUMNA 3
	matriz_Resultado[2][2] = (matriz_Para1[2][0] * matriz_Para2[0][2]) + (matriz_Para1[2][1] * matriz_Para2[1][2]) + 					+ (matriz_Para1[2][2] * matriz_Para2[2][2]);
	return;
}
