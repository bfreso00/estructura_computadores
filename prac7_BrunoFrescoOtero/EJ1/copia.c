#include <stdio.h>
#include <string.h>

int main(){
	char cadena[100], compara[100], anadida[100];
	int len, comp;
	printf("Introduzca una cadena: ");
	fgets(cadena, 100, stdin);
	len = strlen(cadena);
	printf("La longitud de la cadena es: %d\n", len);
	printf("Escriba otra cadena: ");
	fgets(compara, 100, stdin);
	comp = strcmp(cadena, compara);
	if(comp != 0){
		printf("Las dos cadenas no son iguales.\n");
	} else {
		printf("Las dos cadenas son iguales.\n");
	}
	printf("Escriba otra cadena: ");
	fgets(anadida, 100, stdin);
	strcat(cadena, anadida);
	printf("Cadena resultante: %s", cadena);
	return 0;
}
