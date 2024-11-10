#ifndef BATALHA_H
#define BATALHA_H

#include "Inimigos.h"

typedef struct { 
    Personagem personagem;
    ini_boss Boss;
    int turnoAtual;
    int quantTurnos;
    int vencedor;
} Bossfight;

typedef struct { 
    Personagem personagem;
    ini_elite inimigoElite;
    int turnoAtual;
    int quantTurnos;
    int vencedor;
} Elitefight;

typedef struct { 
    Personagem personagem;
    ini_comum inimigo;
    int turnoAtual;
    int quantTurnos;
    int vencedor;
} fight;

int ataque();
int bloquear(int danoDoSlime);
int fugir(int agilidadeHeroi, int agilidadeInimigo);
int usar_item();

#endif