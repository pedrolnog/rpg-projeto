#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "savegame.h"
#include "armas.h"

typedef struct{
	int hpPotion;
	int mpPotion;
	int atkBooster;
	int defBooster;
	int agiBooster;
	Arma armas[3];
}Consumiveis;


void inventario(Personagem *MC);
void comprarItem(Consumiveis *itens, Personagem *MC);
void viewInventario(Consumiveis *itens);
void descartarItem(Consumiveis *itens, Personagem *MC);
void obterArma(Arma *arma, Consumiveis *itens);

FILE mcArquivo;
FILE itensARQ;

#endif
