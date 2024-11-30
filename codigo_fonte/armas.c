#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "armas.h"


//funão que deleta as informações da arma espada
void apagar_espada(){
	armaEspada = fopen("armas_espadas.txt", "w");
	if(armaEspada == NULL){
		printf("Erro!");
	}
	else{
	printf("\nDados Apagados\n\n");
	}
	fclose(armaEspada);
}

//funão que deleta as informações da arma arco
void apagar_arco(){
	armaArco = fopen("armas_arcos.txt", "w");
	if(armaArco == NULL){
		printf("Erro!");
	}
	else{
	printf("\nDados Apagados\n\n");
	}
	fclose(armaArco);
}

//funão que deleta as informações da arma cajado
void apagar_cajado(){
	armaCajado = fopen("armas_cajados.txt", "w");
	if(armaCajado == NULL){
		printf("Erro!");
	}
	else{
	printf("\nDados Apagados\n\n");
	}
	fclose(armaCajado);
}




// Função que criar o arquivo da espada
void criar_espada(){
	armaEspada = fopen("armas_espadas.txt", "w");
	if(armaEspada == NULL){
		printf("Error!\n");
	}
	else{
	fprintf(armaEspada, "Espada_Do_Caos\nCortante\n2\n12\nLacerar\n2\n8\nSangrar\n");
	printf("Arma criada\n");
	}
	fclose(armaEspada);
}

// Função que criar o arquivo do arco
void criar_arco(){
	armaArco = fopen("armas_arcos.txt", "w");
	if(armaArco == NULL){
		printf("Error!\n");
	}
	else{
	fprintf(armaArco, "Arco_da_Lua_Negra\nPerfurante\n4\n8\nJarrete\n3\n6\nDebilitar");
	printf("Arma criada\n");
	}
	fclose(armaArco);
}

// Função que criar o arquivo do cajado
void criar_cajado(){
	armaCajado = fopen("armas_cajados.txt", "w");
	if(armaCajado == NULL){
		printf("Error!\n");
	}
	else{
	fprintf(armaCajado, "Cajado_do_Sabio\nGelo\n3\n12\nSepultura_Glacial\n3\n15\nCongelar");
	printf("Arma criada\n");
	}
	fclose(armaCajado);
}

// Função que mostra as informações da espada

void espadas(){
	Arma espada;
	armaEspada = fopen("armas_espadas.txt", "r");
	if(armaEspada == NULL){
		printf("ERROR!!!");
	}
	else{
	fscanf(armaEspada, "%s %s %d %d %s %d %d %s", &espada.nome, &espada.tipoDano, &espada.danoMin, &espada.danoMax, &espada.habilidade, &espada.danoMinH, &espada.danoMaxH, &espada.efeito);
	
	printf("Dados da Arma \n");
	printf("nome: %s\nTipo de Dano: %s\nDano %d-%d\nHabilidade Especial: %s\nDano da Habilidade: %d-%d\nEfeito: %s\n\n", espada.nome, espada.tipoDano, espada.danoMin, espada.danoMax, espada.habilidade, espada.danoMinH, espada.danoMaxH, espada.efeito);
	fclose(armaEspada);	
	system("pause\n\n");
	
	}
}


void arcos(){
	Arma arco;
	armaArco = fopen("armas_arcos.txt", "r");
	if(armaArco == NULL){
		printf("ERROR!!!");
	}
	else{
	fscanf(armaArco, "%s %s %d %d %s %d %d %s", &arco.nome, &arco.tipoDano, &arco.danoMin, &arco.danoMax, &arco.habilidade, &arco.danoMinH, &arco.danoMaxH, &arco.efeito);
	
	
	printf("Dados da Arma \n");
	printf("nome: %s\nTipo de Dano: %s\nDano %d-%d\nHabilidade Especial: %s\nDano da Habilidade: %d-%d\nEfeito: %s\n\n", arco.nome, arco.tipoDano, arco.danoMin, arco.danoMax, arco.habilidade, arco.danoMinH, arco.danoMaxH, arco.efeito);
	fclose(armaArco);
	system("pause\n\n");
	}
}

void cajados(){
	Arma cajado;
	armaCajado = fopen("armas_cajados.txt", "r");
	if(armaCajado == NULL){
		printf("ERROR!!!");
	}
	else{
	fscanf(armaCajado, "%s %s %d %d %s %d %d %s", &cajado.nome, &cajado.tipoDano, &cajado.danoMin, &cajado.danoMax, &cajado.habilidade, &cajado.danoMinH, &cajado.danoMaxH, &cajado.efeito);
	
	
	printf("Dados da Arma \n");
	printf("nome: %s\nTipo de Dano: %s\nDano %d-%d\nHabilidade Especial: %s\nDano da Habilidade: %d-%d\nEfeito: %s\n\n", cajado.nome, cajado.tipoDano, cajado.danoMin, cajado.danoMax, cajado.habilidade, cajado.danoMinH, cajado.danoMaxH, cajado.efeito);
	fclose(armaCajado);
	system("pause\n\n");
	}
}

void alternar_espada(){
	armaEspada = fopen("armas_espadas.txt", "w");
	if(armaEspada == NULL){
		printf("Error!");
	}
	else{
	fprintf(armaEspada, "Espada_de_ferro\nCortante\n1\n4\nCorte\n0\n2\nDesorientacao\n");
	}
	fclose(armaEspada);
}

void alternar_arco(){
	armaArco = fopen("armas_arcos.txt", "w");
	if(armaArco == NULL){
		printf("Error!");
	}
	else{
	fprintf(armaArco, "Arco_curto\nperfurante\n0\n4\nDisparo_rapido\n2\n6\nNenhum\n");
	}
	fclose(armaArco);
}

void alternar_cajado(){
	armaCajado = fopen("armas_cajados.txt", "w");
	if(armaCajado == NULL){
		printf("Error!");
	}
	else{
	fprintf(armaCajado, "Cajado_simples\nMagico\n2\n6\nCanalizar\n0\n0\nBonus_em_inteligencia\n");
	}
	fclose(armaCajado);	
}

















