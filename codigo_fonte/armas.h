#ifndef ARMAS_H
#define ARMAS_H

#define NA 50
#define T 25
#define H 25
#define E 25

typedef struct Armas{
	char nome[NA]; // nome da espada
	char tipoDano[T]; 
	int danoMin;
	int danoMax;
	char habilidade[H]; // nome da habilidade
	int danoMinH;
	int danoMaxH;
	char efeito[E]; // efeito que a habilidade causa no inimigo caso acerte
} arma;

void espadas();
void arcos();
void cajados();

#endif
