#include <stdio.h>
int main(){
	float C_Volumen, O_Volumen, l1, l2, altura, Pi;
	int opc;
	Pi = 3.14;
	do{
		printf("Escoja la opción que desea realizar:\n");
		printf("1)Cono.\n");
		printf("2)Ortoedro.\n");
		printf("3)Salir.\n");
		scanf("%d", &opc);
		switch(opc){
			case 1: printf("Introduzca el valor del radio de la base:");
				scanf("%f", &l1);
				printf("Introduzca la altura del cono:");
				scanf("%f", &altura);
				C_Volumen = (Pi * l1 * l1 * altura)/3;
				printf("El volumen del cono es: %f\n", C_Volumen);
				break;
			case 2: printf("Introduzca el valor del primer lado:");
				scanf("%f", &l1);
				printf("Introduzca el valor del segundo lado:");
				scanf("%f", &l2);
				printf("Introduzca el valor de la altura:");
				scanf("%f", &altura);
				O_Volumen = l1 * l2 * altura;
				printf("El volumen del ortoedro es: %f\n", O_Volumen);
				break;
			case 3: return 0;
				break;
			default: printf("Introduzca una opción valida, por favor.\n");
		}
	} while(opc != 3);
}
