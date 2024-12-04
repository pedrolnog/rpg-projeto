#include "savegame.h"
#include "iniciarJogo.h"
#include "ManipArquivos.h"
#include "menuBatalha.h"
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>

// Fun��o para iniciar jogo.
void iniciarJogo() {
    FILE* saveFile = abrirArquivo("./dados/saveFile.txt", "r"); // Abertura de arquivo.
    Save save;
    int escolha = 1;

    // Configura��o de locale e encoding
    setlocale(LC_ALL, "Portuguese_Brazil");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    if (fscanf(saveFile, "Nome: %s Nivel: %d Experiencia: %d Ouro: %d HP: %d MP: %d Ataque: %d Defesa: %d Agilidade: %d Area: %d Checkpoint: %d Timestamp: %d",
            save.personagem.nome, &save.personagem.lvl, &save.personagem.exp, &save.personagem.ouro, &save.personagem.hp, &save.personagem.mp,
            &save.personagem.ata, &save.personagem.def, &save.personagem.agi, &save.nivel, &save.checkpoint, &save.timestamp) != 12) {
        printf("\nErro ao ler os dados do arquivo.\n");
        fclose(saveFile);
    }

    fclose(saveFile);

    // Passagem de n�veis.
    do {
        switch (save.nivel) {
            case 0:
                nivelPreludio(&save);
                break;
            case 1:
                nivelTutorial(&save);
                break;
        }

        if (save.nivel > 1) {
            printf("Fase inexistente.\n");
        } else {
            do {
                printf("\n\nProsseguir para a pr�xima fase?\n\n");
                printf("1. Continuar.\n2. Sair.\n");
                scanf("%d", &escolha);
                fflush(stdin); 
            } while (escolha != 1 && escolha != 2); // Evita escolhas diferentes de 1 e 2.
        }

    } while (escolha != 2); // Evita voltar para o menu ap�s cada n�vel.
}

// Fun��o que cont�m o n�vel do prel�dio.
void nivelPreludio(Save *save) {
    int escolha = 0;

    printf("\n");
    printf("\"Voc� estava em casa, uma noite como qualquer outra. A chuva tamborilava suavemente na janela, e o ar estava frio o suficiente para justificar o cobertor sobre suas pernas. Sobre a mesa � sua frente, um velho livro empoeirado reluzia � luz de uma lamparina. Era um presente misterioso que voc� encontrou em sua mochila esta manh�, com uma �nica palavra escrita na capa: 'Fantasia'.\"\n");
    do {
        printf("\n1. Abrir o livro e come�ar a ler.\n2. Ignorar o livro e olhar pela janela.\n");
        scanf("%d", &escolha);
        fflush(stdin);

        if (escolha == 1) {
            printf("\n\"Ao abrir o livro, as p�ginas parecem vivas. As letras dan�am e brilham, formando imagens em sua mente. Antes que pudesse entender o que estava acontecendo, uma voz ecoou pelo quarto:\"\n");
            
            sleep(5);
            
            printf("\nApenas os corajosos podem nos salvar... venha, aventureiro, Fantasia precisa de voc�.\n");
        } else if (escolha == 2) {
            printf("\"Voc� se afasta do livro e olha pela janela. Mas algo est� errado. O c�u, que antes era escuro e tranquilo, agora � engolido por uma escurid�o sem fim. Quando voc� se vira, o livro brilha intensamente, e uma voz ecoa pelo quarto:\"\n");
            
            sleep(5);
            
            printf("N�o h� escapat�ria. Fantasia precisa de voc�, agora.\n");
        } else {
            printf("Voc� pondera sobre sua decis�o...\n");
        }
    } while (escolha != 1 && escolha != 2);

    sleep(5);

    printf("\n\"De repente, um vento invis�vel invade o quarto, folhas do livro voam e giram ao seu redor, formando uma espiral brilhante. Tudo come�a a desaparecer ? a mesa, a janela, at� o som da chuva. Voc� sente como se estivesse sendo puxado para dentro do pr�prio livro.\"\n");

    sleep(5);

    printf("\n\n\t\tBem-vindo a Fantasia. Sua jornada come�a agora.\n\n");

    save->nivel++;

    salvarJogo(save);
    sleep(2);
}

// Fun��o que cont�m o n�vel do tutorial.
void nivelTutorial(Save *save) {
    int escolha = 0;

    printf("\"Voc� sente o ch�o desaparecer sob seus p�s. Quando abre os olhos, est� em um campo dourado, cercado por n�voa brilhante. � sua frente, uma imensa tartaruga fala em um tom grave.\"\n");

    sleep(10);

    printf("???: \n");
    printf("\"Ah, a� est� voc�. Eu j� estava me perguntando se o livro iria escolher algu�m digno. Vamos ver se voc� est� preparado para o que est� por vir.\"\n");

    sleep(10);

    printf("\"Voc� olha em volta com um olhar de confus�o\"\n");

    sleep(5);
    
    printf("???: \n");
    printf("Ah, jovem... voc� foi escolhido para salvar Fantasia. Mas salvar um mundo n�o � tarefa para os despreparados. Aqui, aprender� o b�sico. \nVamos come�ar.\n\n");

    sleep(5);

        do {
        printf("1. Quem � voc�?\n2. O que preciso fazer?\n");
        scanf("%d", &escolha);

        sleep(2);

        if (escolha == 1) {
            printf("\nMORLA: \n");
            printf("Eu sou Morla, a guardi� do conhecimento. Meu papel � gui�-lo antes de sua jornada. Embora, francamente, eu prefira estar dormindo.\n");
        } else if (escolha == 2) {
            printf("\nMORLA: \n");
            printf("H� muito a aprender. Cada escolha que fizer moldar� seu destino. Agora, preste aten��o.\n");
        } else {
            printf("Voc� pensa no que falar.\n");
        }

        sleep(2);

    } while (escolha != 1 && escolha != 2);

    sleep(3);

    escolha = 0;

    printf("\nMORLA: \n");
    printf("Veja � sua frente: uma pedra bloqueia o caminho. Em Fantasia, voc� encontrar� muitos obst�culos assim. O que voc� faz?\n");

    do {
        printf("1. Tentar empurrar a pedra.\n2. Olhar ao redor em busca de algo �til.\n3. Ignorar a pedra e pedir ajuda a Morla.\n");
        scanf("%d", &escolha);

        sleep(2);

        switch (escolha) {
            case 1:
                printf("\"Voc� empurra a pedra com for�a, e ela se move, abrindo o caminho. Uma sensa��o de realiza��o enche seu peito.\"\n");
                sleep(2);
                printf("\nMORLA: \n");
                printf("Boa escolha. �s vezes, a resposta mais simples � a correta.\n");
                break;
            case 2:
                printf("\"Voc� encontra um galho e usa-o como alavanca. A pedra se move facilmente.\"\n");
                sleep(2);
                printf("\nMORLA:\n");
                printf("Astuto. O pensamento r�pido ser� �til em sua jornada.\n");
                break;
            case 3:
                printf("\nMORLA:\n");
                printf("Ah, confiar nos outros pode ser s�bio, mas voc� deve aprender a enfrentar desafios sozinho.\n");
                sleep(2);
                printf("\"Com a ajuda de Morla, voc� empurra a pedra e avan�a, mas sente que perdeu uma chance de crescer.\"\n");
                break;
            default:
                printf("Voc� pensa no que fazer com esta pedra.\n");
        }
        sleep(2);
    } while (escolha != 1 && escolha != 2 && escolha != 3);

    //BATALHA

    printf("\n\"De repente, a n�voa escurece e uma sombra sinistra surge � sua frente. � uma criatura feita de puro Nada, amea�adora e inst�vel.\"\n");

    sleep(5);

    printf("\nMORLA:\n");
    printf("Este � um Fragmento do Nada. N�o tema. Escolha sua a��o com sabedoria para derrot�-lo.\n");

    // Iniciando batalha contra o primeiro inimigo.
    batalhaSlime(save);

    sleep(2);
    printf("Voc� se cansa um pouco...\n");
    sleep(5);

    printf("A n�voa ainda se mant�m, e outra sombra, maior e mais intimidadora surge � sua frente...\nUma figura grande e imponente surge diante de voc�.");

    // Batalha contra a segunda criatura...
    batalhaElite(save);

    sleep(2);

    printf("\nMORLA:\n");
    printf("Muito bem, jovem. Voc� passou nos primeiros testes. Fantasia precisa de um her�i como voc�. Lembre-se, cada escolha molda o destino deste mundo.\n");

    printf("\"Um portal brilhante se abre diante de voc�.\nVoc� o atravessa, sendo transportado para outro local...\"\n\n");

    save->nivel++;

    salvarJogo(save);
    sleep(2);
}
