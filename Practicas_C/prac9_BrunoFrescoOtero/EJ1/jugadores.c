#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 50

struct Tjugador{
	char nombreJug[MAX_CHAR];
	int edad;
	float altura;
};

int jugadormasalto(struct Tjugador *info, int tam);
int jugadormasviejo(struct Tjugador *info, int tam);
int main(){
	struct Tjugador *jugadores;
	int num, i, jugAlt, jugOld;
	char c;
	printf("Indique el numero de jugadores que va a introducir:");
	scanf("%d", &num);
	jugadores = (struct Tjugador *)malloc(sizeof(struct Tjugador)*num);
	for(i=0; i<num; i++){
		printf("\nNombre del jugador %d:", (i+1));
		scanf("%c", &c);
		scanf("%[^\n]", (jugadores+i)->nombreJug);
		printf("\nEdad del jugador %d:", (i+1));
		scanf("%d", &(jugadores+i)->edad);
		printf("\nAltura del jugador %d:", (i+1));
		scanf("%f", &(jugadores+i)->altura);
	}
	jugAlt = jugadormasalto(jugadores, num);
	printf("El jugador %d es el mas alto del equipo.\n", jugAlt+1);
	printf("%s\n", (jugadores+jugAlt)->nombreJug);
	printf("%d\n", (jugadores+jugAlt)->edad);
	printf("%f\n", (jugadores+jugAlt)->altura);
	jugOld = jugadormasviejo(jugadores, num);
	printf("El jugador %d es el mas viejo del equipo.\n", jugOld+1);
	printf("%s\n", (jugadores+jugOld)->nombreJug);
	printf("%d\n", (jugadores+jugOld)->edad);
	printf("%f\n", (jugadores+jugOld)->altura);
	free(jugadores);
	return 0;
}

int jugadormasalto(struct Tjugador *info, int tam){
	int i, masAlto, alturaAlto;
	alturaAlto = 0;
	for(i=0; i<tam; i++){
		if((info+i)->altura > alturaAlto){
			alturaAlto = (info+i)->altura;
			masAlto = i;
		}
	}
	return masAlto;
}

int jugadormasviejo(struct Tjugador *info, int tam){
	int i, masViejo, edadViejo;
	edadViejo = 0;
	for(i=0; i<tam; i++){
		if((info+i)->edad > edadViejo){
			edadViejo = (info+i)->edad;
			masViejo = i;
		}
	}
	return masViejo;
}
