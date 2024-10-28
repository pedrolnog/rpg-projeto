#include "JogosSalvos.h"
#include "NewGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Save newGame() {
    Save save;

    printf("[NOVO JOGO]\n");
    printf("Insira o nome do jogador: ");
    scanf("%49s", save.personagem.nome); // Checar uso de ponteiros !
    save.personagem.vida = 100;
    save.personagem.xp = 0;
    save.nivel = 1;
    save.checkpoint = 0;
    save.timestamp = time(NULL);

    printf("Save criado!");

    return save;
}