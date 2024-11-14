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

void personagem(Personagem *MC);
void criarPersonagem(Personagem *MC);
void statusPersonagem(Personagem *MC);
void upPersonagem(Personagem *MC, int pts);
void deletePersonagem(Personagem *MC);
void inventario(Personagem *MC);
void comprarItem(Consumiveis *itens, Personagem *MC);
void viewInventario(Consumiveis *itens);
void descartarItem(Consumiveis *itens);

FILE mcArquivo;
FILE itensARQ;