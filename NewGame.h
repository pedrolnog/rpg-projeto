#ifndef NEWGAME_H
#define NEWGAME_H

typedef struct {
    char nome[50];
    int vida;
    int xp;
} Personagem;

typedef struct {
    int espaco;
    Personagem personagem;
	int timestamp;
	int nivel;
	int checkpoint;
} Save;
Save newGame();

#endif