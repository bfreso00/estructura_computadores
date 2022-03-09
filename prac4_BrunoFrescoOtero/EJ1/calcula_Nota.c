#include <stdio.h>
void calc_Nota(int nota);
int main(){
	int nota_Eva;
	printf("Introduzca la nota a evaluar: ");
	scanf("%d", &nota_Eva);
	calc_Nota(nota_Eva);
	return 0;
}

void calc_Nota(int nota){
	switch(nota){
		case 5:
		case 6: printf("El alumno tiene un aprobado.\n");
			break;
		case 7:
		case 8: printf("El alumno tiene un notable.\n");
			break;
		case 9:
		case 10: printf("El alumno tiene un sobresaliente.\n");
			 break;
		default: printf("EL alumno tiene un suspenso.\n");
	}
	return;
}
