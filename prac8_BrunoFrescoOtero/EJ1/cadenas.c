#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[]){
	char anadida[100];
	int lenIntro, pos;
	if(argc >= 3){
		lenIntro = strlen(argv[2]);
		printf("Longitud de la cadena introducida: %d\n", lenIntro);
		printf("Introduzca una cadena:");
		fgets(anadida, 100, stdin);
		strcat(argv[2], anadida);
		printf("La cadena concatenada es: %s", argv[2]);
		if(strstr(argv[2], anadida)){
			printf("La cadena indicada esta incluida en la cadena primaria.\n");
			printf("%s", anadida);
		} else {
			printf("La cadena indicada no esta incluida en la cadena primaria.\n");
		}
		pos = atoi(argv[1]);
		printf("El caracter en la posicion indicada es: %c\n", argv[2][pos-1]);
	} else {
		printf("Debe introducir 3 argumentos como minimo para el funcionamiento del programa.\n");
	}
	return 0;
}
