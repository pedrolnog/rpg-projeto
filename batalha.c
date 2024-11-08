#include <stdio.h>
#include <stdlib.h>
#include "inimigos.h"

int ataque(/*se tiver algum buuff ele vai vim como parametro*/){
	// srand(time(NULL));

	int ataque;
	int danoDoAtaque;
	
	ataque = rand() % (20 - 1 + 1) + 1; //gera um numero aleatorio entre 1 e 20 que decidir� se o golpe ira acertar o inimigo ou n�o
	
	if(ataque == 1){ /* um erro critico n�o pode ser afetado por buffs*/
		printf("Voce errou o ataque. \n");
		return 0;
	}
	else if(ataque/*+possivel buff*/ <= 10/*agilidade do inimigo(nesse caso slime)*/){
		printf("o Slime desviou do ataque.\n");
		return 0;
	}
	else if(ataque <= 10/*defesa do inimigo(nesse caso slime)*/){
		danoDoAtaque = rand() % (6 - 1 + 1) + 1;
		danoDoAtaque += rand() % (6 - 1 + 1) + 1;
		danoDoAtaque = danoDoAtaque/2;
		printf("O Slime defendeu o seu ataque e portanto so recebeu %d de dano!\n");
		return danoDoAtaque;
	}
	else if(ataque/*+possivel buff*/ > 10){
		danoDoAtaque = rand() % (6 - 1 + 1) + 1;
		danoDoAtaque += rand() % (6 - 1 + 1) + 1;
		printf("Voce acertou e causou %d de dano no Slime!\n", danoDoAtaque);
		return danoDoAtaque;
	}
	else if(ataque == 20){ /*um acerto critico n�o pode depender de buffs*/
		danoDoAtaque = rand() % (6 - 1 + 1) + 1;
		danoDoAtaque += rand() % (6 - 1 + 1) + 1;
		danoDoAtaque *= 2; 
		printf("Voce acertou um golpe critico e causou %d de dano no Slime!\n", danoDoAtaque);
		return danoDoAtaque;
	}
}

int bloquear(int danoDoSlime/*+bonus de buffs*/){ /*garante uma defesa*/
	return danoDoSlime/2 /*+buff, para reduzir ainda mais o dano*/;
}

int fugir(int agilidadeHeroi, int agilidadeInimigo){ //no caso do tutorial n�o vai ter como escapar ent�o da pra so colocar uma mensagem dizendo que algo prende ele no combate.
	if(agilidadeHeroi/*+buff*/ > agilidadeInimigo){
		printf("Voce escapou com sucesso!\n");
		return 0;
	}
	else{
		printf("Voce nao consegue escapar!\n");
		return 1;
	}
}

int usar_item(){
	int escolhaItem;
	do{
	printf("MOCHILA:\n1.Pocao de Cura(3x)\n5.Sair\n");
	scanf("%d", &escolhaItem);
	} while(escolhaItem != 1 && escolhaItem != 5);

	return escolhaItem;
}