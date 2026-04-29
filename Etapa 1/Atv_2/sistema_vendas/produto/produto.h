#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 100

/* Definição da estrutura Produto */
typedef struct {
    int codigo;
    char nome[200];
    float preco;
    char categoria[50];
    char descricao[500];
} Produto;

/* Protótipos das funções */
void cadastrar_produto(Produto *produto, int codigo);
void exibir_produto(Produto produto);
int carregar_produtos_json(const char *arquivo, Produto produtos[]);

#endif