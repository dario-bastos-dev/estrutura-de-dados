# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -g -Wall -std=c99

# Nome do executável
TARGET = sistema.exe

# Todos os arquivos .c (adicione/remova conforme necessário)
SOURCES = main.c \
          produto/produto.c \
	utilidades/utilidades.c

# Regra padrão
all: $(TARGET)

# Como compilar
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Limpar arquivos compilados
clean:
	del $(TARGET)

# Compilar e executar
run: all
	.\$(TARGET)