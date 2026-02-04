#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
          int codigo;
          char nome[100];
          float preco;
} Produto;

void cadastrarProduto();
void exibirProdutos(void *dados);

#endif