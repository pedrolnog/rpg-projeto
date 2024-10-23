#include <stdio.h>
#include <stdlib.h>
#include "JogosSalvos.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct save {
	int timestamp;
	int nivel;
	int zona;
	int checkpoint;
};

void jogosSalvos() {
	struct save save1;
	struct save Saves[10];
	int i;
	
	printf("[ JOGOS SALVOS ]");
	for (i = 0; i < (sizeof(Saves) / sizeof(Saves[0])); i++) {
		printf("%d. Zona %d", i+1, Saves[i].zona);
	}
	
}
