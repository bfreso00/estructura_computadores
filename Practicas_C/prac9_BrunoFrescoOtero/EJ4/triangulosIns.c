#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Punto{
	int c1;
	int c2;
	int c3;
};
struct Triangulo{
	struct Punto puntos[3];
	double perimetro;
	double area;
};

void leeTriangulos(FILE *pFile, struct Triangulo *t);
double calcL1(struct Triangulo *t, int auxL, int ind);
double calcL2(struct Triangulo *t, int auxL, int ind);
double calcPerimetro(double l1, double l2, double l3);
double calcArea(double l1, double l2, double l3, double semiPer);
int maxPer(struct Triangulo *t);
int maxArea(struct Triangulo *t);
int main(int argc, char *argv[]) {
	FILE *p;
	int i, perMax, areaMax, aux;
	double lado1, lado2, lado3, semiPerimetro;
	struct Triangulo *trian;
	trian = (struct Triangulo *)malloc(sizeof(struct Triangulo)*3);
	if(argc == 2){
		leeTriangulos(p, trian);
		for(i=0; i<3; i++){
			aux = 0;
			lado1 = calcL1(trian, aux, i);
			//printf("%f\n", lado1);
			aux++;
			lado2 = calcL1(trian, aux, i);
			//printf("%f\n", lado2);
			aux++;
			lado3 = calcL2(trian, aux, i);
			//printf("%f\n", lado3);
			(trian+i)->perimetro = calcPerimetro(lado1, lado2, lado3);
			semiPerimetro = ((trian+i)->perimetro)/2;
			(trian+i)->area = calcArea(lado1, lado2, lado3, semiPerimetro);
		}
		perMax = maxPer(trian);
		printf("El triangulo con mas perimetro es el numero %d.\n", perMax+1);
		printf("Puntos:\n");
		for(i=0; i<3; i++){
			printf("Punto %d: (%d,%d,%d)\n", i+1, (trian+perMax)->puntos[i].c1, (trian+perMax)->puntos[i].c2, (trian+perMax)->puntos[i].c3);
		}
		printf("Perimetro: %f\n", (trian+perMax)->perimetro);
		printf("Area: %f\n", (trian+perMax)->area);
		areaMax = maxArea(trian);
		printf("El triangulo con mas area es el numero %d.\n", areaMax+1);
		printf("Puntos:\n");
		for(i=0; i<3; i++){
			printf("Punto %d: (%d,%d,%d)\n", i+1, (trian+areaMax)->puntos[i].c1, (trian+areaMax)->puntos[i].c2, (trian+areaMax)->puntos[i].c3);
		}
		printf("Perimetro: %f\n", (trian+areaMax)->perimetro);
		printf("Area: %f\n", (trian+areaMax)->area);
		free(trian);
	} else {
		printf("Debe introducir 2 argumentos para el funcionamiento del programa.\n");
	}
	return 0;
}

void leeTriangulos(FILE *pFile, struct Triangulo *t){
	int i,j;
	pFile = fopen("coordenadas.txt", "r");
	if(pFile == NULL){
		fprintf(stderr, "Ha ocurrido un error al abrir el archivo");
		exit(EXIT_FAILURE);
	} else {
		if(!feof(pFile)){
			for(i=0; i<3; i++){
				fscanf(pFile,"%d %d %d;%d %d %d;%d %d %d", &(t+i)->puntos[0].c1, &(t+i)->puntos[0].c2, &(t+i)->puntos[0].c3,
									   &(t+i)->puntos[1].c1, &(t+i)->puntos[1].c2, &(t+i)->puntos[1].c3,
									   &(t+i)->puntos[2].c1, &(t+i)->puntos[2].c2, &(t+i)->puntos[2].c3);	
			}
		} 	
	}
	fclose(pFile);
	return;
}

double calcPerimetro(double l1, double l2, double l3) {
	double per;
	per = l1 + l2 + l3;
	return per;
}

double calcArea(double l1, double l2, double l3, double semiPer) {
	double area;
	area = sqrt(semiPer * (semiPer - l1) * (semiPer - l2) * (semiPer - l3));
	return area; 
}

int maxPer(struct Triangulo *t){
	int i, max, maxPer;
	maxPer = 0;
	for(i=0; i<3; i++){
		if((t+i)->perimetro > maxPer){
			maxPer = (t+i)->perimetro;
			max = i;
		}
	}
	return max;
}

int maxArea(struct Triangulo *t){
	int i, max, maxArea;
	maxArea = 0;
	for(i=0; i<3; i++){
		if((t+i)->area > maxArea){
			maxArea = (t+i)->area;
			max = i;
		}
	}
	return max;
}

double calcL1(struct Triangulo *t, int auxL, int ind) {
	double lado;
	lado = sqrt(pow((t+ind)->puntos[auxL+1].c1 - (t+ind)->puntos[auxL].c1, 2) + pow((t+ind)->puntos[auxL+1].c2 - (t+ind)->puntos[auxL].c2, 2) + pow((t+ind)->puntos[auxL+1].c3 - (t+ind)->puntos[auxL].c3, 2));
	return lado;
}

double calcL2(struct Triangulo *t, int auxL, int ind) {
	double lado;
	lado = sqrt(pow((t+ind)->puntos[auxL-2].c1 - (t+ind)->puntos[auxL].c1, 2) + pow((t+ind)->puntos[auxL-2].c2 - (t+ind)->puntos[auxL].c2, 2) + pow((t+ind)->puntos[auxL-2].c3 - (t+ind)->puntos[auxL].c3, 2));
	return lado;
}
