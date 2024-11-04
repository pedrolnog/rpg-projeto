#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#define N 50

typedef struct{
	char nome[N];
	int lvl; //nivel
	int exp; //experiencia
	int hp;//Health Points
	int agi;//Agilidade
	int def;//Dfesa
	int ata;//Ataque
	int mp;//Mana Points
	int ouro; //dinheiro
} Persona;

void atributos(Persona *MC);
void personagem();

#endif
