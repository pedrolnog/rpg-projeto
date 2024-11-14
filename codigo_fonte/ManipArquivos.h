#ifndef MANIPARQUIVOS_H
#define MANIPARQUIVOS_H

#include <stdio.h>

#define caminho_save "./dados/saveFile.txt"

FILE* abrirArquivo(const char* caminho, const char* modo);

#endif