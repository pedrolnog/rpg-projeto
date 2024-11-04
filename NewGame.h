#ifndef NEWGAME_H
#define NEWGAME_H

typedef struct {
    char nome[50];
    int vida;
    int xp;
} Personagem; // Struct teste

typedef struct {
    Personagem personagem;
	int timestamp;
	int nivel;
	int checkpoint;
} Save;

int newGame();

#endif