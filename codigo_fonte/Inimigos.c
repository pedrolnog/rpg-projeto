#include <stdio.h>
#include <stdlib.h>
#include "inimigos.h"
#include "ManipArquivos.h"

//Fun??o que exibe os status do inimigo comum
int inimigo_comum(){
	FILE *inimigoComum; // ponteiro dos status do inimigo comum
	ini_comum inic; 
	
	inimigoComum = abrirArquivo("./gameinfo/inic_status.txt", "r");

	//Entrada de Dados via arquivo ".txt"
	fscanf(inimigoComum, "%s %d %d %d %d %d %s\n", &inic.nome, &inic.hp, &inic.agi, &inic.def,
	 &inic.ata, &inic.mp, &inic.fraq);
	 
	//Exibi??o dos status na Tela
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("                STATUS DO SLIME                \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"); 
	printf("Nome: %s\nHP: %d\nAgilidade: %d\nDefesa: %d\nAtaque: %d\nMP: %d\nFraqueza: %s\n", inic.nome, inic.hp, inic.agi, 
	inic.def, inic.ata, inic.mp, inic.fraq);
	
	fclose(inimigoComum);
	system("pause");
	return 0;
}
//Fun??o que exibe os status do inimigo elite
int inimigo_elite(){
	FILE *inimigoElite; //Ponteiro dos status do inimigo elite
	ini_elite inie;
	
	inimigoElite = abrirArquivo("./gameinfo/inie_status.txt", "r");
	
	//Entrada de Dados via arquivo ".txt"
	fscanf(inimigoElite, "%s %d %d %d %d %d %s %s\n",&inie.nome, &inie.hp, &inie.agi, &inie.def,
	 &inie.ata, &inie.mp, &inie.fraq, &inie.hab_esp);
	 
	//Exibi??o dos status na Tela 
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("          STATUS DO CAVALEIRO NEGRO            \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Nome: %s\nHP: %d\nAgilidade: %d\nDefesa: %d\nAtaque: %d\nMP: %d\nFraqueza: %s\nHabilidade especial: %s\n", 
	inie.nome, inie.hp, inie.agi, inie.def, inie.ata, inie.mp, inie.fraq, inie.hab_esp);
	
	fclose(inimigoElite);
	system("pause");
	return 0;
}

//Fun??o que exibe os status do inimigo Boss

int inimigo_boss(){
	FILE *inimigoBoss;
	ini_boss inib;
	
	inimigoBoss = abrirArquivo("./gameinfo/inib_status.txt", "r");
	
	//Entrada de Dados via arquivo ".txt"
	fscanf(inimigoBoss, "%s %d %d %d %d %d %s %s %d\n",&inib.nome, &inib.hp, &inib.agi, &inib.def,
	 &inib.ata, &inib.mp, &inib.fraq, &inib.hab_esp, &inib.regen);
	 
	//Exibi??o dos status na Tela 
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("            STATUS DO BOSS                     \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Nome: %s\nHP: %d\nAgilidade: %d\nDefesa: %d\nAtaque: %d\nMP: %d\nFraqueza: %s\nHabilidade especial: %s\nRegenera??o %d%%\n", 
	inib.nome, inib.hp, inib.agi, inib.def, inib.ata, inib.mp, inib.fraq, inib.hab_esp, inib.regen);
	
	
	fclose(inimigoBoss);
	system("pause");
	return 0;
	
}







