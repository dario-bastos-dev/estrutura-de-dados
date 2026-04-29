#ifndef PRODUTO_H
#define PRODUTO_H

#include <string.h>

typedef struct {
    int *codigo;
    char **nome;
    int *quantidade;
    int cont;
} Produto;

void adicionarProduto(Produto *produto, int codigo, char nome[100], int quantidade);

void mostrarProdutos(Produto *produto);

void editarProduto(Produto *produto, int codigo, int novaQuantidade);

void removerProduto(Produto *produto, int codigo);

#endif