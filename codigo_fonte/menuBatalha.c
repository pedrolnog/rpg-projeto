#include <stdio.h>
#include <stdlib.h>
#include "menuBatalha.h"
#include "savegame.h"
#include "inimigos.h"
#include "batalha.h"
int batalhaSlime(Save *save){
int escolha;

printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("\n  BATALHA CONTRA O SLIME DO VAZIO INICIADA!!  \n");
printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("               #######              \n"  
 "          #################         \n"
 "       ######################       \n" 
 "      ###### ##################     \n" 
 "    ##### #######  ######  #####    \n" 
 "   ####  #########  ###### ######   \n"  
 "   #### ##########################  \n" 
 "   ###############################  \n"  
 "   ###############################  \n"  
 "   ##############################   \n"  
 "    ############################    \n"  
 "       #######################      \n"  
 "            #############           \n");
 
 
ler_inimigo_comum();
int quantidadePocao = 3;	


sleep(2);
do{
printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("         ESCOLHA O QUE GOSTARIA DE FAZER          ");
printf("\n------------------------------------------------\n");
printf("\n       \\ 1.ATACAR \\   \\  2.FUGIR \\        \n");
printf("\n      \\  3.ITEM  \\   \\ 4. BLOQUEAR \\      \n");
printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
scanf("%d", &escolha);
switch(escolha){
		case 1:
			inimigoComum.hp = ataquenoSlime(save, inimigoComum);
			sleep(2);
			if(inimigoComum.hp == 0){
				printf("\n             !!!VOCE GANHOU 30XP!!!");
				printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
				break;
			}
			printf("\n       VEZ DO SLIME DO VAZIO\n");
			save->personagem.hp = ataqueSlime(save, inimigoComum);
			break;
			
		case 2:
			sleep(2);
			fugir(save, inimigoComum);
			break;
			
		case 3:
			usar_item(save);
			ataqueSlime(save, inimigoComum);
			break;
			
		case 4:
			printf("||||%p||||", save);
			bloquear(save, inimigoComum);
			break; 
	}
	
}while(inimigoComum.hp > 0);

return 0;
}

int batalhaElite(Save *save){
int escolha;

printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("\n  BATALHA CONTRA O CAVALEIRO NEGRO INICIADA!! \n");
printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("                                                 \n"                                                                                      
"                     ## ##                              \n"
"                  ####  ####                            \n" 
"                 #   # ##  ##               			 \n"
"      #          #   #   #   ##              			 \n"
"      ###      ### # ##  #  # ##             			 \n"
"     ## ##     ### ###   #######             			 \n"
"     ##  #      ##   ##  ##   #              			 \n"
"      #  ##     #    ##  #    ##             		   	 \n"
"      ##  #      ##        #########         			 \n"
"       #   #     #########################   			 \n"
"        #  #   # ##   ######          ####   			 \n"
"        #  #########  # #             # ##   			 \n"	
"     ####  ####  # ####  #          ### ##   			 \n"
"     ### ####   ##  ### ##      ##  # ####   		 	 \n"
"         #  #  ######## ##    # #   # ###    			 \n"
"          ## ## #  #  ## # #       # # ##   			 \n"
"           #### ##   ###  #  #   ## # ##     			 \n"
"            ##  #      #####   ### # ##      			 \n"
"               #############     # ##       			 \n"
"               ##     #   ####  ####        			 \n"
"                ##    ##    #######          			 \n"
"               #      #      # ##            			 \n"
"            #########################        			 \n");
 
 
ler_inimigo_elite();
int quantidadePocao = 3;	
save->personagem.hp = 30;

sleep(2);
do{
printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("         ESCOLHA O QUE GOSTARIA DE FAZER          ");
printf("\n------------------------------------------------\n");
printf("\n       \\ 1.ATACAR \\   \\  2.FUGIR \\        \n");
printf("\n      \\  3.ITEM  \\   \\ 4. BLOQUEAR \\      \n");
printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
scanf("%d", &escolha);
switch(escolha){
		case 1:
			inimigoElite.hp = ataquenoCavaleiro(save, inimigoComum);
			sleep(2);
			if(inimigoElite.hp == 0){
				printf("\n             !!!VOCE GANHOU!!!");
				printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
				break;
			}
			printf("\n       VEZ DO CAVALEIRO NEGRO\n");
			save->personagem.hp = ataqueCavaleiro(save);
			break;
		case 2:
			sleep(2);
			fugir();
			break;
			
		case 3:
			usar_item(save);
			ataqueCavaleiro(save);
			break;
			
		case 4:
			bloquearElite(save, inimigoElite);
			break; 
	}
	
}while(inimigoElite.hp > 0);

return 0;
}
