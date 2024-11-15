#include "codigo_fonte/savegame.h"
#include "codigo_fonte/Inimigos.h"
#include "codigo_fonte/armas.h"
#include "codigo_fonte/batalha.h"
#include "codigo_fonte/armaduras.h"
#include "codigo_fonte/ManipArquivos.h"
#include <stdio.h>
#include <unistd.h> // p/ checar se arq. existe
#include <stdlib.h>
#include <locale.h> // https://linguagemc.com.br/localizacao-de-programas-com-locale-h/#:~:text=A%20utiliza%C3%A7%C3%A3o%20do%20arquivo%20locale,localidade%20padr%C3%A3o%20do%20sistema%20operacional.

int main() {
    int escolha;
    char *nomeArquivo = "./dados/saveFile.txt";
    
    setlocale(LC_ALL, "Portuguese"); // UTF-8 n�o funciona. Mudar encoding. (https://cursos.alura.com.br/forum/topico-acentuacao-com-setlocale-nao-funciona-105663)

    printf("%d", access(nomeArquivo, F_OK));
    
    if (access(nomeArquivo, F_OK) == -1) {
        //https://www.learnc.net/c-tutorial/c-file-exists/
        FILE *saveFile = abrirArquivo(nomeArquivo, "w");
        fclose(saveFile);
    }

    do {
        printf("\n Coração de Auryn \n");
        printf("1. Novo Jogo\n2. Continuar\n3. Opções\n4. Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (newGame() == 1) {
                    printf("Save criado!\n");
                    ler_inimigo_comum();
                    ataque();
                } else {
                    printf("Falha em criar save\n");
                };
                break;
            case 2:
                jogosSalvos();
                ler_inimigo_comum();
                ataque();
                break;
            case 3:
                criar();

        }
    } while (escolha != 4);

    return 0;
}