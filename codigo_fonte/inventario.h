#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "savegame.h"

typedef struct{
	int hpPotion;
	int mpPotion;
	int atkBooster;
	int defBooster;
	int agiBooster;
}Consumiveis;


void inventario(Personagem *MC);
void comprarItem(Consumiveis *itens, Personagem *MC);
void viewInventario(Consumiveis *itens);
void descartarItem(Consumiveis *itens, Personagem *MC);

FILE mcArquivo;
FILE itensARQ;

#endif