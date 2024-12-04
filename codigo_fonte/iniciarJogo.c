#include "savegame.h"
#include "iniciarJogo.h"
#include "ManipArquivos.h"
#include "menuBatalha.h"
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>

// Função para iniciar jogo.
void iniciarJogo() {
    FILE* saveFile = abrirArquivo("./dados/saveFile.txt", "r"); // Abertura de arquivo.
    Save save;
    int escolha = 1;

    // Configuração de locale e encoding
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

    // Passagem de níveis.
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
                printf("\n\nProsseguir para a próxima fase?\n\n");
                printf("1. Continuar.\n2. Sair.\n");
                scanf("%d", &escolha);
                fflush(stdin); 
            } while (escolha != 1 && escolha != 2); // Evita escolhas diferentes de 1 e 2.
        }

    } while (escolha != 2); // Evita voltar para o menu após cada nível.
}

// Função que contém o nível do prelúdio.
void nivelPreludio(Save *save) {
    int escolha = 0;

    printf("\n");
    printf("\"Você estava em casa, uma noite como qualquer outra. A chuva tamborilava suavemente na janela, e o ar estava frio o suficiente para justificar o cobertor sobre suas pernas. Sobre a mesa à sua frente, um velho livro empoeirado reluzia à luz de uma lamparina. Era um presente misterioso que você encontrou em sua mochila esta manhã, com uma única palavra escrita na capa: 'Fantasia'.\"\n");
    do {
        printf("\n1. Abrir o livro e começar a ler.\n2. Ignorar o livro e olhar pela janela.\n");
        scanf("%d", &escolha);
        fflush(stdin);

        if (escolha == 1) {
            printf("\n\"Ao abrir o livro, as páginas parecem vivas. As letras dançam e brilham, formando imagens em sua mente. Antes que pudesse entender o que estava acontecendo, uma voz ecoou pelo quarto:\"\n");
            
            sleep(5);
            
            printf("\nApenas os corajosos podem nos salvar... venha, aventureiro, Fantasia precisa de você.\n");
        } else if (escolha == 2) {
            printf("\"Você se afasta do livro e olha pela janela. Mas algo está errado. O céu, que antes era escuro e tranquilo, agora é engolido por uma escuridão sem fim. Quando você se vira, o livro brilha intensamente, e uma voz ecoa pelo quarto:\"\n");
            
            sleep(5);
            
            printf("Não há escapatória. Fantasia precisa de você, agora.\n");
        } else {
            printf("Você pondera sobre sua decisão...\n");
        }
    } while (escolha != 1 && escolha != 2);

    sleep(5);

    printf("\n\"De repente, um vento invisível invade o quarto, folhas do livro voam e giram ao seu redor, formando uma espiral brilhante. Tudo começa a desaparecer ? a mesa, a janela, até o som da chuva. Você sente como se estivesse sendo puxado para dentro do próprio livro.\"\n");

    sleep(5);

    printf("\n\n\t\tBem-vindo a Fantasia. Sua jornada começa agora.\n\n");

    save->nivel++;

    salvarJogo(save);
    sleep(2);
}

// Função que contém o nível do tutorial.
void nivelTutorial(Save *save) {
    int escolha = 0;

    printf("\"Você sente o chão desaparecer sob seus pés. Quando abre os olhos, está em um campo dourado, cercado por névoa brilhante. À sua frente, uma imensa tartaruga fala em um tom grave.\"\n");

    sleep(10);

    printf("???: \n");
    printf("\"Ah, aí está você. Eu já estava me perguntando se o livro iria escolher alguém digno. Vamos ver se você está preparado para o que está por vir.\"\n");

    sleep(3);

    printf("\n\"Você olha em volta com um olhar de confusão\"\n");

    sleep(3);
    
    printf("\n???\n");
    printf("Ah, jovem... você foi escolhido para salvar Fantasia. Mas salvar um mundo não é tarefa para os despreparados. Aqui, aprenderá o básico. \nVamos começar.\n\n");

    sleep(5);
        do {
        printf("1. Quem é você?\n2. O que preciso fazer?\n");
        scanf("%d", &escolha);

        sleep(2);

        if (escolha == 1) {
            printf("\nMORLA: \n");
            printf("Eu sou Morla, a guardiã do conhecimento. Meu papel é guiá-lo antes de sua jornada. Embora, francamente, eu prefira estar dormindo.\n");
        } else if (escolha == 2) {
            printf("\n???: \n");
            printf("Há muito a aprender. Cada escolha que fizer moldará seu destino. Agora, preste atenção.\n");
            sleep(2);
            printf("Aliás, meu nome é Morla.\n");
        } else {
            printf("\"Você pensa no que falar...\n\"");
        }

        sleep(2);

    } while (escolha != 1 && escolha != 2);

    sleep(3);

    escolha = 0;

    printf("\nMORLA: \n");
    printf("Veja à sua frente: uma pedra bloqueia o caminho. Em Fantasia, você encontrará muitos obstáculos assim. O que você faz?\n");

    do {
        printf("1. Tentar empurrar a pedra.\n2. Olhar ao redor em busca de algo útil.\n3. Ignorar a pedra e pedir ajuda a Morla.\n");
        scanf("%d", &escolha);

        sleep(2);

        switch (escolha) {
            case 1:
                printf("\"Você empurra a pedra com força, e ela se move, abrindo o caminho. Uma sensação de realização enche seu peito.\"\n");
                sleep(2);
                printf("\nMORLA: \n");
                printf("Boa escolha. Às vezes, a resposta mais simples é a correta.\n");
                break;
            case 2:
                printf("\"Você encontra um galho e usa-o como alavanca. A pedra se move facilmente.\"\n");
                sleep(2);
                printf("\nMORLA:\n");
                printf("Astuto. O pensamento rápido será útil em sua jornada.\n");
                break;
            case 3:
                printf("\nMORLA:\n");
                printf("Ah, confiar nos outros pode ser sábio, mas você deve aprender a enfrentar desafios sozinho.\n");
                sleep(2);
                printf("\"Com a ajuda de Morla, você empurra a pedra e avança, mas sente que perdeu uma chance de crescer.\"\n");
                break;
            default:
                printf("\"Você pensa no que fazer com esta pedra...\n\"");
        }
        sleep(2);
    } while (escolha != 1 && escolha != 2 && escolha != 3);

    // BATALHA

    printf("\n\"De repente, a névoa escurece e uma sombra sinistra surge à sua frente. É uma criatura feita de puro Nada, ameaçadora e instável.\"\n");

    sleep(5);

    printf("\nMORLA:\n");
    printf("Este é um Fragmento do Nada. Não tema. Escolha sua ação com sabedoria para derrotá-lo.\n");

    // Iniciando batalha contra o primeiro inimigo.
    batalhaSlime(save);

    sleep(2);
    printf("Você se cansa um pouco...\n");
    sleep(3);

    printf("\nMORLA:\n");
    printf("Muito bem, jovem. Você passou nos primeiros testes. Fantasia precisa de um herói como você. Lembre-se, cada escolha molda o destino deste mundo.\n");

    sleep(3);

    printf("\"Um portal brilhante se abre diante de você. Você o atravessa, sendo transportado para outro local...\"\n\n");

    sleep(5);

    printf("\"Você acorda com uma dor de cabeça intensa... Você lentamente esquece quem estava com você anteriormente, como se tudo tivesse sido um sonho.\nPorém, ainda assim, você sente que precisará dos ensinamentos...\" \n");

    save->nivel++;

    salvarJogo(save);
    sleep(2);
}


void nivelUm(Save *save) {
    int escolha = 0;

    printf("\"Você, %s sente que caiu no chão ao olhar pra cima você vê que está numa pequena cidade.\n\"", save->personagem.nome);
    sleep(2);
    printf("Você observa um velho homem próximo a você...\"\n", save->personagem.nome);

    sleep(2);

    printf("\n???\n");
    printf("Venho por meio deste dizer que aqui não é lugar para crianças. Peço que se retire\n");

    sleep(2);

    do {
        printf("1. Se você não me quer, então não deveria ter me chamado\n2. Quem é você? O que estou fazendo aqui?!\n");
        scanf("%d", &escolha);
        
        if (escolha == 1) {
            printf("\nVELHO CONSELHEIRO\n");
            printf("Não era você quem queríamos, criança. Chamamos por %s.\n", save->personagem.nome);
        } else if (escolha == 2) {
            printf("\nVELHO CONSELHEIRO\n");
            printf("Está perdida, criança? Eu sou apenas um velho conselheiro, e estamos aqui esperando por %s.\n", save->personagem.nome);
        } else {
            printf("\"Você pensa no que falar...\n\"");
        }
        sleep(2);
    } while (escolha != 1 && escolha != 2);

    printf("\n%s\n", save->personagem.nome);
    printf("Mas eu sou %s\n", save->personagem.nome);
        sleep(2);

    sleep(2);

    printf("\nVELHO CONSELHEIRO\n");
    printf("(risada) Não %s a criança. %s o guerreiro\n", save->personagem.nome, save->personagem.nome);

    sleep(2);

    printf("\n%s\n", save->personagem.nome);
    printf("Sou o único %s no Povo das planícies, mas eu posso muito bem voltar a caçar meus búfalos (sai andando)\n", save->personagem.nome);

    sleep(3);

    printf("\nVELHO CONSELHEIRO\n");
    printf("Volte, por favor. Se você é o %s que pedimos, aceitaria desbravar uma missão?\n", save->personagem.nome);

    sleep(2);

    printf("\n%s\n", save->personagem.nome);
    printf("Sim, claro. Que tipo de missão?\n");

    sleep(2);

    printf("\nVELHO CONSELHEIRO\n");
    printf("Achar a cura para a imperatriz... e salvar o nosso mundo. \nNinguém pode te dar um conselho, exceto esse: Você deve ir sozinho e deixar tudo para trás. Será perigoso.\n");

    sleep(3);

    printf("\n%s\n", save->personagem.nome);
    printf("Quais são as chances de sucesso?\n");

    sleep(2);

    printf("\nVELHO CONSELHEIRO\n");
    printf("Eu não sei, mas se você falhar a imperatriz vai morrer... E todo nosso mundo será destruído.\n");

    sleep(2);

    printf("\n%s\n", save->personagem.nome);
    printf("Quando começo?\n");

    sleep(1);


    printf("\nVELHO CONSELHEIRO\n");
    printf("Agora. E você deve se apressar, pois o Nada cresce mais forte a cada dia. Pegue isso.\n(Ancião dá um amuleto para %s)\n", save->personagem.nome);
    sleep(1);
    printf("Aquele que veste o Auryn, fala pela imperatriz. Ele o guiará e protegerá.\n");

    printf("\"Você sai a cavalo rapidamente com cumprimentos de despedida e boa sorte dos cidadãos, passando por várias belas paisagens diversas do reino de fantasia\"\n");

    printf("\"Ao mesmo tempo, em outro lugar em fantasia, uma criatura também começa sua missão...\"\n");

    save->nivel++;
    salvarJogo(save);
    sleep(2);
}

void nivelDois(Save *save) {
    int escolha = 0;
    printf("\n\"Eles viajaram sem rumo por uma semana, mas sem encontrar uma cura para a imperatriz. Nem %s, nem seu cavalo, Artax, suspeitavam que a criatura já estava os vigiando.\"\n", save->personagem.nome);

    sleep(2);

    printf("\n%s\n", save->personagem.nome);
    printf("(cavalo lambe o rosto de %s) O que foi, Artax? Já é hora de ir? Já sei o que você quer... É hora de comer! Boa ideia.\n", save->personagem.nome);

    printf("\n\"Depois, %s continua sua jornada por fantasia, desbravando os mais diversos lugares de fantasia\"\n", save->personagem.nome);
    printf("\"A criatura, que a cada momento que passava se aproximava de %s, agora está no mesmo local que ele.\"\n", save->personagem.nome);
    printf("\"%s sente um calafrio, um pressentimento de que algo ruim estava prestes a acontecer...\nUma névoa surge em volta dele, quando ele finalmente vê pela névoa...\"\n", save->personagem.nome);

    // Batalha contra o segundo inimigo.
    batalhaElite(save);

    if (save->personagem.hp <= 0) {
        printf("\n\"Você morreu. O reino de Fantasia está perdido.\"\n");
    } else {
        printf("\"Você está extremamente cansado. Você sabe que algo te ajudou nesse combate e então você percebe, seu amuleto estava brilhando.\"\n");
        printf("\"Você resolve descansar um pouco antes de prosseguir...\"\n");
        save->nivel++;
        salvarJogo(save);
    }


}