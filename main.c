#include "JogosSalvos.h"
#include "newGame.h"
#include <stdio.h>
#include <unistd.h> // p/ checar se arq. existe
#include <stdlib.h>

int main() {
    int escolha, i;
    char *nomeArquivo = "saveFiles.txt";
    

    if (access(nomeArquivo, F_OK) == 0) {
        //https://www.learnc.net/c-tutorial/c-file-exists/
        FILE *saveFiles = fopen("saveFiles.txt", "w");
        if (saveFiles == NULL) {
            printf("Erro na criação do saveFiles.txt");
        } else {
            for (i = 0; i < 10; i++) {
                fprintf(saveFiles, "%d, Auryn, -1, -1, -1, -1, -1; ", i);
            }
            printf("Arquivo criado");
        }
        fclose(saveFiles);
    }

    printf("Coracao de Auryn\n");
    printf("1. Novo Jogo\n2. Continuar\n3. Opcoes\n4. Sair\n");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            newGame();
            break;
        case 2:
            jogosSalvos();
            break;
    }

    return 0;
}