#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quitaespacios(char *cadena, char *cadenasin);
int main(){
	char *chain, *chainOut;
	char var;
	int len, i;
	i = 0;
	chain = (char*)malloc(sizeof(char)*100);
	chainOut = (char*)malloc(sizeof(char)*100); 
	printf("Escriba una cadena: ");
	scanf("%[^\n]", chain);
	quitaespacios(chain, chainOut);
	printf("Cadena sin espacios: ");
	for(i; chainOut[i] != '\0'; i++){
		printf("%c", chainOut[i]);
	}
	free(chain);
	free(chainOut);
	return 0;
}

void quitaespacios(char *cadena, char *cadenasin){
	int i = 0, j = 0;
	for(i; cadena[i] != '\0'; i++){
		for(j; cadena[i] != '\0'; j++){
			cadenasin[j] = cadena[i];
			if(cadena[i+1] = ' '){
				i++;
			}
		}
	}
	return;
}
