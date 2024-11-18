# Variáveis
CC = gcc
CFLAGS = -Wall -g
TARGET = jogo

# Diretório de objetos
OBJ_DIR = codigo_fonte

# Arquivos objeto
OBJ = main.o $(OBJ_DIR)/iniciarJogo.o $(OBJ_DIR)/savegame.o $(OBJ_DIR)/armaduras.o $(OBJ_DIR)/Inimigos.o $(OBJ_DIR)/batalha.o $(OBJ_DIR)/armas.o $(OBJ_DIR)/ManipArquivos.o $(OBJ_DIR)/inventario.o $(OBJ_DIR)/menuBatalha.o $(OBJ_DIR)/statusPersonagem.o

# Regra principal
all: $(TARGET)

# Criar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compilar os objetos
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

$(OBJ_DIR)/armaduras.o: codigo_fonte/armaduras.c codigo_fonte/armaduras.h
	$(CC) $(CFLAGS) -c codigo_fonte/armaduras.c -o $(OBJ_DIR)/armaduras.o

$(OBJ_DIR)/armas.o: codigo_fonte/armas.c codigo_fonte/armas.h
	$(CC) $(CFLAGS) -c codigo_fonte/armas.c -o $(OBJ_DIR)/armas.o

$(OBJ_DIR)/batalha.o: codigo_fonte/batalha.c codigo_fonte/batalha.h
	$(CC) $(CFLAGS) -c codigo_fonte/batalha.c -o $(OBJ_DIR)/batalha.o

$(OBJ_DIR)/Inimigos.o: codigo_fonte/Inimigos.c codigo_fonte/Inimigos.h
	$(CC) $(CFLAGS) -c codigo_fonte/Inimigos.c -o $(OBJ_DIR)/Inimigos.o

$(OBJ_DIR)/inventario.o: codigo_fonte/inventario.c codigo_fonte/inventario.h
	$(CC) $(CFLAGS) -c codigo_fonte/inventario.c -o $(OBJ_DIR)/inventario.o

$(OBJ_DIR)/ManipArquivos.o: codigo_fonte/ManipArquivos.c codigo_fonte/ManipArquivos.h
	$(CC) $(CFLAGS) -c codigo_fonte/ManipArquivos.c -o $(OBJ_DIR)/ManipArquivos.o

$(OBJ_DIR)/savegame.o: codigo_fonte/savegame.c codigo_fonte/savegame.h
	$(CC) $(CFLAGS) -c codigo_fonte/savegame.c -o $(OBJ_DIR)/savegame.o

$(OBJ_DIR)/iniciarJogo.o: codigo_fonte/iniciarJogo.c codigo_fonte/iniciarJogo.h
	$(CC) $(CFLAGS) -c codigo_fonte/iniciarJogo.c -o $(OBJ_DIR)/iniciarJogo.o

$(OBJ_DIR)/menuBatalha.o: codigo_fonte/menuBatalha.c codigo_fonte/menuBatalha.h
	$(CC) $(CFLAGS) -c codigo_fonte/menuBatalha.c -o $(OBJ_DIR)/menuBatalha.o

$(OBJ_DIR)/statusPersonagem.o: codigo_fonte/statusPersonagem.c codigo_fonte/statusPersonagem.h
	$(CC) $(CFLAGS) -c codigo_fonte/statusPersonagem.c -o $(OBJ_DIR)/statusPersonagem.o

# Limpar arquivos objeto e executável
clean:
	rm -f $(OBJ) $(TARGET)
