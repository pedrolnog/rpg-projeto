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

void jogosSalvos() {
	Save save;
	FILE *saveFile;

	// memset(Saves, -1, sizeof(Saves)); // Define todos os parâmetros das structs em Save como 0. 
	
	// Para mais informações, veja: https://www.geeksforgeeks.org/memset-c-example/ ou https://gist.github.com/juniorcesarabreu/ff81bac6dd8510bcd1a816f270223168
	
	saveFile = abrirArquivo("./gameinfo/saveFile.txt", "r");

	fscanf(saveFile,"Nome: %s Nivel: %d, Experiencia: %d, Ouro: %d, HP: %d, MP: %d, Ataque: %d, Defesa: %d, Agilidade: %d, Área: %d, Checkpoint: %d, Timestamp: %d", &save.personagem.nome, &save.personagem.lvl, &save.personagem.exp, &save.personagem.ouro, &save.personagem.hp, &save.personagem.mp, &save.personagem.ata, &save.personagem.def, &save.personagem.agi, &save.nivel, &save.checkpoint, &save.timestamp);

	printf("--------------------------------------------------\n");
	printf("Nome: %s Nivel: %d, Experiencia: %d, Ouro: %d, HP: %d, MP: %d, Ataque: %d\nDefesa: %d, Agilidade: %d\nÁrea: %d, Checkpoint: %d, Timestamp: %d\n", save.personagem.nome, save.personagem.lvl, save.personagem.exp, save.personagem.ouro, save.personagem.hp, save.personagem.mp, save.personagem.ata, save.personagem.def, save.personagem.agi, save.nivel, save.checkpoint, (((int) time(NULL) - save.timestamp) / 3600));
	printf("--------------------------------------------------\n");

	/* Imprimindo todos os jogos salvos. Utiliza um loop que se mantém enquanto i é menor que a quantidade de itens em Saves.
	printf("[ JOGO SALVOS ]\n");
	for (i = 0; i < (sizeof(Saves) / sizeof(Saves[0])); i++) {
		if (!(Saves[i].timestamp = -1)) {
			printf("%d - Checkpoint %d\n", i+1, Saves[i].checkpoint);
		} else {
			printf("%d - ESPACO VAZIO\n", i+1);
			continue;
		}
	}
	*/
}