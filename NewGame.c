#include "JogosSalvos.h"
#include "NewGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int newGame() {
    FILE *saveFiles;
    Save save;
    
    saveFiles = fopen("saveFiles.txt", "w");

        if (saveFiles == NULL) {
            printf("Erro");
            return 0;
        } else {
            printf("[NOVO JOGO]\n");
            printf("Insira o nome do jogador: ");
            scanf("%49s", save.personagem.nome); // Checar uso de ponteiros !
            save.personagem.vida = 100;
            save.personagem.xp = 0;
            save.nivel = 1;
            save.checkpoint = 0;
            save.timestamp = time(NULL);

            fprintf(saveFiles, "%s %d %d %d %d %d\n", 
            save.personagem.nome, save.personagem.vida, save.personagem.xp, save.nivel, save.checkpoint, save.timestamp);
            fclose(saveFiles);
        }
    return 1;
}