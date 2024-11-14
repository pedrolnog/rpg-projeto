# Variáveis
CC = gcc
CFLAGS = -Wall -g
TARGET = jogo

# Arquivos objeto
OBJ = main.o savegame.o Inimigos.o batalha.o armas.o ManipArquivos.o

# Regra principal
all: $(TARGET)

# Gerar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compilar os objetos
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

savegame.o: savegame.c savegame.h
	$(CC) $(CFLAGS) -c savegame.c

inimigos.o: Inimigos.c Inimigos.h
	$(CC) $(CFLAGS) -c Inimigos.c 

armas.o: armas.c armas.h
	$(CC) $(CFLAGS) -c armas.c

batalha.o: batalha.c batalha.h
	$(CC) $(CFLAGS) -c batalha.c

ManipArquivos.o: ManipArquivos.c ManipArquivos.h
	$(CC) $(CFLAGS) -c ManipArquivos.c

armaduras.o: armaduras.c armaduras.h
	$(CC) $(CFLAGS) -c armaduras.c


# Limpar arquivos objeto e executável
clean:
	rm -f $(OBJ) $(TARGET)
