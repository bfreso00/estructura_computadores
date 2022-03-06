#include <stdio.h>
int main()
{
	int nota;
	printf("Introduzca una nota a evaluar: ");
	scanf("%d", &nota);
	if(nota == 5 || nota == 6){
		printf("El alumno tiene un aprobado.\n");
	} else if(nota == 7 || nota == 8){
		printf("El alumno tiene un notable.\n");
	} else if(nota == 9 || nota == 10){
		printf("El alumno tiene un sobresaliente.\n");
	} else {
		printf("El alumno tiene un suspenso.\n");
	}
	return 0;
}
