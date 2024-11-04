#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "armas.h"
#define N 50
#define T 25
#define H 25
#define E 25

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



// Fun��o que mostra as informa��es da espada
void espadas(){
	FILE *ae;
	arma espada;
	
	
	ae = fopen("gameinfo/armas_espadas.txt", "r");
	if(ae == NULL){
		printf("ERROR!!!");
	}
	else{
	fscanf(ae, "%s %s %d %d %s %d %d %s", &espada.nome, &espada.tipoDano, &espada.danoMin, &espada.danoMax, &espada.habilidade, &espada.danoMinH, &espada.danoMaxH, &espada.efeito);
	
	
	printf("Dados da Arma \n");
	printf("nome: %s\nTipo de Dano: %s\nDano %d-%d\nHabilidade Especial: %s\nDano da Habilidade: %d-%d\nEfeito: %s\n\n", espada.nome, espada.tipoDano, espada.danoMin, espada.danoMax, espada.habilidade, espada.danoMinH, espada.danoMaxH, espada.efeito);
	
	fclose(ae);
	system("pause");
	}
}


void arcos(){
	FILE *aa;
	arma arco;
	
	
	aa = fopen("gameinfo/armas_arcos.txt", "r");
	if(aa == NULL){
		printf("ERROR!!!");
	}
	else{
	fscanf(aa, "%s %s %d %d %s %d %d %s", &arco.nome, &arco.tipoDano, &arco.danoMin, &arco.danoMax, &arco.habilidade, &arco.danoMinH, &arco.danoMaxH, &arco.efeito);
	
	
	printf("Dados da Arma \n");
	printf("nome: %s\nTipo de Dano: %s\nDano %d-%d\nHabilidade Especial: %s\nDano da Habilidade: %d-%d\nEfeito: %s\n\n", arco.nome, arco.tipoDano, arco.danoMin, arco.danoMax, arco.habilidade, arco.danoMinH, arco.danoMaxH, arco.efeito);
	
	fclose(aa);
	system("pause");
	}
}

void cajados(){
	FILE *ac;
	arma cajado;
	
	
	ac = fopen("gameinfo/armas_cajados.txt", "r");
	if(ac == NULL){
		printf("ERROR!!!");
	}
	else{
	fscanf(ac, "%s %s %d %d %s %d %d %s", &cajado.nome, &cajado.tipoDano, &cajado.danoMin, &cajado.danoMax, &cajado.habilidade, &cajado.danoMinH, &cajado.danoMaxH, &cajado.efeito);
	
	
	printf("Dados da Arma \n");
	printf("nome: %s\nTipo de Dano: %s\nDano %d-%d\nHabilidade Especial: %s\nDano da Habilidade: %d-%d\nEfeito: %s\n\n", cajado.nome, cajado.tipoDano, cajado.danoMin, cajado.danoMax, cajado.habilidade, cajado.danoMinH, cajado.danoMaxH, cajado.efeito);
	
	fclose(ac);
	system("pause");
	}
}

int ataque(/*se tiver algum buuff ele vai vim como parametro*/){
	srand(time(NULL));

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
