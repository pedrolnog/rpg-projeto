# Variáveis
CC = gcc
CFLAGS = -Wall -g
TARGET = jogo

# Arquivos objeto
OBJ = main.o JogosSalvos.o

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

# Limpar arquivos objeto e executável
clean:
	rm -f $(OBJ) $(TARGET)
