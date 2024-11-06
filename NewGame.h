#ifndef NEWGAME_H
#define NEWGAME_H

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
} Personagem;

typedef struct {
    Personagem personagem;
	int timestamp;
	int nivel;
	int checkpoint;
} Save;

int newGame();
void atributos(Save *save);
void personagem(Save *save);

#endif