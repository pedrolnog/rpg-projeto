#include "savegame.h"
#include "ManipArquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Parte de Coimbra
int pts = 10;
void personagem(Save *save){
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
    			criarPersonagem(save);
    			break;
    		case 2:
    			statusPersonagem(save);
    			break;
    		case 3:
    			upPersonagem(save, pts);
    			break;
    		case 4:
    			deletePersonagem(save);
    			break;
    		case 5:
    			printf("Saindo. . .\n");
    			break;
    		default:
    			printf("Opcao invalida!\n");
		}
	}while(opt != 5);
    
}
void criarPersonagem(Save *save){
	//corresponde ao Creat do CRUD
    save->personagem.lvl = 1;
    save->personagem.exp = 0;
    save->personagem.hp = 30;
    save->personagem.agi = 10;
    save->personagem.def = 10;
    save->personagem.ata = 10;
    save->personagem.mp = 20;
    save->personagem.ouro = 500;
    printf("Insira o nome do personagem: ");
    fgets(save->personagem.nome, 50, stdin);
    save->personagem.nome[strcspn(save->personagem.nome, "\n")] = 0;
    
    FILE *mcArquivo = abrirArquivo("dados/saveFile.txt", "w");

     fprintf(mcArquivo, "Nome: %s Nivel: %d Experiencia: %d Ouro: %d HP: %d MP: %d Ataque: %d Defesa: %d Agilidade: %d ", 
    save->personagem.nome, save->personagem.lvl, save->personagem.exp, save->personagem.ouro, save->personagem.hp, save->personagem.mp, save->personagem.ata, save->personagem.def, save->personagem.agi);
    
    fclose(mcArquivo);
}
void statusPersonagem(Save *save){
	//correspondente ao Read do CRUD
	FILE *mcArquivo = abrirArquivo("./dados/saveFile.txt", "r");

    fscanf(mcArquivo, "Nome: %49s[^\n] Nivel: %d Experiencia: %d Ouro: %d HP: %d MP: %d Ataque: %d Defesa: %d Agilidade: %d ", save->personagem.nome    , &save->personagem.lvl, &save->personagem.exp, &save->personagem.ouro, &save->personagem.hp, &save->personagem.mp, &save->personagem.ata, &save->personagem.def, &save->personagem.agi);
    
    printf("Status do personagem:\n");
    
    printf("Nome: %s\n", save->personagem.nome);
    printf("Nivel: %d\n", save->personagem.lvl);
    printf("Experiencia: %d\n", save->personagem.exp);
    printf("Ouro: %d\n", save->personagem.ouro);
    printf("HP: %d\n", save->personagem.hp);
    printf("MP: %d\n", save->personagem.mp);
    printf("Ataque: %d\n", save->personagem.ata);
    printf("Defesa: %d\n", save->personagem.def);
    printf("Agilidade: %d\n", save->personagem.agi);
    
    fclose(mcArquivo);

}
void upPersonagem(Save *save, int pts){
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
                break;
        }
    } while (pts > 0);

    FILE *mcArquivo = abrirArquivo("dados/saveFile.txt", "w");
    
    fprintf(mcArquivo, "Nome: %s Nivel: %d Experiencia: %d Ouro: %d HP: %d MP: %d Ataque: %d Defesa: %d Agilidade: %d ", 
    save->personagem.nome, save->personagem.lvl, save->personagem.exp, save->personagem.ouro, save->personagem.hp, save->personagem.mp, save->personagem.ata, save->personagem.def, save->personagem.agi);
    
    fclose(mcArquivo);
    
    }

void deletePersonagem(Save *save){
	//corresponde ao Delete do CRUD
	if(remove("./dados/saveFile.txt") == 0){
		printf("Personagem apagado com sucesso!");
	}else{
		printf("Erro ao deletar personagem.");
	}
}

// Parte de Pedro

int newGame() {
    FILE *saveFile;
    Save save;
    
    printf("[NOVO JOGO]\n");
        
    save.nivel = 0;
    save.checkpoint = 0;
    save.timestamp = time(NULL);

    criarPersonagem(&save);
    upPersonagem(&save, 4);

    saveFile = abrirArquivo("./dados/saveFile.txt", "a");

    fprintf(saveFile, "Area: %d Checkpoint: %d Timestamp: %d ", save.nivel, save.checkpoint, save.timestamp);

    fclose(saveFile);
    return 1;
}

void jogosSalvos() {
	Save save;
	FILE *saveFile;

	// memset(Saves, -1, sizeof(Saves)); // Define todos os parâmetros das structs em Save como 0. 
	
	// Para mais informações, veja: https://www.geeksforgeeks.org/memset-c-example/ ou https://gist.github.com/juniorcesarabreu/ff81bac6dd8510bcd1a816f270223168
	
	saveFile = abrirArquivo("./dados/saveFile.txt", "r");

	fscanf(saveFile,"Nome: %s Nivel: %d Experiencia: %d Ouro: %d HP: %d MP: %d Ataque: %d Defesa: %d Agilidade: %d Area: %d Checkpoint: %d Timestamp: %d", &save.personagem.nome, &save.personagem.lvl, &save.personagem.exp, &save.personagem.ouro, &save.personagem.hp, &save.personagem.mp, &save.personagem.ata, &save.personagem.def, &save.personagem.agi, &save.nivel, &save.checkpoint, &save.timestamp);

	printf("--------------------------------------------------\n");
	printf("Nome: %s Nivel: %d, Experiencia: %d, Ouro: %d, HP: %d, MP: %d, Ataque: %d\nDefesa: %d, Agilidade: %d\nÁrea: %d, Checkpoint: %d, Timestamp: %d\n", save.personagem.nome, save.personagem.lvl, save.personagem.exp, save.personagem.ouro, save.personagem.hp, save.personagem.mp, save.personagem.ata, save.personagem.def, save.personagem.agi, save.nivel, save.checkpoint, (((int) time(NULL) - save.timestamp) / 3600));
	printf("--------------------------------------------------\n");
}

void salvarJogo(Save *save) {
    FILE *saveFile = abrirArquivo(caminho_save, "w");

    fprintf(saveFile, "Nome: %s Nivel: %d Experiencia: %d Ouro: %d HP: %d MP: %d Ataque: %d Defesa: %d Agilidade: %d Area: %d Checkpoint: %d Timestamp: %d\n\n\n",
            save->personagem.nome, save->personagem.lvl, save->personagem.exp, save->personagem.ouro, save->personagem.hp, save->personagem.mp,
            save->personagem.ata, save->personagem.def, save->personagem.agi, save->nivel, save->checkpoint, save->timestamp);
    printf("Jogo salvo!");
    fclose(saveFile);
}