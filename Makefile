# Variáveis
CC = gcc
CFLAGS = -Wall -g
TARGET = jogo

# Arquivos objeto
OBJ = main.o codigo_fonte/savegame.o codigo_fonte/armaduras.o codigo_fonte/Inimigos.o codigo_fonte/batalha.o codigo_fonte/armas.o codigo_fonte/ManipArquivos.o codigo_fonte/inventario.o

# Regra principal
all: $(TARGET)

# Gerar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compilar os objetos
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

codigo_fonte/armaduras.o: codigo_fonte/armaduras.c codigo_fonte/armaduras.h
	$(CC) $(CFLAGS) -c codigo_fonte/armaduras.c

codigo_fonte/armas.o: codigo_fonte/armas.c codigo_fonte/armas.h
	$(CC) $(CFLAGS) -c codigo_fonte/armas.c

codigo_fonte/batalha.o: codigo_fonte/batalha.c codigo_fonte/batalha.h
	$(CC) $(CFLAGS) -c codigo_fonte/batalha.c

codigo_fonte/Inimigos.o: codigo_fonte/Inimigos.c codigo_fonte/Inimigos.h
	$(CC) $(CFLAGS) -c codigo_fonte/Inimigos.c

codigo_fonte/inventario.o: codigo_fonte/inventario.c codigo_fonte/inventario.h
	$(CC) $(CFLAGS) -c codigo_fonte/inventario.c

codigo_fonte/ManipArquivos.o: codigo_fonte/ManipArquivos.c codigo_fonte/ManipArquivos.h
	$(CC) $(CFLAGS) -c codigo_fonte/ManipArquivos.c

codigo_fonte/savegame.o: codigo_fonte/savegame.c codigo_fonte/savegame.h
	$(CC) $(CFLAGS) -c codigo_fonte/savegame.c

# Limpar arquivos objeto e executável
clean:
	rm -f $(OBJ) $(TARGET)
