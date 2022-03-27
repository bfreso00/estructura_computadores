#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Punto{
	int c1;
	int c2;
	int c3;
};
struct Triangulo{
	struct Punto *puntos;
	double perimetro;
	double area;
};

void leeTriangulos(FILE *pFile, struct Punto *p, struct Triangulo *t);
double calcPerimetro(double l1, double l2, double l3);
double calcArea(double l1, double l2, double l3, double semiPer);
int maxPer(struct Triangulo *t);
int maxArea(struct Triangulo *t);
int main(int argc, char *argv[]) {
	FILE *p;
	int i, perMax, areaMax;
	double lado1, lado2, lado3, semiPerimetro;
	struct Punto *punt;
	struct Triangulo *trian;
	punt = (struct Punto *)malloc(sizeof(struct Punto)*3);
	trian = (struct Triangulo *)malloc(sizeof(struct Triangulo)*3);
	if(argc == 2){
		leeTriangulos(p, punt, trian);
		for(i=0; i<3; i++){
			lado1 = sqrt(pow((trian+i)->((p+1)->c1) - (trian+i)->((p+0)->c1), 2) + pow((trian+i)->((p+1)->c2) - (trian+i)->((p+0)->c2), 2) + pow((trian+i)->((p+1)->c3) - (trian+i)->((p+0)->c3), 2));
			lado2 = sqrt(pow((trian+i)->((p+2)->c1) - (trian+i)->((p+1)->c1), 2) + pow((trian+i)->((p+2)->c2) - (trian+i)->((p+1)->c2), 2) + pow((trian+i)->((p+2)->c3) - (trian+i)->((p+1)->c3), 2));
			lado3 = sqrt(pow((trian+i)->((p+0)->c1) - (trian+i)->((p+2)->c1), 2) + pow((trian+i)->((p+0)->c2) - (trian+i)->((p+2)->c2), 2) + pow((trian+i)->((p+0)->c3) - (trian+i)->((p+2)->c3), 2));
			(trian+i)->perimetro = calcPerimetro(lado1, lado2, lado3);
			semiPerimetro = ((trian+i)->perimetro)/2;
			(trian+i)->area = calcArea(lado1, lado2, lado3, semiPerimetro);
		}
		perMax = maxPer(trian);
		printf("El triangulo con mas perimetro es el numero %d.\n", perMax+1);
		printf("Puntos:\n");
		for(i=0; i<3; i++){
			printf("Punto %d: (%d,%d,%d)\n", i+1, (trian+perMax)->((p+i)->c1), (trian+perMax)->((p+i)->c2), (trian+perMax)->((p+i)->c3));
		}
		printf("Perimetro: %f", (trian+perMax)->perimetro);
		printf("Area: %f", (trian+perMax)->area);
		areaMax = maxArea(trian);
		printf("El triangulo con mas area es el numero %d.\n", areaMax+1);
		printf("Puntos:\n");
		for(i=0; i<3; i++){
			printf("Punto %d: (%d,%d,%d)\n", i+1, (trian+areaMax)->((p+i)->c1), (trian+areaMax)->((p+i)->c2), (trian+areaMax)->((p+i)->c3));
		}
		printf("Perimetro: %f", (trian+areaMax)->perimetro);
		printf("Area: %f", (trian+areaMax)->area);
	} else {
		printf("Debe introducir 2 argumentos para el funcionamiento del programa.\n");
	}
	return 0;
}

void leeTriangulo(FILE *pFile, struct Punto *p, struct Triangulo *t){
	int i;
	pFile = fopen("coordenadas.txt", "r");
	if(pFile == NULL){
		fprintf(stderr, "Ha ocurrido un error al abrir el archivo");
		exit(EXIT_FAILURE);
	} else {
		do{
			if(!feof(pFile)){
				fscanf(pFile,"%d %d %d;%d %d %d;%d %d %d", &(p+0)->c1, &(p+0)->c2, &(p+0)->c3, 
									    &(p+1)->c1, &(p+1)->c2, &(p+1)->c3, 
									    &(p+2)->c1, &(p+2)->c2, &(p+2)->c3);
				((t+i)->(puntos+0)) = (p+0);
				((t+i)->(puntos+1)) = (p+1);
				((t+i)->(puntos+2)) = (p+2);
				i++;
			} 
		}while(!feof(pFile));	
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
