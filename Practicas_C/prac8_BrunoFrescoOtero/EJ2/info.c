#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE
#define MAX_CHAR 100
#define MAX_LINEAS 5

void matrizRes(FILE *pFile, char matrizP[MAX_LINEAS][MAX_CHAR]);
void impLetra(char matrizP[MAX_LINEAS][MAX_CHAR], char cP);
void impAll(char matrizP[MAX_LINEAS][MAX_CHAR]);
int main(){
	FILE *p;
	char matriz[MAX_LINEAS][MAX_CHAR];
	char c;
	matrizRes(p, matriz);
	printf("Introduzca una letra para filtrar los nombres:");
	scanf("%c", &c);
	printf("Alumnos que empiezan por la letra indicada:\n");
	impLetra(matriz, c);
	printf("Lista de todos los alumnos:\n");
	impAll(matriz);
	return 0;
}

void matrizRes(FILE *pFile, char matrizP[MAX_LINEAS][MAX_CHAR]){
	char *linea = NULL;
	size_t tam = 0;
	ssize_t bytesleidos;
	int i = 0;
	pFile = fopen("info.txt", "r");
	if(pFile == NULL){
		fprintf(stderr, "Ha ocurrido un error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
	do{
		bytesleidos = getline(&linea, &tam, pFile);
		if(bytesleidos != -1){
			strncpy(matrizP[i], linea, bytesleidos - 1);
			matrizP[i][bytesleidos - 1] = '\0';
			i++;
		}
	}while(bytesleidos != -1);
	free(linea);
	fclose(pFile);
	return;
}

void impLetra(char matrizP[MAX_LINEAS][MAX_CHAR], char cP) {
	int i = 0;
	int j = 0;
	for(i; i < MAX_LINEAS; i++){
		if(matrizP[i][0] == cP){
			for(j; j < strlen(matrizP[i]); j++){
				printf("%c", matrizP[i][j]);
			}
		printf("\n");
		j = 0;
		}
	}
	return;
}

void impAll(char matrizP[MAX_LINEAS][MAX_CHAR]) {
	int i = 0;
	int j = 0;
	for(i; i < MAX_LINEAS; i++) {
		for(j; j < strlen(matrizP[i]); j++) {
			printf("%c", matrizP[i][j]);
		}
		printf("\n");
		j = 0;
	}
	return;
}
