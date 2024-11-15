#include <stdio.h>
#include <stdlib.h>
#include "inimigos.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Função que exibe os status do inimigo comum
int ler_inimigo_comum(){ 
	
	inimigo_comum = abrirArquivo("./dados/inic_status.txt", "r");

	//Entrada de Dados via arquivo ".txt"
	fscanf(inimigo_comum, "%s %d %d %d %d %d %s",&inimigoComum.nome, &inimigoComum.hp, &inimigoComum.agi, &inimigoComum.def,
	 &inimigoComum.ata, &inimigoComum.mp, &inimigoComum.fraq);
	 
	//Exibição dos status na Tela
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("                STATUS DO SLIME                \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"); 
	printf("Nome: %s\nHP: %d\nAgilidade: %d\nDefesa: %d\nAtaque: %d\nMP: %d\nFraqueza: %s\n", inimigoComum.nome, inimigoComum.hp, inimigoComum.agi, 
	inimigoComum.def, inimigoComum.ata, inimigoComum.mp, inimigoComum.fraq);
	
	fclose(inimigo_comum);
	return 0;
}
//Função que exibe os status do inimigo elite
int ler_inimigo_elite(){
	
	
	inimigo_elite = abrirArquivo("./dados/inie_status.txt", "r");
	
	//Entrada de Dados via arquivo ".txt"
	fscanf(inimigo_elite, "%s %d %d %d %d %d %s %s\n",&inimigoElite.nome, &inimigoElite.hp, &inimigoElite.agi, &inimigoElite.def,
	 &inimigoElite.ata, &inimigoElite.mp, &inimigoElite.fraq, &inimigoElite.hab_esp);
	 
	//Exibição dos status na Tela 
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("          STATUS DO CAVALEIRO NEGRO            \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Nome: %s\nHP: %d\nAgilidade: %d\nDefesa: %d\nAtaque: %d\nMP: %d\nFraqueza: %s\nHabilidade especial: %s\n", 
	inimigoElite.nome, inimigoElite.hp, inimigoElite.agi, inimigoElite.def, inimigoElite.ata, inimigoElite.mp, inimigoElite.fraq, inimigoElite.hab_esp);
	
	fclose(inimigo_elite);
	return 0;
}

//Função que exibe os status do inimigo Boss
int ler_inimigo_boss(){
	
	inimigo_boss = abrirArquivo("./dados/inib_status.txt", "r");
	
	//Entrada de Dados via arquivo ".txt"
	fscanf(inimigo_boss, "%s %d %d %d %d %d %s %s %d\n",&inimigoBoss.nome, &inimigoBoss.hp, &inimigoBoss.agi, &inimigoBoss.def,
	 &inimigoBoss.ata, &inimigoBoss.mp, &inimigoBoss.fraq, &inimigoBoss.hab_esp, &inimigoBoss.regen);
	 
	//Exibição dos status na Tela 
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("            STATUS DO BOSS                     \n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Nome: %s\nHP: %d\nAgilidade: %d\nDefesa: %d\nAtaque: %d\nMP: %d\nFraqueza: %s\nHabilidade especial: %s\nRegeneração %d%%\n", 
	inimigoBoss.nome, inimigoBoss.hp, inimigoBoss.agi, inimigoBoss.def, inimigoBoss.ata, inimigoBoss.mp, inimigoBoss.fraq, inimigoBoss.hab_esp, inimigoBoss.regen);
	
	fclose(inimigo_boss);
	return 0;
	
}
//Apaga os dados salvos na struct de inimigo comum
int apa_inimigo_comum(){
	inimigo_comum = abrirArquivo("inic_status.txt", "w");
	
	fprintf(inimigo_comum,"Apagado\n0\n0\n0\n0\n0\nApagado\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("       Os status do SLIME foram apagados!\n");
	
	fclose(inimigo_comum);
	return 0;
}
//Apaga os dados salvos na struc de inimigo elite
int apa_inimigo_elite(){
	inimigo_elite = abrirArquivo("inie_status.txt", "w");
	
	fprintf(inimigo_elite,"Apagado\n0\n0\n0\n0\n0\nApagado\nApagado\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("  Os status do CAVALEIRO_NEGRO foram apagados!\n");
	
	fclose(inimigo_elite);
	return 0;
}
//Apaga os dados salvos na struct de inimigo boss
int apa_inimigo_boss(){
	inimigo_boss = abrirArquivo("inib_status.txt", "w");
	
	fprintf(inimigo_boss,"Apagado\n0\n0\n0\n0\n0\nApagado\nApagado\n0\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("       Os status do BOSS foram apagados!\n");
	
	fclose(inimigo_boss);
	return 0;
}
//Atualiza os status no arquivo .txt de inimigos comuns
int upd_inimigo_comum(){
inimigo_comum = abrirArquivo("inic_status.txt", "w");
	
	fprintf(inimigo_comum,"Slime_V2\n35\n12\n12\n8\n18\nFogo\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("     Os status do SLIME foram atualizados!\n");
	
	fclose(inimigo_comum);
	return 0;
}
//Atualiza os status no arquivo .txt de inimigos elite
int upd_inimigo_elite(){
	inimigo_elite = abrirArquivo("inie_status.txt", "w");
	
	fprintf(inimigo_elite,"Cavaleiro_Negro_V2\n55\n22\n22\n18\n12\nMagia\nCorte_Fantasma\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("   Os status do CAVALEIRO_NEGRO atualizados!\n");
	
	fclose(inimigo_elite);
	return 0;
}
//Atualiza os status no arquivo .txt do inimigo boss
int upd_inimigo_boss(){
inimigo_boss = abrirArquivo("inib_status.txt", "w");
	
	fprintf(inimigo_boss,"Vazio_V2\n160\n35\n45\n30\n35\nMagia\nToque_da_penumbra\n20\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        Os status do BOSS atualizados!\n");
	
	fclose(inimigo_boss);
	return 0;
}
//Cria um aqruivo .txt com os status do inimigo comum
int cri_inimigo_comum(){
inimigo_comum = abrirArquivo("inic_status.txt", "w");
	
	fprintf(inimigo_comum,"Slime\n30\n10\n10\n5\n15\nFogo\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("        O arquivo do SLIME foi criado!\n");
	
	fclose(inimigo_comum);
	return 0;
}
//Cria um arquivo .txt com os status do inimigo elite
int cri_inimigo_elite(){
inimigo_elite = abrirArquivo("inie_status.txt", "w");
	
	fprintf(inimigo_elite,"Cavaleiro_Negro\n50\n20\n20\n15\n10\nMagia\nCorte_Fantasma\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("   O arquiva do CAVALEIRO_NEGRO foi criado!\n");
	
	fclose(inimigo_elite);
	return 0;
}
//Cria um um arquivo .txt com os status do inimigo boss
int cri_inimigo_boss(){
inimigo_boss = abrirArquivo("inib_status.txt", "w");
	
	fprintf(inimigo_boss,"Vazio\n150\n30\n40\n25\n30\nMagia\nToque_da_penumbra\n15\n");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("           O arquivo do BOSS criado!\n");
	
	fclose(inimigo_boss);
	return 0;
}
