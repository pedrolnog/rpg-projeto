#ifndef ARMAS_H
#define ARMAS_H

#define T 25
#define H 25
#define E 25

typedef struct Armas{
	char nome[50]; // nome da espada
	char tipoDano[T]; 
	int danoMin;
	int danoMax;
	char habilidade[H]; // nome da habilidade
	int danoMinH;
	int danoMaxH;
	char efeito[E]; // efeito que a habilidade causa no inimigo caso acerte
}Arma;

FILE* armaEspada;
FILE* armaArco;
FILE* armaCajado;

void apagar_espada();
void apagar_arco();
void apagar_cajado();

void criar_espada();
void criar_arco();
void criar_cajado();

void espadas();
void arcos();
void cajados();

void alternar_espada();
void alternar_arco();
void alternar_cajado();

#endif
