#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE
#define MAX_CHAR 50
#define MAX_LINEAS 4

struct Alumno{
	char nombre[MAX_CHAR];
	char apellidos[MAX_CHAR];
	float notas[2];
};

void matrizAlumnos(FILE *pFile, char matrizP[MAX_LINEAS][MAX_CHAR]);
void iniAlumnos(struct Alumno *alumnos, char matrizP[MAX_LINEAS][MAX_CHAR], char notasChar[2][3]);
int mediaAlta(struct Alumno *alumnos);
int main(int argc, char *argv[]) {
	char notasC[2][3], matriz[MAX_LINEAS][MAX_CHAR];
	int mediaMasAlta; 
	int i,j;
	FILE *p;
	struct Alumno *alum;
	alum = (struct Alumno *)malloc(sizeof(struct Alumno)*MAX_LINEAS);
	if(argc == 2){
		matrizAlumnos(p, matriz);
		iniAlumnos(alum, matriz, notasC);
		for(i=0; i<4; i++){
			for(j=0; j<2; j++){
				(alum+i)->notas[j] = atof(notasC[j]);
			}
			j = 0;
		}
		mediaMasAlta = mediaAlta(alum);
		printf("El alumno con mas media es el alumno %d.\n", mediaMasAlta+1);
		printf("%s\n", (alum+mediaMasAlta)->nombre);
		printf("%s\n", (alum+mediaMasAlta)->apellidos);
		printf("Primera nota: %f\n", (alum+mediaMasAlta)->notas[0]);
		printf("Segunda nota: %f\n", (alum+mediaMasAlta)->notas[1]);
		free(alum);
	} else {
		printf("Debe introducir 2 argumentos para el funcionamiento del programa.\n");
	}
	return 0;
}

void matrizAlumnos(FILE *pFile, char matrizP[MAX_LINEAS][MAX_CHAR]){
	char *linea = NULL;
	size_t tam = 0;
	ssize_t bytesleidos;
	int i = 0;
	pFile = fopen("alumnos.txt", "r");
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

void iniAlumnos(struct Alumno *alumnos, char matrizP[MAX_LINEAS][MAX_CHAR], char notasChar[2][3]){
	int i,j,z,y;
	char c;
	z = 0;
	j = 0;
	for(i=0; i<MAX_LINEAS; i++){
		do{
			(alumnos+i)->nombre[z] = matrizP[i][j];
			z++;
			j++;
		}while(matrizP[i][j] != ' ');
		j++;
		z = 0;
		do{
			(alumnos+i)->apellidos[z] = matrizP[i][j];
			z++;
			j++;
		}while(matrizP[i][j] != ' ');
		j++;
		(alumnos+i)-> apellidos[z] = ' ';
		z++;
		do{
			(alumnos+i)->apellidos[z] = matrizP[i][j];
			z++;
			j++;
		}while(matrizP[i][j] != ' ');
		j++;
		z = 0;
		for(z; z<2; z++){
			for(y=0; y<3; y++){
				notasChar[z][y] = matrizP[i][j];
				j++;
			}
			y = 0;
			j++;
		}
		j = 0;
		z = 0;
	}
}

int mediaAlta(struct Alumno *alumnos){
	int i, maxAlumno;
	float media, mediaMax;
	mediaMax = 0;
	for(i=0; i<4; i++){
		media = ((alumnos+i)->notas[0] + (alumnos+i)->notas[1])/2;
		if(media>mediaMax){
			mediaMax = media;
			maxAlumno = i;
		}
	}
	return maxAlumno;
}
