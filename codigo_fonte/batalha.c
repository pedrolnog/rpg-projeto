#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "inimigos.h"
#include "savegame.h"
#include "menuBatalha.h"

int ataquenoSlime(Save *save, ini_comum inimigoComum){ // tirar upd // Juntar com a arma // Fazer o dano funcional
	int ataque;
	int danoDoAtaque;
	srand(time(NULL));
	
	ataque = rand() % (20 - 1 + 1) + 1; 
	danoDoAtaque = rand() % (16 - 5 + 1) + 5;
	
	if(ataque == 1){ /* um erro critico nÃ¯Â¿Â½o pode ser afetado por buffs*/
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        VOCE TEVE UM ERRO CRITICO...             \n");
	printf("        E deu 0 de dano                            ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		upd_inimigo_comum();
		return inimigoComum.hp;
	}
	
	else if(ataque + save->personagem.ata <= inimigoComum.agi){/*agilidade do inimigo(nesse caso slime)*/
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O SLIME DO VAZIO DESVIOU...              \n");
	printf("        E perdeu 0 pontos de vida                  ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		upd_inimigo_comum();
		return inimigoComum.hp;
	}
	else if(ataque + save->personagem.ata <= inimigoComum.def){/*defesa do inimigo(nesse caso slime)*/
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O SLIME DO  VAZIO DEFENDEU!!!            \n");
	printf("Seu ataque oscila e o slime perde %d pontos de vida", danoDoAtaque - 2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	
	if((inimigoComum.hp - danoDoAtaque + 2) <= 0){
	printf("       O SLIME DO VAZIO FOI NOCAUTEADO!!           ");
	return 0;
	}
	else{
	inimigoComum.hp = inimigoComum.hp - danoDoAtaque + 2;
	printf("        Ele ainda tem %d pontos de vida            ", inimigoComum.hp);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		
		upd_inimigo_comum();
		return inimigoComum.hp;
		
	}
	
	else if(ataque + save->personagem.ata > inimigoComum.def){
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        VOCE ACERTOU!!!                          \n");
	printf("        E tirou %d pontos de vida do slime      ", danoDoAtaque);
	printf("\n-----------------------------------------------\n");
	if((inimigoComum.hp - danoDoAtaque) <= 0){
	printf("       O SLIME DO VAZIO FOI NOCAUTEADO!!           ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoComum.hp = inimigoComum.hp - danoDoAtaque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		
		upd_inimigo_comum();
		return inimigoComum.hp;
	}
	
	else if(ataque == 20){ /*um acerto critico nÃ¯Â¿Â½o pode depender de buffs*/
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=\n");
	printf("        VOCE ACERTOU UM ATAQUE CRITICO                 \n");
	printf("        E tirou %d pontos de vida do slime do vazio      ", 2 * danoDoAtaque);
	printf("\n-----------------------------------------------------\n");
	if((inimigoComum.hp - danoDoAtaque ) <= 0){
	printf("       O SLIME DO VAZIO FOI NOCAUTEADO!!           ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoComum.hp = inimigoComum.hp - danoDoAtaque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		upd_inimigo_comum();
		return inimigoComum.hp;
	}
}

int ataqueSlime(Save *heroi){ // TUDO OK!
    int ataque;
	int danoDoAtaque;
	srand(time(NULL));
	danoDoAtaque = rand() % (8 - 4 + 1) + 4;
	ataque = rand() % (20 - 1 + 1) + 1; 
	
	if(ataque == 1)/* um erro critico nÃ¯Â¿Â½o pode ser afetado por buffs*/{ 
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O SLIME DO VAZIO TE ATACA...             \n");
	printf("        Ele errou o golpe                          ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	return heroi->personagem.hp;
	}
	
	else if(ataque <= (heroi->personagem.agi)/2){
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O SLIME DO VAZIO TE ATACA...             \n");
	printf("        voce desvia do golpe                       ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	return heroi->personagem.hp;
	}

	else if(ataque <= heroi->personagem.def){
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("        O SLIME DO VAZIO TE ATACA...             \n");
	printf("O ataque foi fraco, mas voce ainda perde %d pontos de vida",danoDoAtaque - 1);
	printf("\n--------------------------------------------------------\n");
	heroi->personagem.hp = heroi->personagem.hp - danoDoAtaque  + 1;
	printf("        Voce ainda tem %d pontos de vida           ",heroi->personagem.hp);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	
	return heroi->personagem.hp;
	}

	else if(ataque > heroi->personagem.def){
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O SLIME DO VAZIO TE ATACA...             \n");
	printf("        Ele te tirou %d pontos de vida             ",danoDoAtaque);
	printf("\n-----------------------------------------------\n");
	heroi->personagem.hp = heroi->personagem.hp - danoDoAtaque;
	printf("        Voce ainda tem %d pontos de vida           ",heroi->personagem.hp);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	return heroi->personagem.hp;
	}
}

int bloquear(Save *heroi, ini_comum inimigoComum){ /*garante uma defesa*/
	int ataque;
	
	ataque = rand() % 3;
	heroi->personagem.hp = heroi->personagem.hp - ataque;
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("       VOCE DEFENDEU!!!                          \n");
	printf("       E conseguiu diminuir o dano para %d         ", ataque);
	printf("\n-----------------------------------------------\n");
	printf("        Voce ainda tem %d pontos de vida\n         ",heroi->personagem.hp);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	return heroi->personagem.hp;
}
int bloquearElite(Save *heroi, ini_comum inimigoElite){ /*garante uma defesa*/
	int ataque;
	
	ataque = rand() % 8;
	heroi->personagem.hp = heroi->personagem.hp - ataque;
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("       VOCE DEFENDEU!!!                          \n");
	printf("       E conseguiu diminuir o dano para %d         ", ataque);
	printf("\n-----------------------------------------------\n");
	printf("        Voce ainda tem %d pontos de vida\n         ",heroi->personagem.hp);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	return heroi->personagem.hp;
}

int fugir(){ //Colocar .
	sleep(2);
	printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	printf("           Voce nao consegue escapar!            ");
	printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		return 1;
	}

int usar_item(Save *save){
	int escolhaItem;
	int quantidadePocao = 999; //infinitas
	do{
	sleep(2);
	printf("MOCHILA:\n1.Pocao de Cura(%dx)\n5.Sair\n", quantidadePocao);
	scanf("%d", &escolhaItem);
	if(escolhaItem == 1){
		save->personagem.hp = save->personagem.hp + 10;
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("                +10 HP RESTAURADO                 ");
		printf("\n-----------------------------------------------\n");
		printf("            Voce tem %d pontos de vida\n           ",save->personagem.hp);
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	}
	} while(escolhaItem != 1 && escolhaItem != 5);

	return escolhaItem;
}


int ataquenoCavaleiro(Save *save, ini_comum inimigoComum){
	int ataque;
	int danoDoAtaque;
	srand(time(NULL));
	danoDoAtaque = rand() % (16 - 5 + 1) + 5;
	ataque = rand() % (20 - 1 + 1) + 1; 
	if(ataque == 1){ /* um erro critico nÃ¯Â¿Â½o pode ser afetado por buffs*/
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        VOCE TEVE UM ERRO CRITICO...             \n");
	printf("        E deu 0 de dano                            ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		upd_inimigo_elite();
		return inimigoElite.hp;
	}
	
	else if(ataque + save->personagem.ata <= inimigoElite.agi){/*agilidade do inimigo(nesse caso slime)*/
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O CAVALEIRO NEGRO DESVIOU                \n");
	printf("        E perdeu 0 pontos de vida                  ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		upd_inimigo_elite();
		return inimigoElite.hp;
	}
	else if(ataque + save->personagem.ata <= inimigoElite.def){/*defesa do inimigo(nesse caso slime)*/
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O CAVALEIRO NEGRO DEFENDEU!!!            \n");
	printf("        Mas perdeu %d pontos de vida               ", danoDoAtaque - 3);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	if((inimigoElite.hp - danoDoAtaque + 3) <= 0){
	printf("        O CAVALEIRO NEGRO FOI NOCAUTEADO!!         ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoElite.hp = inimigoElite.hp - danoDoAtaque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		
		upd_inimigo_elite();
		return inimigoElite.hp;
		
	}
	
	else if(ataque + save->personagem.ata > inimigoElite.def){
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        VOCE ACERTOU!!!                          \n");
	printf("    E tirou %d pontos de vida do Cavaleiro Negro   ", danoDoAtaque);
	printf("\n-----------------------------------------------\n");
	if((inimigoElite.hp - danoDoAtaque ) <= 0){
	printf("       O CAVALEIRO NEGRO FOI NOCAUTEADO!!          ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoElite.hp = inimigoElite.hp - danoDoAtaque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		
		upd_inimigo_elite();
		return inimigoElite.hp;
	}
	
	else if(ataque == 20){ /*um acerto critico nÃ¯Â¿Â½o pode depender de buffs*/
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=\n");
	printf("        VOCE ACERTOU UM ATAQUE CRITICO                 \n");
	printf("        E tirou %d pontos de vida do Cavaleiro Negro     ", 2 * danoDoAtaque);
	printf("\n-----------------------------------------------------\n");
	if((inimigoElite.hp - danoDoAtaque ) <= 0){
	printf("       O SLIME DO VAZIO FOI NOCAUTEADO!!           ");
	return 0;
	}
	else{
	printf("        Ele ainda tem %d pontos de vida            ", inimigoElite.hp = inimigoElite.hp - danoDoAtaque);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		upd_inimigo_elite();
		return inimigoElite.hp;
	}
}

int ataqueCavaleiro(Save *save){
    int ataque;
	int danoDoAtaque;
	srand(time(NULL));
	danoDoAtaque = rand() % (12 - 4 + 1) + 4;
	ataque = rand() % (20 - 1 + 1) + 1; 
	
	if(ataque == 1)/* um erro critico nÃ¯Â¿Â½o pode ser afetado por buffs*/{ 
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O CAVALEIRO NEGRO TE ATACA...            \n");
	printf("        Ele errou o golpe                          ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	return save->personagem.hp;
	}
	
	else if(ataque <= (save->personagem.agi)/2){
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O CAVALEIRO NEGRO TE ATACA...            \n");
	printf("        voce desvia do golpe                       ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	return save->personagem.hp;
	}

	else if(ataque <= save->personagem.def){
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=\n");
	printf("        O CAVALEIRO NEGRO TE ATACA...            \n");
	printf("O ataque foi fraco, mas voce ainda perde %d pontos de vida",danoDoAtaque - 2);
	printf("\n---------------------------------------------------------\n");
	save->personagem.hp = save->personagem.hp - danoDoAtaque  + 2;
	printf("        Voce ainda tem %d pontos de vida           ",save->personagem.hp);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	return save->personagem.hp;
	}

	else if(ataque > save->personagem.def){
	sleep(2);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O CAVALEIRO NEGRO TE ATACA...            \n");
	printf("        Ele te tirou %d pontos de vida             ",danoDoAtaque);
	printf("\n-----------------------------------------------\n");
	save->personagem.hp = save->personagem.hp - danoDoAtaque;
	printf("        Voce ainda tem %d pontos de vida           ",save->personagem.hp);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	return save->personagem.hp;
	}

}
