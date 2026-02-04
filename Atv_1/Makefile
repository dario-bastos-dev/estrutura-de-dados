# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -g -Wall

# Nome do executável
TARGET = sistema.exe

# Todos os arquivos .c (adicione/remova conforme necessário)
SOURCES = main.c \
          menus.c \
          core.c \
          Aluno/aluno.c \
          Carro/carro.c \
          Cliente/cliente.c \
          Conta_bancaria/conta_bancaria.c \
          Endereco/endereco.c \
          Filme/filme.c \
          Funcionario/funcionario.c \
          Livro/livro.c \
          Produto/produto.c \
          Professor/professor.c

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