#ifndef INIMIGOS_H
#define INIMIGOS_H

#include <stdio.h>

#define N 50

struct inimigo_comum{
	char nome[N];
	int hp; //Health points
	int agi; //Agilidade
	int def; //Defesa
	int ata; //Ataque
	int mp; //Mana points
	char fraq[N]; //Fraqueza
}typedef ini_comum;

struct inimigo_elite{
	char nome[N]; 
	int hp; 
	int agi; 
	int def; 
	int ata;
	int mp; 
	char fraq[N];
	char hab_esp[N]; //Habilidade especial
}typedef ini_elite;

struct inimigo_boss{
	char nome[N]; 
	int hp; 
	int agi;
	int def;
	int ata;
	int mp; 
	char hab_esp[N]; 
	char fraq[N];
	char imuni[N]; //Imunidade
	int regen; //Regeneração
}typedef ini_boss;

FILE *ic; //Ponteiro dos status do inimigo comum
FILE *ie; //Ponteiro dos status do inimigo elite
FILE *ib; //Ponteiro dos status do Boss

ini_comum inic;
ini_elite inie;
ini_boss inib;

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
