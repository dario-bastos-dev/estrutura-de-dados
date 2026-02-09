# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -g -Wall

# Nome do executável
TARGET = sistema.exe

# Todos os arquivos .c (adicione/remova conforme necessário)
SOURCES = main.c \
          produto/produto.c \
	cliente/cliente.c \
	venda/venda.c \
	utilidades/utilidades.c \
	json/cJSON.c

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