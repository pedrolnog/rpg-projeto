#include <stdio.h>
#include <stdlib.h>
#include "menuBatalha.h"
#include "savegame.h"
#include "inimigos.h"


batalhaSlime(){
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
heroi.hp = 30;

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
			inimigoComum.hp = ataquenoSlime();
			sleep(2);
			if(inimigoComum.hp == 0){
				printf("\n             !!!VOCE GANHOU!!!");
				printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
				break;
			}
			printf("\n       VEZ DO SLIME DO VAZIO\n");
			heroi.hp = ataqueSlime(heroi.hp);
			break;
			
		case 2:
			sleep(2);
			fugir(10, inimigoComum.agi);
			break;
			
		case 3:
			usar_item();
			ataqueSlime();
			break;
			
		case 4:
			bloquear(inimigoComum.ata);
			break; 
	}
	
}while(inimigoComum.hp > 0);

return 0;
}

batalhaElite(){
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
heroi.hp = 30;

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
			inimigoElite.hp = ataquenoCavaleiro();
			sleep(2);
			if(inimigoElite.hp == 0){
				printf("\n             !!!VOCE GANHOU!!!");
				printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
				break;
			}
			printf("\n       VEZ DO CAVALEIRO NEGRO\n");
			heroi.hp = ataqueCavaleiro(heroi.hp);
			break;
			
		case 2:
			sleep(2);
			fugir(10, inimigoElite.agi);
			break;
			
		case 3:
			usar_item();
			ataqueCavaleiro();
			break;
			
		case 4:
			bloquear(inimigoElite.ata);
			break; 
	}
	
}while(inimigoElite.hp > 0);

return 0;
}

batalhaBoss(){
int escolha;

printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("VOCE SENTE TODOS SEUS SENTIDOS GRITAREM PERIGO, ALGO TE ENCONTROU");	
printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");	
	
printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("\n  BATALHA CONTRA O VAZIO INICIADA!!  \n");
printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("	                        ####################           \n"
"        	            ########################  ##          \n"
"        	          #########################  #####        \n"
"        	        ###########################  #######      \n"
"	       	      #############################  #########    \n"
"        	    ##############################  ##########MM  \n"
"        	    ###############################  ###########  \n"
"        	  ################################   ###########mm\n"
"        	  ############      ############      ############\n"
"        	  ##########::  (O)  ###########        ##########\n"
"        	--############      ############       ###########\n"
"        	MM#################################  #############\n"
"        	mm##### ############################  ############\n"
"        	..#####    #########################  ############\n"
"        	  ########  ########################  #  #########\n"
"        	  #########     mm################       #########\n"
"        	  ##########      --############      ::########::\n"
"        	    #########                         ##########  \n"
"        	    #########  #--                m  #########::  \n"
"        	      ####### ######++        MM###  #########    \n"
"        	        ##### ##### #######  ####### #######      \n"
"        	          ###  ####  ###### ##############        \n"
"        	            M  ##### ###### ##########::          \n"
"                  	         mm################::    \n");
 
 
ler_inimigo_boss();
int quantidadePocao = 3;	
heroi.hp = 30;
	
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
			inimigoBoss.hp = ataquenoBoss();
			sleep(2);
			if(inimigoBoss.hp == 0){
				printf("\n             !!!VOCE GANHOU!!!");
				printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
				break;
			}
			printf("\n       VEZ DO VAZIO\n");
			heroi.hp = ataqueBoss(heroi.hp);
			break;
			
		case 2:
			sleep(2);
			fugir(10, inimigoBoss.agi);
			break;
			
		case 3:
			usar_item();
			ataqueBoss();
			break;
			
		case 4:
			bloquear(inimigoBoss.ata);
			break; 
	}
if(heroi.hp == 0){
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	pritnf("         VOCE NAO PODE MORRER... NAO AGORA        ");
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	heroi.hp = 30;
}
	
}while(inimigoBoss.hp > 0);

return 0;
}


