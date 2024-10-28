#include "JogosSalvos.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int escolha;

    printf("Coracao de Auryn\n");
    printf("1. Novo Jogo\n2. Comecar\n3. Opcoes\n4. Sair\n");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            break;
        case 2:
            jogosSalvos();
            break;
    }

    return 0;
}