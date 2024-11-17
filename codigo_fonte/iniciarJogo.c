#include "savegame.h"
#include "iniciarJogo.h"
#include <stdio.h>
#include <stdlib.h>

int iniciarJogo() {
    FILE* saveFile = abrirArquivo("./dados/saveFile.txt", "r"); 
    Save *save;

    fscanf(saveFile, "Nome: %49s[^\n] Nivel: %d Experiencia: %d Ouro: %d HP: %d MP: %d Ataque: %d Defesa: %d Agilidade: %d", save->personagem.nome    , &save->personagem.lvl, &save->personagem.exp, &save->personagem.ouro, &save->personagem.hp, &save->personagem.mp, &save->personagem.ata, &save->personagem.def, &save->personagem.agi);
    
    printf("Status do personagem:\n");
    
    printf("Nome: %s\n", save->personagem.nome);
    printf("Nivel: %d\n", save->personagem.lvl);
    printf("Experiencia: %d\n", save->personagem.exp);
    printf("Ouro: %d\n", save->personagem.ouro);
    printf("HP: %d\n", save->personagem.hp);
    printf("MP: %d\n", save->personagem.mp);
    printf("Ataque: %d\n", save->personagem.ata);
    printf("Defesa: %d\n", save->personagem.def);
    printf("Agilidade: %d\n", save->personagem.agi);
}