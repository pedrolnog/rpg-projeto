#include "JogosSalvos.h"
#include "NewGame.h"
#include "ManipArquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Parte de Coimbra
void atributos(Save *save){
    int pts = 10;
    int option;
    do{
        printf("Distribua os pontos do personagem\n\n");
        printf("\n1. HP: 1pt = +5HP\n2. MP: 1pt = +5HP\n3. ATK: 1pt = +2ATK\n4. DEF: 1pt = +2DEF\n5. AGI: 1pt = +2 AGI\n");
        printf("Qual atributo voce ira aprimorar?\n");
        scanf("%d", &option);
        printf("Pontos sobrando: %d\n", pts);
        switch(option){
            case 1:
                save->personagem.hp += 5;
                pts--;
                break;
            case 2:
                save->personagem.mp += 5;
                pts--;
                break;
            case 3:
                save->personagem.ata += 2;
                pts--;
                break;
            case 4:
                save->personagem.def += 2;
                pts--;
                break;
            case 5:
                save->personagem.agi += 2;
                pts--;
                break;
            default:
                printf("Escolha um atributo valido!\n");
            break;
            }
        }while(pts > 0);
        fflush(stdin);
    }


void personagem(Save *save){
    save->personagem.lvl = 1;
    save->personagem.exp = 0;
    save->personagem.hp = 30;
    save->personagem.agi = 10;
    save->personagem.def = 10;
    save->personagem.ata = 10;
    save->personagem.mp = 20;
    save->personagem.ouro = 500;

    fflush(stdin);
    printf("Insira o nome do personagem: ");
    fgets(save->personagem.nome, N, stdin);
    save->personagem.nome[strcspn(save->personagem.nome, "\n")] = 0;
    printf("%s", save->personagem.nome);
    atributos(save);

    FILE *arquivo = abrirArquivo("./gameinfo/saveFile.txt", "w");
    
    fprintf(arquivo, "Nome: %49s Nivel: %d, Experiencia: %d, Ouro: %d, HP: %d, MP: %d, Ataque: %d, Defesa: %d, Agilidade: %d, ", 
    save->personagem.nome, save->personagem.lvl, save->personagem.exp, save->personagem.ouro, save->personagem.hp, save->personagem.mp, save->personagem.ata, save->personagem.def, save->personagem.agi);
       
    fclose(arquivo);
}

// Parte de Pedro

int newGame() {
    FILE *saveFile;
    Save save;
    
    saveFile = abrirArquivo("./gameinfo/saveFile.txt", "a");
    
    printf("[NOVO JOGO]\n");
        
    save.nivel = 1;
    save.checkpoint = 0;
    save.timestamp = time(NULL);

    personagem(&save);

    fprintf(saveFile, "Área: %d, Checkpoint: %d, Timestamp: %d\n", save.nivel, save.checkpoint, save.timestamp);

    fclose(saveFile);
    return 1;
}