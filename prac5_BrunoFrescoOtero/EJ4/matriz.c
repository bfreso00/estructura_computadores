#include <stdio.h>
#include <stdlib.h>
//#include <time.h> => libreria para generar la seed aleatoria

void ini_Matriz(int matriz_Para[5][5]);
int main(){
	int i,j,matriz[5][5];
	i = 0;
	j = 0;
	srand(5);
	//srand(time(NULL)); => instanciación de la seed aleatoria
	ini_Matriz(matriz);
	for(i; i<5; i++){
		for(j; j<5; j++){
			printf("%d  ", matriz[i][j]);
		}
		j = 0;
		printf("\n");
	}
	return 0;
}

void ini_Matriz(int matriz_Para[5][5]){
	int i, j;
	i = 0;
	j = 0;
	for(i; i<5; i++){
		for(j; j<5; j++){
			matriz_Para[i][j] = (rand()%13) + 3;
		}
		j = 0;
	}
}
