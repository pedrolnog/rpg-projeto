#include <stdio.h>
#include <stdlib.h>
#include "inimigos.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Função que exibe os status do inimigo comum
int ler_inimigo_comum(){ 
	
	ic = fopen("inic_status.txt", "r");
	if(ic==NULL){
		printf("ERRO!\n");
		return 0;
	} 
	//Entrada de Dados via arquivo ".txt"
	fscanf(ic, "%s %d %d %d %d %d %s",&inic.nome, &inic.hp, &inic.agi, &inic.def,
	 &inic.ata, &inic.mp, &inic.fraq);
	 
	//Exibição dos status na Tela
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("                STATUS DO SLIME                \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"); 
	printf("Nome: %s\nHP: %d\nAgilidade: %d\nDefesa: %d\nAtaque: %d\nMP: %d\nFraqueza: %s\n", inic.nome, inic.hp, inic.agi, 
	inic.def, inic.ata, inic.mp, inic.fraq);
	
	fclose(ic);
	return 0;
}
//Função que exibe os status do inimigo elite
int ler_inimigo_elite(){
	
	
	ie = fopen("inie_status.txt", "r");
	if(ie == NULL){
		printf("ERRO!");
		return 0;
	}
	
	//Entrada de Dados via arquivo ".txt"
	fscanf(ie, "%s %d %d %d %d %d %s %s\n",&inie.nome, &inie.hp, &inie.agi, &inie.def,
	 &inie.ata, &inie.mp, &inie.fraq, &inie.hab_esp);
	 
	//Exibição dos status na Tela 
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("          STATUS DO CAVALEIRO NEGRO            \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Nome: %s\nHP: %d\nAgilidade: %d\nDefesa: %d\nAtaque: %d\nMP: %d\nFraqueza: %s\nHabilidade especial: %s\n", 
	inie.nome, inie.hp, inie.agi, inie.def, inie.ata, inie.mp, inie.fraq, inie.hab_esp);
	
	fclose(ie);
	return 0;
}

//Função que exibe os status do inimigo Boss
int ler_inimigo_boss(){
	
	ib = fopen("inib_status.txt", "r");
	if(ib == NULL){
		printf("O programa foi de F");
		return 0;
	}
	
	//Entrada de Dados via arquivo ".txt"
	fscanf(ib, "%s %d %d %d %d %d %s %s %d\n",&inib.nome, &inib.hp, &inib.agi, &inib.def,
	 &inib.ata, &inib.mp, &inib.fraq, &inib.hab_esp, &inib.regen);
	 
	//Exibição dos status na Tela 
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("            STATUS DO BOSS                     \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Nome: %s\nHP: %d\nAgilidade: %d\nDefesa: %d\nAtaque: %d\nMP: %d\nFraqueza: %s\nHabilidade especial: %s\nRegeneração %d%%\n", 
	inib.nome, inib.hp, inib.agi, inib.def, inib.ata, inib.mp, inib.fraq, inib.hab_esp, inib.regen);
	
	fclose(ib);
	return 0;
	
}
//Apaga os dados salvos na struct de inimigo comum
int apa_inimigo_comum(){
	ic = fopen("inic_status.txt", "w");
	if(ic == NULL){
		printf("ERRO!\n");
	}
	else{
	fprintf(ic,"Apagado\n0\n0\n0\n0\n0\nApagado\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("       Os status do SLIME foram apagados!\n");
	}
	fclose(ic);
	return 0;
}
//Apaga os dados salvos na struc de inimigo elite
int apa_inimigo_elite(){
	ie = fopen("inie_status.txt", "w");
	if(ie == NULL){
		printf("ERRO!\n");
	}
	else{
	fprintf(ie,"Apagado\n0\n0\n0\n0\n0\nApagado\nApagado\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("  Os status do CAVALEIRO_NEGRO foram apagados!\n");
	}
	fclose(ie);
	return 0;
}
//Apaga os dados salvos na struct de inimigo boss
int apa_inimigo_boss(){
	ib = fopen("inib_status.txt", "w");
	if(ib == NULL){
		printf("ERRO!\n");
	}
	else{
	fprintf(ib,"Apagado\n0\n0\n0\n0\n0\nApagado\nApagado\n0\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("       Os status do BOSS foram apagados!\n");
	}
	fclose(ib);
	return 0;
}
//Atualiza os status no arquivo .txt de inimigos comuns
int upd_inimigo_comum(){
ic = fopen("inic_status.txt", "w");
	if(ic == NULL){
		printf("ERRO!\n");
	}
	else{
	fprintf(ic,"Slime_V2\n35\n12\n12\n8\n18\nFogo\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("     Os status do SLIME foram atualizados!\n");
	}
	fclose(ic);
	return 0;
}
//Atualiza os status no arquivo .txt de inimigos elite
int upd_inimigo_elite(){
	ie = fopen("inie_status.txt", "w");
	if(ie == NULL){
		printf("ERRO!\n");
	}
	else{
	fprintf(ie,"Cavaleiro_Negro_V2\n55\n22\n22\n18\n12\nMagia\nCorte_Fantasma\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("   Os status do CAVALEIRO_NEGRO atualizados!\n");
	}
	fclose(ie);
	return 0;
}
//Atualiza os status no arquivo .txt do inimigo boss
int upd_inimigo_boss(){
ib = fopen("inib_status.txt", "w");
	if(ib == NULL){
		printf("ERRO!\n");
	}
	else{
	fprintf(ib,"Vazio_V2\n160\n35\n45\n30\n35\nMagia\nToque_da_penumbra\n20\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        Os status do BOSS atualizados!\n");
	}
	fclose(ib);
	return 0;
}
//Cria um aqruivo .txt com os status do inimigo comum
int cri_inimigo_comum(){
ic = fopen("inic_status.txt", "w");
	if(ic == NULL){
		printf("ERRO!\n");
	}
	else{
	fprintf(ic,"Slime\n30\n10\n10\n5\n15\nFogo\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O arquivo do SLIME foi criado!\n");
	}
	fclose(ic);
	return 0;
}
//Cria um arquivo .txt com os status do inimigo elite
int cri_inimigo_elite(){
ie = fopen("inie_status.txt", "w");
	if(ie == NULL){
		printf("ERRO!\n");
	}
	else{
	fprintf(ie,"Cavaleiro_Negro\n50\n20\n20\n15\n10\nMagia\nCorte_Fantasma\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("   O arquiva do CAVALEIRO_NEGRO foi criado!\n");
	}
	fclose(ie);
	return 0;
}
//Cria um um arquivo .txt com os status do inimigo boss
int cri_inimigo_boss(){
ib = fopen("inib_status.txt", "w");
	if(ib == NULL){
		printf("ERRO!\n");
	}
	else{
	fprintf(ib,"Vazio\n150\n30\n40\n25\n30\nMagia\nToque_da_penumbra\n15\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("           O arquivo do BOSS criado!\n");
	}
	fclose(ib);
	return 0;
}
