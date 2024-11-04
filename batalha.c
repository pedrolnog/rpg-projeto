#include <stdio.h>
#include <stdlib.h>
#include "inimigos.h"
#include "personagem.h"

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