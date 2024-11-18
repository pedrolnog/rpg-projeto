#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "inimigos.h"
#include "savegame.h"
#include "menuBatalha.h"

int ataquenoSlime(/*se tiver algum buuff ele vai vim como parametro*/){
	int ataque;
	srand(time(NULL));
	
	ataque = rand() % 20; 
	
	if(ataque < 3){ /* um erro critico nï¿½o pode ser afetado por buffs*/
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        VOCE TEVE UM ERRO CRITICO...             \n");
	printf("        E deu 0 de dano                            ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		upd_inimigo_comum();
		return inimigoComum.hp;
	}
	
	else if(ataque/*+possivel buff*/ <= 5 && ataque >= 3/*agilidade do inimigo(nesse caso slime)*/){
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O SLIME DO VAZIO DESVIOU...              \n");
	printf("        E perdeu 0 pontos de vida                  ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		upd_inimigo_comum();
		return inimigoComum.hp;
	}
	else if(ataque <= 6/*defesa do inimigo(nesse caso slime)*/){
	//	danoDoAtaque = rand() % (6 - 1 + 1) + 1;
	//	danoDoAtaque += rand() % (6 - 1 + 1) + 1;
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O SLIME DO  VAZIO DEFENDEU!!!            \n");
	printf("         tirou %d pontos de vida do slime      ", ataque);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	if((inimigoComum.hp - ataque ) <= 0){
	printf("       O SLIME DO VAZIO FOI NOCAUTEADO!!           ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoComum.hp = inimigoComum.hp - ataque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		
		upd_inimigo_comum();
		return inimigoComum.hp;
		
	}
	
	else if(ataque > 6 && ataque < 10){
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        VOCE ACERTOU!!!                          \n");
	printf("        E tirou %d pontos de vida do slime      ", ataque);
	printf("\n-----------------------------------------------\n");
	if((inimigoComum.hp - ataque ) <= 0){
	printf("       O SLIME DO VAZIO FOI NOCAUTEADO!!           ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoComum.hp = inimigoComum.hp - ataque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		
		upd_inimigo_comum();
		return inimigoComum.hp;
	}
	
	else if(ataque/*+possivel buff*/ >= 10){
	//	danoDoAtaque = rand() % (6 - 1 + 1) + 1;
	//	danoDoAtaque += rand() % (6 - 1 + 1) + 1;
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        VOCE ACERTOU!!!                          \n");
	printf("        E tirou %d pontos de vida do slime      ", ataque);
	printf("\n-----------------------------------------------\n");
	if((inimigoComum.hp - ataque ) <= 0){
	printf("       O SLIME DO VAZIO FOI NOCAUTEADO!!           ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoComum.hp = inimigoComum.hp - ataque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		
		upd_inimigo_comum();
		return inimigoComum.hp;
	}
	else if(ataque == 20){ /*um acerto critico nï¿½o pode depender de buffs*/
	//	danoDoAtaque = rand() % (6 - 1 + 1) + 1;
	//	danoDoAtaque += rand() % (6 - 1 + 1) + 1;
	//	danoDoAtaque *= 2; 
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=\n");
	printf("        VOCE ACERTOU UM ATAQUE CRITICO                 \n");
	printf("        E tirou %d pontos de vida do slime do vazio      ", 2 * ataque);
	printf("\n-----------------------------------------------------\n");
	if((inimigoComum.hp - ataque ) <= 0){
	printf("       O SLIME DO VAZIO FOI NOCAUTEADO!!           ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoComum.hp = inimigoComum.hp - ataque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		upd_inimigo_comum();
		return inimigoComum.hp;
	}
}

int ataqueSlime(){
    int ataque;
	int danoDoAtaque;
	srand(time(NULL));
	
	ataque = rand() % 10;
	
	if(ataque < 1)/* um erro critico nï¿½o pode ser afetado por buffs*/{ 
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O SLIME DO VAZIO TE ATACA...             \n");
	printf("        Ele errou o golpe                          ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	return heroi.hp;
	}
	
	else{
		ataque = ataque;
		heroi.hp = heroi.hp - ataque;
		sleep(2);
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("        O SLIME DO VAZIO TE ATACA...             \n");
		printf("        Ele te tirou %d pontos de vida             ",ataque);
		printf("\n-----------------------------------------------\n");
		printf("        Voce ainda tem %d pontos de vida           ",heroi.hp);
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		return heroi.hp;
	}

}

int bloquear(int danoDoSlime/*+bonus de buffs*/){ /*garante uma defesa*/
	int ataque;
	
	ataque = rand() % 5;
	
	ataque = ataque;
	heroi.hp = heroi.hp - ataque;
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("       VOCE DEFENDEU!!!                          \n");
	printf("       E conseguiu diminuir o dano para %d         ", ataque);
	printf("\n-----------------------------------------------\n");
	printf("        Voce ainda tem %d pontos de vida\n         ",heroi.hp);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	return heroi.hp;
}

int fugir(int agilidadeHeroi, int agilidadeInimigo){ //no caso do tutorial nï¿½o vai ter como escapar entï¿½o da pra so colocar uma mensagem dino combate.
	sleep(2);
	printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printf("           Voce nao consegue escapar!            ");
	printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		return 1;
	}

int usar_item(){
	int escolhaItem;
	int quantidadePocao = 999; //infinitas
	do{
	sleep(2);
	printf("MOCHILA:\n1.Pocao de Cura(%dx)\n5.Sair\n", quantidadePocao);
	scanf("%d", &escolhaItem);
	if(escolhaItem == 1){
		heroi.hp = heroi.hp + 10;
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("                +10 HP RESTAURADO                 ");
		printf("\n-----------------------------------------------\n");
		printf("            Voce tem %d pontos de vida\n           ",heroi.hp);
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	}
	} while(escolhaItem != 1 && escolhaItem != 5);

	return escolhaItem;
}


int ataquenoCavaleiro(/*se tiver algum buuff ele vai vim como parametro*/){
	int ataque;
	int danoDoAtaque;
	srand(time(NULL));
	
	ataque = rand() % 20; 
	
	if(ataque < 3){ /* um erro critico nï¿½o pode ser afetado por buffs*/
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        VOCE TEVE UM ERRO CRITICO...             \n");
	printf("        E deu 0 de dano                            ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		upd_inimigo_elite();
		return inimigoElite.hp;
	}
	
	else if(ataque/*+possivel buff*/ <= 5 && ataque >= 3/*agilidade do inimigo(nesse caso o Cavaleiro)*/){
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("       O CAVALEIRO NEGRO DESVIOU                 \n");
	printf("       E perdeu 0 pontos de vida                  ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		upd_inimigo_elite();
		return inimigoElite.hp;
	}
	else if(ataque <= 6/*defesa do inimigo(nesse caso cavaleiro)*/){
	//	danoDoAtaque = rand() % (6 - 1 + 1) + 1;
	//	danoDoAtaque += rand() % (6 - 1 + 1) + 1;
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O CAVALEIRO NEGRO DEFENDEU!!!            \n");
	printf("        Mas perdeu %d pontos de vida               ", ataque);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	if((inimigoElite.hp - ataque ) <= 0){
	printf("       O CAVALEIRO NEGRO FOI NOCAUTEADO!!           ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoElite.hp = inimigoElite.hp - ataque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
		
		upd_inimigo_elite();
		return inimigoComum.hp;
		
	}
	
	else if(ataque > 6 && ataque < 10){
	danoDoAtaque = ataque;
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        VOCE ACERTOU!!!                          \n");
	printf("        E tirou %d pontos de vida do cavaleiro     ", ataque);
	printf("\n-----------------------------------------------\n");
	if((inimigoElite.hp - ataque ) <= 0){
	printf("       O CAVALEIRO NEGRO FOI NOCAUTEADO!!          ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoElite.hp = inimigoElite.hp - ataque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		
		upd_inimigo_elite();
		return inimigoElite.hp;
	}
	
	else if(ataque/*+possivel buff*/ >= 10){
	//	danoDoAtaque = rand() % (6 - 1 + 1) + 1;
	//	danoDoAtaque += rand() % (6 - 1 + 1) + 1;
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        VOCE ACERTOU!!!                          \n");
	printf("        E tirou %d pontos de vida do cavaleiro     ", ataque);
	printf("\n-----------------------------------------------\n");
	if((inimigoElite.hp - ataque ) <= 0){
	printf("       O CAVALEIRO NEGRO FOI NOCAUTEADO!!          ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoElite.hp = inimigoElite.hp - ataque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		
		upd_inimigo_elite();
		return inimigoElite.hp;
	}
	else if(ataque == 20){ /*um acerto critico nï¿½o pode depender de buffs*/
	//	danoDoAtaque = rand() % (6 - 1 + 1) + 1;
	//	danoDoAtaque += rand() % (6 - 1 + 1) + 1;
	//	danoDoAtaque *= 2; 
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=\n");
	printf("        VOCE ACERTOU UM ATAQUE CRITICO                 \n");
	printf("        E tirou %d pontos de vida do cavaleiro negro     ", 2 * ataque);
	printf("\n-----------------------------------------------------\n");
	if((inimigoElite.hp - ataque ) <= 0){
	printf("       O CAVALEIRO NEGRO FOI NOCAUTEADO!!          ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoElite.hp = inimigoElite.hp - ataque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		upd_inimigo_elite();
		return inimigoElite.hp;
	}
}

int ataqueCavaleiro(){
    int ataque;
	int danoDoAtaque;
	srand(time(NULL));
	
	ataque = rand() % 15;
	
	if(ataque < 1)/* um erro critico nï¿½o pode ser afetado por buffs*/{ 
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O CAVALEIRO NEGRO TE ATACA...            \n");
	printf("        Ele errou o golpe                          ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	return heroi.hp;
	}
	else if(ataque == 15){
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("        O CAVALEIRO NEGRO TE ATACA...            \n");
		printf("        ELE USA O CORTE FANTASMA!!!!             \n");
		printf("\n-----------------------------------------------\n");
		printf("        Voce ainda tem %d pontos de vida           ",heroi.hp);
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	}
	else{
		ataque = ataque;
		heroi.hp = heroi.hp - ataque;
		sleep(2);
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("        O CAVALEIRO NEGRO TE ATACA...            \n");
		printf("        Ele te tirou %d pontos de vida             ",ataque);
		printf("\n-----------------------------------------------\n");
		printf("        Voce ainda tem %d pontos de vida           ",heroi.hp);
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		return heroi.hp;
	}

}
