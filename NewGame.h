#ifndef NEWGAME_H
#define NEWGAME_H

typedef struct {
    char nome[50];
    int vida;
    int xp;
} Personagem;

typedef struct {
    Personagem personagem;
	int timestamp;
	int nivel;
	int checkpoint;
} Save;
int newGame();

#endif