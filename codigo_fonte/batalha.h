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

int ataquenoSlime(Save *save, ini_comum inimigoComum);
int ataquenoCavaleiro(Save *save, ini_comum inimigoComum);
int bloquear(Save *save, ini_comum inimigoComum);
int bloquearElite(Save *save, ini_elite inimigoElite);
int fugir();
int usar_item(Save *save);
int ataqueSlime(Save *save, ini_comum inimigoComum);
int ataqueCavaleiro(Save *save);

#endif
