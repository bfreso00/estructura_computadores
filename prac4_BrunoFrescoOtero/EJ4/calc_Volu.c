#include <stdio.h>

void volumen_Cono(float radio_Para, float altura_Para);
void volumen_Ortoedro(float l1_Para, float l2_Para, float altura_Para);
int main(){
	float l1, l2, altura;
	int opc;
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
				volumen_Cono(l1, altura);
				break;
			case 2: printf("Introduzca el valor del primer lado:");
				scanf("%f", &l1);
				printf("Introduzca el valor del segundo lado:");
				scanf("%f", &l2);
				printf("Introduzca el valor de la altura:");
				scanf("%f", &altura);
				volumen_Ortoedro(l1, l2, altura);
				break;
			case 3: return 0;
				break;
			default: printf("Introduzca una opción valida, por favor.\n");
		}
	} while(opc != 3);
}

void volumen_Cono(float radio_Para, float altura_Para){
	float C_Volu, Pi;
	Pi = 3.14;
	C_Volu = (Pi * radio_Para * radio_Para * altura_Para)/3;
	printf("El volumen del cono es: %f\n", C_Volu);
	return;	
}

void volumen_Ortoedro(float l1_Para, float l2_Para, float altura_Para){
	float O_Volu;
	O_Volu = l1_Para * l2_Para * altura_Para;
	printf("El volumen del ortoedro es: %f\n", O_Volu);
	return;	
}
