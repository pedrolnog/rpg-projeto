#include "armaduras.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criar(){
	printf("b");

	FILE *vestes;
	struct armadura atributos;
	vestes = fopen("dados/vestes.txt", "w"); 
	
	if (vestes == NULL){
		printf("erro!");
	}else{
		strcpy(atributos.tipo, "base");
		atributos.mobilidade= 10;
		atributos.peso = 20;
		atributos.resistencia = 50;
		fprintf(vestes, "mobilidade: %d; peso: %d; tipo:%s; resistencia:%d");
		fclose(vestes);
	}
}