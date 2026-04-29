# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -g -Wall

# Nome do executável
TARGET = sistema.exe

# Todos os arquivos .c (adicione/remova conforme necessário)
SOURCES = main.c \
          aluno/aluno.c \
          turma/turma.c \
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