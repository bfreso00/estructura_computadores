#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Punto{
	int c1;
	int c2;
};

struct Triangulo{
	struct Punto puntos[3];
	double perimetro;
	double area;
};

double calDist(struct Punto *p1, struct Punto *p2);
double calPer(double dist1, double dist2, double dist3);
double calArea(double semiPer, double dist1, double dist2, double dist3);
int main(){
	struct Punto *puntos;
	struct Triangulo trian;
	int i;
	double perimetro, semiperimetro, lado1, lado2, lado3, area;
	puntos = (struct Punto *)malloc(sizeof(struct Punto)*3);
	for(i=0; i<3; i++){
		printf("Punto %d:\n", i+1);
		printf("Coordenada 1:");
		scanf("%d", &(puntos+i)->c1);
		printf("Coordenada 2:");
		scanf("%d", &(puntos+i)->c2);
		trian.puntos[i] = puntos[i];
	}
	lado1 = calDist((puntos+0), (puntos+1));
	lado2 = calDist((puntos+1), (puntos+2));
	lado3 = calDist((puntos+2), (puntos+0));
	perimetro = calPer(lado1, lado2, lado3);
	trian.perimetro = perimetro;
	semiperimetro = perimetro/2;
	area = calArea(semiperimetro, lado1, lado2, lado3);
	trian.area = area;
	printf("Datos del triangulo:\n");
	for(i=0; i<3; i++){
		printf("Punto %d: (%d,%d)\n", i+1, (puntos+i)->c1, (puntos+i)->c2);
	}
	printf("Perimetro: %f\n", trian.perimetro);
	printf("Area: %f\n", trian.area);
	free(puntos);
	return 0;
}

double calDist(struct Punto *p1, struct Punto *p2) {
	double distancia;
	distancia = sqrt(pow((p2+0)->c1 - (p1+0)->c1, 2) + pow((p2+1)->c2 - (p1+1)->c2, 2));
	return distancia;
}

double calPer(double dist1, double dist2, double dist3){
	double per;
	per = dist1 + dist2 + dist3;
	return per;
}

double calArea(double semiPer, double dist1, double dist2, double dist3){
	double area;
	area = sqrt(semiPer*(semiPer-dist1)*(semiPer-dist2)*(semiPer-dist3));
	return area;
}
