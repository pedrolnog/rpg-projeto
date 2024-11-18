#ifndef SAVEGAME_H
#define SAVEGAME_H

#define MAXIMO_SAVES 1

typedef enum{
	SAUDAVEL,
	ENVENENADO,
	MORRENDO,
	MORTO
}Status; 

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
	Status status; // Status do personagem
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
