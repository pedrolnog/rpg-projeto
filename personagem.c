 pedro.wip-batalha_personagem
#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"
#define N 50

typedef struct{
    char nome[N];
    int lvl; //nivel
    int exp; //experiencia
    int hp;//Health Points
    int agi;//Agilidade
    int def;//Dfesa
    int ata;//Ataque
    int mp;//Mana Points
    int ouro; //dinheiro
}Persona;

void atributos(Persona MC){
    int pts = 10;
    int option;
    do{
        printf("\n1. HP: 1pt = +5HP\n2. MP: 1pt = +5HP\n3. ATK: 1pt = +2ATK\n4. DEF: 1pt = +2DEF\n5. AGI: 1pt = +2 AGI\n");
        printf("Qual atributo voce ira aprimorar?\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                MC->hp += 5;
                pts--;
                break;
            case 2:
                MC->mp += 5;
                pts--;
                break;
            case 3:
                MC->ata += 2;
                pts--;
                break;
            case 4:
                MC->def += 2;
                pts--;
                break;
            case 5:
                MC->agi += 2;
                pts--;
                break;
            default:
            printf("Escolha um atributo valido!\n");
            break;
            }
        }while(pts > 0);
    }


void personagem(){
    Persona MC;
    MC.lvl = 1;
    MC.exp = 0;
    MC.hp = 30;
    MC.agi = 10;
    MC.def = 10;
    MC.ata = 10;
    MC.mp = 20;
    MC.ouro = 500;

    printf("Insira o nome do personagem: ");
    fgets(MC.nome, N, stdin);
    printf("Distribua os pontos do personagem\n\n");
    atributos(&MC);

    FILEarquivo = fopen("personagem.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.");
    } else {
        fprintf(arquivo, "Nome: %s\n", MC.nome);
        fprintf(arquivo, "Nivel: %d\n", MC.lvl);
        fprintf(arquivo, "Experiencia: %d\n", MC.exp);
        fprintf(arquivo, "Ouro: %d\n", MC.ouro);
        fprintf(arquivo, "HP: %d\n", MC.hp);
        fprintf(arquivo, "MP: %d\n", MC.mp);
        fprintf(arquivo, "Ataque: %d\n", MC.ata);
        fprintf(arquivo, "Defesa: %d\n", MC.def);
        fprintf(arquivo, "Agilidade: %d\n", MC.agi);
        fclose(arquivo);
    }

#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"
#define N 50

typedef struct{
    char nome[N];
    int lvl; //nivel
    int exp; //experiencia
    int hp;//Health Points
    int agi;//Agilidade
    int def;//Dfesa
    int ata;//Ataque
    int mp;//Mana Points
    int ouro; //dinheiro
}Persona;

void atributos(Persona MC){
    int pts = 10;
    int option;
    do{
        printf("\n1. HP: 1pt = +5HP\n2. MP: 1pt = +5HP\n3. ATK: 1pt = +2ATK\n4. DEF: 1pt = +2DEF\n5. AGI: 1pt = +2 AGI\n");
        printf("Qual atributo voce ira aprimorar?\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                MC->hp += 5;
                pts--;
                break;
            case 2:
                MC->mp += 5;
                pts--;
                break;
            case 3:
                MC->ata += 2;
                pts--;
                break;
            case 4:
                MC->def += 2;
                pts--;
                break;
            case 5:
                MC->agi += 2;
                pts--;
                break;
            default:
            printf("Escolha um atributo valido!\n");
            break;
            }
        }while(pts > 0);
    }


void personagem(){
    Persona MC;
    MC.lvl = 1;
    MC.exp = 0;
    MC.hp = 30;
    MC.agi = 10;
    MC.def = 10;
    MC.ata = 10;
    MC.mp = 20;
    MC.ouro = 500;

    printf("Insira o nome do personagem: ");
    fgets(MC.nome, N, stdin);
    printf("Distribua os pontos do personagem\n\n");
    atributos(&MC);

    FILEarquivo = fopen("personagem.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.");
    } else {
        fprintf(arquivo, "Nome: %s\n", MC.nome);
        fprintf(arquivo, "Nivel: %d\n", MC.lvl);
        fprintf(arquivo, "Experiencia: %d\n", MC.exp);
        fprintf(arquivo, "Ouro: %d\n", MC.ouro);
        fprintf(arquivo, "HP: %d\n", MC.hp);
        fprintf(arquivo, "MP: %d\n", MC.mp);
        fprintf(arquivo, "Ataque: %d\n", MC.ata);
        fprintf(arquivo, "Defesa: %d\n", MC.def);
        fprintf(arquivo, "Agilidade: %d\n", MC.agi);
        fclose(arquivo);
    }
 main
}
