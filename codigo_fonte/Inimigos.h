#ifndef INIMIGOS_H
#define INIMIGOS_H

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
	int regen; //Regenera��o
}typedef ini_boss;

int inimigo_comum();
int inimigo_elite();
int inimigo_boss();

#endif