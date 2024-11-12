#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"
#define N 50

int pts = 10;

void personagem(Persona *MC){

    int opt;
    do{
    	printf("O que deseja fazer com o personagem?\n");
    	printf("1. Criar.\n");
    	printf("2. Ler status.\n");
    	printf("3. Distribuir pontos.\n");
    	printf("4. Deletar personagem.\n");
    	printf("5. Sair.\n");
    	printf("Opcao: ");
    	scanf("%d", &opt);
    	getchar();
    	switch(opt){
    		case 1:
    			criarPersonagem(MC);
    			break;
    		case 2:
    			statusPersonagem(MC);
    			break;
    		case 3:
    			upPersonagem(MC, pts);
    			break;
    		case 4:
    			deletePersonagem(MC);
    			break;
    		case 5:
    			printf("Saindo. . .\n");
    			break;
    		default:
    			printf("Opcao invalida!\n");
		}
	}while(opt != 5);
    
}

void criarPersonagem(Persona *MC){
	//corresponde ao Creat do CRUD
    MC->lvl = 1;
    MC->exp = 0;
    MC->hp = 30;
    MC->agi = 10;
    MC->def = 10;
    MC->ata = 10;
    MC->mp = 20;
    MC->ouro = 500;
    printf("Insira o nome do personagem: ");
    fgets(MC->nome, N, stdin);
    FILE *mcArquivo = fopen("personagem.txt", "w");
    if(mcArquivo == NULL){
        printf("Erro ao abrir o arquivo.");
    } else {
        fprintf(mcArquivo, "Nome: %s\n", MC->nome);
        fprintf(mcArquivo, "Nivel: %d\n", MC->lvl);
        fprintf(mcArquivo, "Experiencia: %d\n", MC->exp);
        fprintf(mcArquivo, "Ouro: %d\n", MC->ouro);
        fprintf(mcArquivo, "HP: %d\n", MC->hp);
        fprintf(mcArquivo, "MP: %d\n", MC->mp);
        fprintf(mcArquivo, "Ataque: %d\n", MC->ata);
        fprintf(mcArquivo, "Defesa: %d\n", MC->def);
        fprintf(mcArquivo, "Agilidade: %d\n", MC->agi);
        fclose(mcArquivo);
    }
	
}

void statusPersonagem(Persona *MC){
	//correspondente ao Read do CRUD
	FILE *mcArquivo = fopen("personagem.txt", "r");
    if(mcArquivo == NULL){
        printf("Erro ao abrir o arquivo.");
    } else {
        fscanf(mcArquivo, "Nome: %49[^\n]\n", MC->nome);
        fscanf(mcArquivo, "Nivel: %d\n", &MC->lvl);
        fscanf(mcArquivo, "Experiencia: %d\n", &MC->exp);
        fscanf(mcArquivo, "Ouro: %d\n", &MC->ouro);
        fscanf(mcArquivo, "HP: %d\n", &MC->hp);
        fscanf(mcArquivo, "MP: %d\n", &MC->mp);
        fscanf(mcArquivo, "Ataque: %d\n", &MC->ata);
        fscanf(mcArquivo, "Defesa: %d\n", &MC->def);
        fscanf(mcArquivo, "Agilidade: %d\n", &MC->agi);
        
        printf("Status do personagem:\n");
        
        printf("Nome: %s\n", MC->nome);
        printf("Nivel: %d\n", MC->lvl);
        printf("Experiencia: %d\n", MC->exp);
        printf("Ouro: %d\n", MC->ouro);
        printf("HP: %d\n", MC->hp);
        printf("MP: %d\n", MC->mp);
        printf("Ataque: %d\n", MC->ata);
        printf("Defesa: %d\n", MC->def);
        printf("Agilidade: %d\n", MC->agi);
        
        fclose(mcArquivo);
    }
}

void upPersonagem(Persona *MC, int pts){
	//refere-se ao Update de CRUD
	printf("Distribua os pontos do personagem\n");
	
    int option;
    do{
        printf("\n1. HP: 1pt = +5HP\n2. MP: 1pt = +5HP\n3. ATK: 1pt = +2ATK\n4. DEF: 1pt = +2DEF\n5. AGI: 1pt = +2 AGI\n");
        printf("Pontos disponiveis: %d\n", pts);
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
    FILE *mcArquivo = fopen("personagem.txt", "w");
    if(mcArquivo == NULL){
        printf("Erro ao abrir o arquivo.");
    } else {
        fprintf(mcArquivo, "Nome: %s\n", MC->nome);
        fprintf(mcArquivo, "Nivel: %d\n", MC->lvl);
        fprintf(mcArquivo, "Experiencia: %d\n", MC->exp);
        fprintf(mcArquivo, "Ouro: %d\n", MC->ouro);
        fprintf(mcArquivo, "HP: %d\n", MC->hp);
        fprintf(mcArquivo, "MP: %d\n", MC->mp);
        fprintf(mcArquivo, "Ataque: %d\n", MC->ata);
        fprintf(mcArquivo, "Defesa: %d\n", MC->def);
        fprintf(mcArquivo, "Agilidade: %d\n", MC->agi);
        
        
        fclose(mcArquivo);
    	}
    }

void deletePersonagem(Persona *MC){
	//corresponde ao Delete do CRUD
	if(remove("personagem.txt") == 0){
		printf("Personagem apagado com sucesso!");
	}else{
		printf("Erro ao deletar personagem.");
	}
}
