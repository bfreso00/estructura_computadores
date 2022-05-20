#include <stdio.h>

void ini_Matriz(int matriz_Para[9][9]);
int main(){
	int i,j,matriz[9][9];
	i = 0;
	j = 0;
	ini_Matriz(matriz);
	for(i; i<9; i++){
		for(j; j<9; j++){
			printf("%d  ", matriz[i][j]);
		}
		j = 0;
		printf("\n");
	}
	return 0;
}

void ini_Matriz(int matriz_Para[9][9]){
	int i, j;
	i = 0;
	j = 0;
	for(i; i<9; i++){
		for(j; j<9; j++){
			if(i == j){
				matriz_Para[i][j] = 1;
			} else {
				matriz_Para[i][j] = 0;
			}
		}
		j = 0;
	}
}
