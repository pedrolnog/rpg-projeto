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

    system("cls");

    if (fscanf(saveFile, "Nome: %s Nivel: %d Experiencia: %d Ouro: %d HP: %d MP: %d Ataque: %d Defesa: %d Agilidade: %d Area: %d Checkpoint: %d Timestamp: %d",
            &save.personagem.nome, &save.personagem.lvl, &save.personagem.exp, &save.personagem.ouro, &save.personagem.hp, &save.personagem.mp,
            &save.personagem.ata, &save.personagem.def, &save.personagem.agi, &save.nivel, &save.checkpoint, &save.timestamp) != 12) {
        printf("\nErro ao ler os dados do arquivo.\n");
        fclose(saveFile);
    }

    fclose(saveFile);

    // Passagem de n�veis.
    do {
        sleep(1);
        switch (save.nivel) {
            case 0:
                nivelPreludio(&save);
                break;
            case 1:
                nivelTutorial(&save);
                break;
            case 2:
                nivelUm(&save);
                break;
            case 3:
                nivelDois(&save);
        }

        if (save.nivel > 3) {
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

    sleep(3);

    printf("\n\"Voc� olha em volta com um olhar de confus�o\"\n");

    sleep(3);
    
    printf("\n???\n");
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
            printf("\n???: \n");
            printf("H� muito a aprender. Cada escolha que fizer moldar� seu destino. Agora, preste aten��o.\n");
            sleep(2);
            printf("Ali�s, meu nome � Morla.\n");
        } else {
            printf("\"Voc� pensa no que falar...\n\"");
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
                printf("\"Voc� pensa no que fazer com esta pedra...\n\"");
        }
        sleep(2);
    } while (escolha != 1 && escolha != 2 && escolha != 3);

    // BATALHA

    printf("\n\"De repente, a n�voa escurece e uma sombra sinistra surge � sua frente. � uma criatura feita de puro Nada, amea�adora e inst�vel.\"\n");

    sleep(5);

    printf("\nMORLA:\n");
    printf("Este � um Fragmento do Nada. N�o tema. Escolha sua a��o com sabedoria para derrot�-lo.\n");

    // Iniciando batalha contra o primeiro inimigo.
    batalhaSlime(save);

    sleep(2);
    printf("Voc� se cansa um pouco...\n");
    sleep(3);

    printf("\nMORLA:\n");
    printf("Muito bem, jovem. Voc� passou nos primeiros testes. Fantasia precisa de um her�i como voc�. Lembre-se, cada escolha molda o destino deste mundo.\n");

    sleep(3);

    printf("\"Um portal brilhante se abre diante de voc�. Voc� o atravessa, sendo transportado para outro local...\"\n\n");

    sleep(5);

    printf("\"Voc� acorda com uma dor de cabe�a intensa... Voc� lentamente esquece quem estava com voc� anteriormente, como se tudo tivesse sido um sonho.\nPor�m, ainda assim, voc� sente que precisar� dos ensinamentos...\" \n");

    save->nivel++;

    salvarJogo(save);
    sleep(2);
}


void nivelUm(Save *save) {
    int escolha = 0;

    printf("\"Voc�, %s sente que caiu no ch�o ao olhar pra cima voc� v� que est� numa pequena cidade.\n\"", save->personagem.nome);
    sleep(2);
    printf("Voc� observa um velho homem pr�ximo a voc�...\"\n", save->personagem.nome);

    sleep(2);

    printf("\n???\n");
    printf("Venho por meio deste dizer que aqui n�o � lugar para crian�as. Pe�o que se retire\n");

    sleep(2);

    do {
        printf("1. Se voc� n�o me quer, ent�o n�o deveria ter me chamado\n2. Quem � voc�? O que estou fazendo aqui?!\n");
        scanf("%d", &escolha);
        
        if (escolha == 1) {
            printf("\nVELHO CONSELHEIRO\n");
            printf("N�o era voc� quem quer�amos, crian�a. Chamamos por %s.\n", save->personagem.nome);
        } else if (escolha == 2) {
            printf("\nVELHO CONSELHEIRO\n");
            printf("Est� perdida, crian�a? Eu sou apenas um velho conselheiro, e estamos aqui esperando por %s.\n", save->personagem.nome);
        } else {
            printf("\"Voc� pensa no que falar...\n\"");
        }
        sleep(2);
    } while (escolha != 1 && escolha != 2);

    printf("\n%s\n", save->personagem.nome);
    printf("Mas eu sou %s\n", save->personagem.nome);
        sleep(2);

    sleep(2);

    printf("\nVELHO CONSELHEIRO\n");
    printf("(risada) N�o %s a crian�a. %s o guerreiro\n", save->personagem.nome, save->personagem.nome);

    sleep(2);

    printf("\n%s\n", save->personagem.nome);
    printf("Sou o �nico %s no Povo das plan�cies, mas eu posso muito bem voltar a ca�ar meus b�falos (sai andando)\n", save->personagem.nome);

    sleep(3);

    printf("\nVELHO CONSELHEIRO\n");
    printf("Volte, por favor. Se voc� � o %s que pedimos, aceitaria desbravar uma miss�o?\n", save->personagem.nome);

    sleep(2);

    printf("\n%s\n", save->personagem.nome);
    printf("Sim, claro. Que tipo de miss�o?\n");

    sleep(2);

    printf("\nVELHO CONSELHEIRO\n");
    printf("Achar a cura para a imperatriz... e salvar o nosso mundo. \nNingu�m pode te dar um conselho, exceto esse: Voc� deve ir sozinho e deixar tudo para tr�s. Ser� perigoso.\n");

    sleep(3);

    printf("\n%s\n", save->personagem.nome);
    printf("Quais s�o as chances de sucesso?\n");

    sleep(2);

    printf("\nVELHO CONSELHEIRO\n");
    printf("Eu n�o sei, mas se voc� falhar a imperatriz vai morrer... E todo nosso mundo ser� destru�do.\n");

    sleep(2);

    printf("\n%s\n", save->personagem.nome);
    printf("Quando come�o?\n");

    sleep(1);


    printf("\nVELHO CONSELHEIRO\n");
    printf("Agora. E voc� deve se apressar, pois o Nada cresce mais forte a cada dia. Pegue isso.\n(Anci�o d� um amuleto para %s)\n", save->personagem.nome);
    sleep(1);
    printf("Aquele que veste o Auryn, fala pela imperatriz. Ele o guiar� e proteger�.\n");

    printf("\"Voc� sai a cavalo rapidamente com cumprimentos de despedida e boa sorte dos cidad�os, passando por v�rias belas paisagens diversas do reino de fantasia\"\n");

    printf("\"Ao mesmo tempo, em outro lugar em fantasia, uma criatura tamb�m come�a sua miss�o...\"\n");

    save->nivel++;
    salvarJogo(save);
    sleep(2);
}

void nivelDois(Save *save) {
    int escolha = 0;
    printf("\n\"Eles viajaram sem rumo por uma semana, mas sem encontrar uma cura para a imperatriz. Nem %s, nem seu cavalo, Artax, suspeitavam que a criatura j� estava os vigiando.\"\n", save->personagem.nome);

    sleep(2);

    printf("\n%s\n", save->personagem.nome);
    printf("(cavalo lambe o rosto de %s) O que foi, Artax? J� � hora de ir? J� sei o que voc� quer... � hora de comer! Boa ideia.\n", save->personagem.nome);

    printf("\n\"Depois, %s continua sua jornada por fantasia, desbravando os mais diversos lugares de fantasia\"\n", save->personagem.nome);
    printf("\"A criatura, que a cada momento que passava se aproximava de %s, agora est� no mesmo local que ele.\"\n", save->personagem.nome);
    printf("\"%s sente um calafrio, um pressentimento de que algo ruim estava prestes a acontecer...\nUma n�voa surge em volta dele, quando ele finalmente v� pela n�voa...\"\n", save->personagem.nome);

    // Batalha contra o segundo inimigo.
    batalhaElite(save);

    if (save->personagem.hp <= 0) {
        printf("\n\"Voc� morreu. O reino de Fantasia est� perdido.\"\n");
    } else {
        printf("\"Voc� est� extremamente cansado. Voc� sabe que algo te ajudou nesse combate e ent�o voc� percebe, seu amuleto estava brilhando.\"\n");
        printf("\"Voc� resolve descansar um pouco antes de prosseguir...\"\n");
        save->nivel++;
        salvarJogo(save);
    }


}