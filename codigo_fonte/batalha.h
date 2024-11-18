#ifndef BATALHA_H
#define BATALHA_H
#include <Windows.h>
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
int bloquear(Save *save, int danoDoSlime);
int fugir(int agilidadeHeroi, int agilidadeInimigo);
int usar_item(Save *save);
int ataqueSlime(Save *save);
int ataqueCavaleiro(Save *save);

#endif
