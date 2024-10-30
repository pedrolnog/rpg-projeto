# Variáveis
CC = gcc
CFLAGS = -Wall -g
TARGET = jogo

# Arquivos objeto
OBJ = main.o JogosSalvos.o NewGame.o

# Regra principal
all: $(TARGET)

# Gerar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compilar os objetos
main.o: main.c JogosSalvos.h
	$(CC) $(CFLAGS) -c main.c

JogosSalvos.o: JogosSalvos.c JogosSalvos.h
	$(CC) $(CFLAGS) -c JogosSalvos.c

NewGame.o: NewGame.c NewGame.h
	$(CC) $(CFLAGS) -c NewGame.c

inimigos.o: Inimigos.c Inimigos.h
	$(CC) $(CFLAGS) -c Inimigos.c 

armas.o: armas.c armas.h
	$(CC) $(CFLAGS) -c armas.c

personagem.o: personagem.c personagem.h 
	$(CC) $(CFLAGS) -c personagem.c

# Limpar arquivos objeto e executável
clean:
	rm -f $(OBJ) $(TARGET)
