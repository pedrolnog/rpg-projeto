#include "ManipArquivos.h"
#include <stdlib.h>
#include <stdio.h>

// Função para abrir arquivos. Serve como wrapper para fopen()
FILE* abrirArquivo(const char* caminho, const char* modo) {
    FILE *arquivo;

    arquivo = fopen(caminho, modo);

    if (arquivo != NULL) {
        return arquivo;
    } else {
        int escolha;
        printf("\n\n\t\tErro ao abrir arquivo: %s\n\n", caminho);
        printf("\n1. Criar novo savefile\n2. Sair\n");

        scanf("%d", &escolha);

        if (escolha == 1) {
            criarPasta();
            arquivo = abrirArquivo(caminho_save, "w");
            return arquivo;
        } else {
            return NULL;
        }
    }
}

void criarPasta() {
    int pasta;

    pasta = mkdir("dados");

    if (!pasta) {
        return ;
    } else {
        printf("\n\n\t\tErro criando pasta do jogo.\n\n");
        exit(1);
    }

}