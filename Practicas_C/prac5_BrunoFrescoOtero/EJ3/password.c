#include <stdio.h>
#include <stdlib.h>
//#include <time.h> => libreria para generar los valores aleatorios

void abc(int vector_Para[]);
int main(){
	int vector[26], i;
	char password[9];
	i = 0;
	srand(5);
	//srand(time(NULL)); => instanciación de la seed aleatoria
	abc(vector);
	for(i; i<9; i++){
		if(i != 8){
			password[i] = vector[rand()%(25+1)];
		} else {
			password[i] = '\0';
		}
	}
	printf("%s\n", password);
	return 0;
}

void abc(int vector_Para[]){
	int i, num_Char;
	i = 0;
	num_Char = 97;
	for(i; i<26; i++){
		vector_Para[i] = num_Char;
		num_Char++;
	}
	return;
}
