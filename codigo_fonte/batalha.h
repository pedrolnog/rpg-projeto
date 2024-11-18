#include <Windows.h>
#ifndef BATALHA_H
#define BATALHA_H
#include "Inimigos.h"
#include "savegame.h"

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

int ataquenoSlime();
int ataquenoCavaleiro();
int bloquear(int danoDoSlime);
int fugir(int agilidadeHeroi, int agilidadeInimigo);
int usar_item();
int ataqueSlime();
int ataqueCavaleiro();

#endif

int ataque();
int bloquear(int danoDoSlime);
int fugir(int agilidadeHeroi, int agilidadeInimigo);
int usar_item();

#endif
