#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "armas.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Fun��o que mostra as informa��es da espada
void espadas(){
	FILE *ae;
	arma espada;
	
	
	ae = fopen("gameinfo/armas_espadas.txt", "r");
	if(ae == NULL){
		printf("ERROR!!!");
	}
	else{
	fscanf(ae, "%49s %24s %d %d %24s %d %d %24s", &espada.nome, &espada.tipoDano, &espada.danoMin, &espada.danoMax, &espada.habilidade, &espada.danoMinH, &espada.danoMaxH, &espada.efeito);
	
	
	printf("Dados da Arma \n");
	printf("nome: %s\nTipo de Dano: %s\nDano %d-%d\nHabilidade Especial: %s\nDano da Habilidade: %d-%d\nEfeito: %s\n\n", espada.nome, espada.tipoDano, espada.danoMin, espada.danoMax, espada.habilidade, espada.danoMinH, espada.danoMaxH, espada.efeito);
	
	fclose(ae);
	system("pause");
	}
}


void arcos(){
	FILE *aa;
	arma arco;
	
	
	aa = fopen("gameinfo/armas_arcos.txt", "r");
	if(aa == NULL){
		printf("ERROR!!!");
	}
	else{
	fscanf(aa, "%49s %24s %d %d %24s %d %d %24s", &arco.nome, &arco.tipoDano, &arco.danoMin, &arco.danoMax, &arco.habilidade, &arco.danoMinH, &arco.danoMaxH, &arco.efeito);
	
	
	printf("Dados da Arma \n");
	printf("nome: %s\nTipo de Dano: %s\nDano %d-%d\nHabilidade Especial: %s\nDano da Habilidade: %d-%d\nEfeito: %s\n\n", arco.nome, arco.tipoDano, arco.danoMin, arco.danoMax, arco.habilidade, arco.danoMinH, arco.danoMaxH, arco.efeito);
	
	fclose(aa);
	system("pause");
	}
}

void cajados(){
	FILE *ac;
	arma cajado;
	
	
	ac = fopen("gameinfo/armas_cajados.txt", "r");
	if(ac == NULL){
		printf("ERROR!!!");
	}
	else{
	fscanf(ac, "%49s %24s %d %d %24s %d %d %24s", &cajado.nome, &cajado.tipoDano, &cajado.danoMin, &cajado.danoMax, &cajado.habilidade, &cajado.danoMinH, &cajado.danoMaxH, &cajado.efeito);
	
	
	printf("Dados da Arma \n");
	printf("nome: %s\nTipo de Dano: %s\nDano %d-%d\nHabilidade Especial: %s\nDano da Habilidade: %d-%d\nEfeito: %s\n\n", cajado.nome, cajado.tipoDano, cajado.danoMin, cajado.danoMax, cajado.habilidade, cajado.danoMinH, cajado.danoMaxH, cajado.efeito);
	
	fclose(ac);
	system("pause");
	}
}
