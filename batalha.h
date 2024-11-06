#ifndef BATALHA_H
#define BATALHA_H
#include "personagem.h"
#include "Inimigos.h"

typedef struct { 
    Persona personagem;
    inimigo_boss Boss;
    int turnoAtual;
    int quantTurnos;
    int vencedor;
} Bossfight;

typedef struct { 
    Persona personagem;
    inimigo_elite inimigoElite;
    int turnoAtual;
    int quantTurnos;
    int vencedor;
} Elitefight;

typedef struct { 
    Persona personagem;
    inimigo_comum inimigo;
    int turnoAtual;
    int quantTurnos;
    int vencedor;
} fight;

int ataque();
int bloquear(int danoDoSlime);
int fugir(int agilidadeHeroi, int agilidadeInimigo);
int usar_item();

#endif