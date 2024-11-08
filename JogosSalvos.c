#include "JogosSalvos.h"
#include "NewGame.h"
#include "ManipArquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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