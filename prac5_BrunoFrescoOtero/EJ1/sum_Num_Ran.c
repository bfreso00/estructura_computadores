#include <stdio.h>
#include <stdlib.h>
//#include <time.h> => libreria para generar la seed aleatoria

void ini_Vector(int vector_Para[]);
int suma(int vector_Para[]);
int main(){
	int vector[10], result, i;
	i = 0;
	srand(5);
	//srand(time(NULL)); => instanciacion de la seed aleaotoria
	ini_Vector(vector);
	result = suma(vector);
	for(i; i<10; i++){
		printf("El valor del vector %d es: %d\n", i+1, vector[i]);
	}
	printf("El valor de la suma de todas las posiciones es: %d\n", result);
	return 0;
}

void ini_Vector(int vector_Para[]){
	int num_Ran, i;
	i = 0;
	for(i; i<10; i++) {
		vector_Para[i] = (rand() % 10) + 1;
	}
	return;
}

int suma(int vector_Para[]){
	int resultado, i;
	i = 0;
	resultado = 0;
	for(i; i<10; i++){
		resultado = resultado + vector_Para[i];
	}
	return resultado;
}
