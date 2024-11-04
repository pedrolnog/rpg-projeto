#ifndef ARMAS_H
#define ARMAS_H

typedef struct Armas{
	char nome[N]; // nome da espada
	char tipoDano[T]; 
	int danoMin;
	int danoMax;
	char habilidade[H]; // nome da habilidade
	int danoMinH;
	int danoMaxH;
	char efeito[E]; // efeito que a habilidade causa no inimigo caso acerte
}arma;

void espadas();
void arcos();
void cajados();
int ataque();
int bloquear(int danoDoSlime);
int fugir(int agilidadeHeroi, int agilidadeInimigo);
int usar_item();

#endif
