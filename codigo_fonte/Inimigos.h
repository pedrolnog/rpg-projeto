#ifndef INIMIGOS_H
#define INIMIGOS_H

#include <stdio.h>

#define NI 50

struct inimigo_comum{
	char nome[NI];
	int hp; //Health points
	int agi; //Agilidade
	int def; //Defesa
	int ata; //Ataque
	int mp; //Mana points
	char fraq[NI]; //Fraqueza
}typedef ini_comum;

struct inimigo_elite{
	char nome[NI]; 
	int hp; 
	int agi; 
	int def; 
	int ata;
	int mp; 
	char fraq[NI];
	char hab_esp[NI]; //Habilidade especial
}typedef ini_elite;

struct inimigo_boss{
	char nome[NI]; 
	int hp; 
	int agi;
	int def;
	int ata;
	int mp; 
	char hab_esp[NI]; 
	char fraq[NI];
	char imuni[NI]; //Imunidade
	int regen; //Regeneração
}typedef ini_boss;

FILE *inimigo_comum; //Ponteiro dos status do inimigo comum
FILE *inimigo_elite; //Ponteiro dos status do inimigo elite
FILE *inimigo_boss; //Ponteiro dos status do Boss

ini_comum inimigoComum;
ini_elite inimigoElite;
ini_boss inimigoBoss;

int ler_inimigo_comum(); //Apresenta os status do inimigo comum
int ler_inimigo_elite(); //Apresenta os status do inimigo elite
int ler_inimigo_boss(); //Apresenta os status do Boss
int apa_inimigo_comum(); //Apaga os dados salvos na struct de inimigo comum
int apa_inimigo_elite(); //Apaga os dados salvos na struc de inimigo elite
int apa_inimigo_boss(); //Apaga os dados salvos na struct de inimigo boss	
int upd_inimigo_comum(); //Escreve os status no arquivo .txt de inimigos comum
int upd_inimigo_elite(); //Escreve os status no arquivo .txt de inimigos elite
int upd_inimigo_boss(); //Escreve os status no arquivo .txt de inimigos boss
int cri_inimigo_comum(); //Cria um aqruivo .txt com os status do inimigo comum
int cri_inimigo_elite(); //Cria um arquivo .txt com os status do inimigo elite
int cri_inimigo_boss(); //Cria um um arquivo .txt com os status do inimigo boss

#endif
