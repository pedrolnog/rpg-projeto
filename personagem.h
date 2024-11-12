#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#define N 50

typedef struct{
	char nome[N];
	int lvl; //nivel
	int exp; //experiencia
	int hp;//Health Points
	int agi;//Agilidade
	int def;//Dfesa
	int ata;//Ataque
	int mp;//Mana Points
	int ouro; //dinheiro
} Persona;

typedef struct{
	int hpPotion;
	int mpPotion;
	int atkBooster;
	int defBooster;
	int agiBooster;
}Consumiveis;


void personagem(Persona *MC);
void criarPersonagem(Persona *MC);
void statusPersonagem(Persona *MC);
void upPersonagem(Persona *MC, int pts);
void deletePersonagem(Persona *MC);
void inventario(Persona *MC);
void comprarItem(Consumiveis *itens, Persona *MC);
void viewInventario(Consumiveis *itens);
void descartarItem(Consumiveis *itens);

FILE mcArquivo;
FILE itensARQ;
#endif
