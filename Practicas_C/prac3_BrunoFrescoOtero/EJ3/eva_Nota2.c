#include <stdio.h>
int main()
{
	int nota;
	printf("Introduzca una nota a evaluar: ");
	scanf("%d", &nota);
	switch (nota){
		case 5:
		case 6: printf("El alumno tiene un aprobado.\n");
			break;
		case 7:
		case 8: printf("El alumno tiene un notable.\n");
			break;
		case 9:
		case 10: printf("El alumno tiene un sobresaliente.\n");
			 break;
		default: printf("El alumno tiene un suspenso.\n");
	}
	printf("Fin del algoritmo.\n");
	return 0;
}
