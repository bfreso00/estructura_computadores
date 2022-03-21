#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quitaespacios(char *cadena, char *cadenasin);
int main(){
	char *chain, *chainOut;
	char c;
	int maxLen, i;
	i = 0;
	printf("Introduzca la longitud maxima de las cadenas:");
	scanf("%d", &maxLen);
	chain = (char*)malloc(sizeof(char)*maxLen);
	chainOut = (char*)malloc(sizeof(char)*maxLen); 
	printf("Escriba una cadena: ");
	scanf("%c", &c);
	scanf("%[^\n]", chain);
	printf("%s\n", chain);
	quitaespacios(chain, chainOut);
	printf("Cadena sin espacios:\n");
	for(i; chainOut[i] != '\0'; i++){
		printf("%c", chainOut[i]);
	}
	printf("\n");
	free(chain);
	free(chainOut);
	return 0;
}

void quitaespacios(char *cadena, char *cadenasin){
	int i = 0, j = 0;
	for(j; j < strlen(cadena); j++){
		for(i; cadena[i] != '\0'; i++){
			if(cadena[i] != ' '){
				cadenasin[j] = cadena[i];
				j++;
			}
		}
	}
	return;
}
