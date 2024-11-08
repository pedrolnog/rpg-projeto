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
        printf("\n\n\t\tErro ao abrir arquivo: %s\n\n", caminho);
        return NULL;
    }
}