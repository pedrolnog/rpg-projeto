#include "savegame.h"
#include "statusPersonagem.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void mostrarStatus(Save *save){
	
	printf("nome: %s\n", save->personagem.nome);
	printf("vida:%d\n", save->personagem.hp);
	printf("Status: \n");
	
	switch(save->personagem.status){
		
		case SAUDAVEL:
			printf("Saudavel");
			break;
		
		case ENVENENADO:
			printf("envenenado");
			break;
			
		case MORRENDO:
			printf("morrendo");
			break;
			
		case MORTO:
			printf("morto");
			break;
	}
	
	
	printf("\n\n\n");
}