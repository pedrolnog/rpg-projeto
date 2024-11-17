#include "codigo_fonte/savegame.h"
#include "codigo_fonte/Inimigos.h"
#include "codigo_fonte/armas.h"
#include "codigo_fonte/batalha.h"
#include "codigo_fonte/armaduras.h"
#include "codigo_fonte/ManipArquivos.h"
#include "codigo_fonte/inventario.h"
#include "codigo_fonte/iniciarJogo.h"
#include <stdio.h>
#include <unistd.h> // p/ checar se arq. existe
#include <stdlib.h>
#include <locale.h> // https://linguagemc.com.br/localizacao-de-programas-com-locale-h/#:~:text=A%20utiliza%C3%A7%C3%A3o%20do%20arquivo%20locale,localidade%20padr%C3%A3o%20do%20sistema%20operacional.

int main() {
    int escolha, escolha2;
    char *nomeArquivo = "./dados/saveFile.txt";
    
    setlocale(LC_ALL, "Portuguese"); // UTF-8 n�o funciona. Mudar encoding. (https://cursos.alura.com.br/forum/topico-acentuacao-com-setlocale-nao-funciona-105663)    
    
    do {
        printf("\n Coração de Auryn \n");
        printf("1. Novo Jogo\n2. Continuar\n3. Opções\n4. Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                newGame();
                iniciarJogo();
                break;
            case 2:
                if (access(nomeArquivo, F_OK) == -1) {
                    printf("Jogo anterior não encontrado.\n1. Criar novo jogo\n2. Sair\n");
                    scanf("%d", &escolha2);
                    if (escolha2 == 1) {
                        //https://www.learnc.net/c-tutorial/c-file-exists/
                        FILE *saveFile = abrirArquivo(nomeArquivo, "w");
                        fclose(saveFile);
                        newGame();
                    } else {
                        continue;
                    }
                } else {
                    iniciarJogo();
                }
                break;
            case 3:
                criar();
                break;

        }
    } while (escolha != 4);

    return 0;
}