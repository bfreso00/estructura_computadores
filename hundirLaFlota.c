#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _GNU_SOURCE

struct coordenadas{
	int c1;
	int c2;
};

struct barco1{
	struct coordenadas coor;
};

struct barco2{
	struct coordenadas coor[2];
};

struct barco3{
	struct coordenadas coor[3];
};

void config(struct barco1 *b1, struct barco2 *b2, struct barco3 *b3, int *matriz1, int *matriz2, int *matriz3, int *matriz4);
int main(){
	int opc = 1;
	struct barco1 *s1;
	struct barco2 *s2;
	struct barco3 *s3;
	int *matrizJug, *matrizMaq, *matrizXJug, *matrizXMaq;
	while(opc != 4){
		printf("///////////////////HUNDIR LA FLOTA//////////////////\n");
		printf("Seleccione una de las opciones disponibles:\n");
		printf("1.Configuración de los tableros y los barcos.\n");
		printf("2.Jugar (Jugador vs Máquina).\n");
		printf("3.Jugar (Máquina vs Máquina).\n");
		printf("4.Salir.\n");
		printf("Que desea hacer: ");
		scanf("%d", &opc);
		switch(opc){
			case 1: printf("Configuración tablero y barcos.\n");
				config(s1, s2, s3, s4, matrizJug, matrizMaq, matrizXJug, matrizXMaq);
				break;
			case 2: printf("Juego Jugador vs Máquina.\n");
				break;
			case 3: printf("Juego Máquina vs Máquina.\n");
				break;
			case 4: printf("Gracias por jugar.\n");
				 break;
			default: printf("Debe seleccionar una opción válida.\n");
				 break;
		}	
	}
	return 0;	
}
void config(struct barco1 *b1, struct barco2 *b2, struct barco3 *b3, struct barco4 *b4, int *matriz1, int *matriz2, int *matriz3, int *matriz4){
	int numb1, numb2, numb3, opcCon, n, m, numShips, pos1, pos2, pos3, stanPos1, stanPos2, stanPos3, i;
	FILE *p;
	char c;
	char *nombreFile;
	while(opcCon != 3){
		printf("1.Utilizar configuración existente.\n");
		printf("2.Hacer nueva configuraciónd de tablero y barcos.\n");
		printf("3.Volver al menú de inicio.\n");
		printf("¿Que desea hacer?\n");
		scanf("%d", &opcCon);
		switch(opcCon){
			case 1:  printf("Indique el nombre del archivo de configuración que desea utilizar: ");
				 scanf("%c", &c);
				 scanf("%[^\n]", nombreFile);
				 p = fopen(nombreFile, "r");
				 if(p == NULL){
				 	fprintf(stderr, "El archivo esta vacío/no se ha encontrado el archivo.\n");
				 	return;
				 } else {
				 	if(!feof(p)){
				 		fscanf(p,"%d", &n);
				 		fscanf(p,"%d", &m);
				 		fscanf(p,"%d", &numShips);
				 		fscanf(p,"%d %d %d", &stanPos1, &numb1, &pos1);
				 		b1 = (struct barco1 *)malloc(sizeof(struct barco1)*numb1);
				 		for(i=0; i<numb1; i++){
				 			fscanf(p,"(%d,%d)", &(b1+i)->coor.c1, &(b1+i)->coor.c2);
				 		}
				 		fscanf(p,"%d %d %d", &stanPos2, &numb2, &pos2);
				 		b2 = (struct barco2 *)malloc(sizeof(struct barco2)*numb2);
				 		for(i=0; i<numb2; i++){
				 			fscanf(p,"(%d,%d) (%d,%d)", &(b2+i)->coor[0].c1, &(b2+i)->coor[0].c2, &(b2+i)->coor[1].c1, &(b2+i)->coor[1].c2);
				 		}
				 		fscanf(p,"%d %d %d", &stanPos3, &numb3, &pos3);
				 		b3 = (struct barco3 *)malloc(sizeof(struct barco3)*numb3);
				 		for(i=0; i<numb3; i++){
				 			fscanf(p,"(%d,%d) (%d,%d) (%d,%d)", &(b3+i)->coor[0].c1, &(b3+i)->coor[0].c2, &(b3+i)->coor[1].c1, &(b3+i)->coor[1].c2, &(b3+i)->coor[2].c1, &(b3+i)->coor[2].c2);
				 		}
				 		fscanf(p,"%d %d %d", &stanPos4, &numb4, &pos4);
				 	}
				 	matriz1 = (int *)malloc(n*m*sizeof(int));
				 	matriz2 = (int *)malloc(n*m*sizeof(int));
				 	matriz3 = (int *)malloc(n*m*sizeof(int));
				 	matriz4 = (int *)malloc(n*m*sizeof(int));
				 }
				 fclose(p);
				 printf("Configuración cargada con exito.\n");
				 printf("Número de filas: %d\n", n);
				 printf("Número de columnas: %d\n", m);
				 printf("Total de barcos: %d\n", numShips);
				 printf("Número de barcos de 1 posición: %d\n", numb1);
				 printf("Número de barcos de 2 posiciones: %d\n", numb2);
				 printf("Número de barcos de 3 posiciones: %d\n", numb3);
				 printf("Barcos de 1 posición.\n");
				 for(i = 0; i<numb1; i++){
					printf("Coordenada barco %d: (%d,%d)\n", i+1, (b1+i)->coor.c1, (b1+i)->coor.c2);
				 }
				 printf("Barcos de 2 posiciones.\n");
				 for(i = 0; i<numb2; i++){
					printf("Coordenadas barco %d: (%d,%d) (%d,%d)\n", i+1, (b2+i)->coor[0].c1, (b2+i)->coor[0].c2, (b2+i)->coor[1].c1, (b2+i)->coor[1].c2);
				 }
				 printf("Barcos de 3 posiciones.\n");
				 for(i = 0; i<numb3; i++){
					printf("Coordenadas barco %d: (%d,%d) (%d,%d) (%d,%d)\n", i+1, (b3+i)->coor[0].c1, (b3+i)->coor[0].c2, (b3+i)->coor[1].c1, (b3+i)->coor[1].c2, (b3+i)->coor[2].c1, (b3+i)->coor[2].c2);
				 }
				 break;
			case 2: printf("Archivo nuevo de configuración.\n");
				 break;
			case 3: printf("Volviendo al menú de inicio...\n");
				 break;
			default: printf("Debe escoger una de las opciones disponibles.\n");
				 break;	 
			}	
		}
	}
	return;
}


