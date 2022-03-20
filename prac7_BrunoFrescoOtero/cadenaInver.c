#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void invierte(char *cadenaOrigen, char *cadenaDestino);
int main(){
	char cadena[100], invertida[100];
	printf("Introduzca una cadena: ");
	fgets(cadena, 100, stdin);
	invierte(cadena, invertida);
	printf("Cadena invertida: %s\n", invertida);
	return 0;
}

void invierte(char *cadenaOrigen, char *cadenaDestino){
	int i = 0, len;
	len = strlen(cadenaOrigen);
	i = 0;
	for(i; cadenaOrigen[i] != '\0'; i++){
		len--;
		cadenaDestino[i] = cadenaOrigen[len];
		if(len < 0){
			cadenaDestino[i] = '\0';
		}
	}	
	return;
}
