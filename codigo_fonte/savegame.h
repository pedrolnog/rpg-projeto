#ifndef NEWGAME_H
#define NEWGAME_H

#define MAXIMO_SAVES 1

typedef struct{
	char nome[50];
	int lvl;  //nivel
	int exp;  //experiencia
	int hp;   //Health Points
	int agi;  //Agilidade
	int def;  //Dfesa
	int ata;  //Ataque
	int mp;   //Mana Points
	int ouro; //dinheiro
} Personagem;

typedef struct {
    Personagem personagem;
	int timestamp;
	int nivel;
	int checkpoint;
} Save;

void personagem(Save *save);
void criarPersonagem(Save *save);
void statusPersonagem(Save *save);
void upPersonagem(Save *save, int pts);
void deletePersonagem(Save *save);
int newGame();
void atributos(Save *save);
void personagem(Save *save);
void jogosSalvos();

Personagem heroi;
#endif
