#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

void adicionarProduto(Produto *produto, int codigo, char nome[100], int quantidade) {
    // Aloar memória para novo produto
    int *novo_codigo = realloc(produto->codigo, (sizeof(int) * (produto->cont + 1)));
    if (novo_codigo == NULL)
    {
          printf("Erro ao alocar memória para o código do produto.\n");
          return;
    }
    
    produto->codigo = novo_codigo;
    produto->codigo[produto->cont] = codigo;
    
    char **novo_nome = realloc(produto->nome, (sizeof(char) * 100 * (produto->cont + 1)));
    if (novo_nome == NULL)
    {
          printf("Erro ao alocar memória para o nome do produto.\n");
          free(produto->codigo);
          return;
    }
    novo_nome[produto->cont] = malloc(sizeof(char) * 100);
    if (novo_nome[produto->cont] == NULL)
    {
          printf("Erro ao alocar memória para o nome do produto.\n");
          free(produto->codigo);
          return;
    }
    
    produto->nome = novo_nome;
    strcpy(produto->nome[produto->cont], nome);
    
    int *novo_quantidade = realloc(produto->quantidade, (sizeof(int) * (produto->cont + 1)));
    if (novo_quantidade == NULL)
    {
          printf("Erro ao alocar memória para a quantidade do produto.\n");
          free(produto->codigo);
          free(produto->nome);
          return;
    }
    
    produto->quantidade = novo_quantidade;
    produto->quantidade[produto->cont] = quantidade;
    
    produto->cont += 1;

    return;
}

void mostrarProdutos(Produto *produto) {
          printf("Produtos:\n");
          for (int i = 0; i < produto->cont; i++) {
          printf("Codigo: %d | Nome: %s | Quantidade: %d\n", produto->codigo[i], produto->nome[i], produto->quantidade[i]);
          }

          return;
};

void editarProduto(Produto *produto, int codigo, int novaQuantidade) {
          for (int i = 0; i < produto->cont; i++) {
                if (produto->codigo[i] == codigo) {
                      produto->quantidade[i] = novaQuantidade;
                      printf("Produto editado com sucesso!\n");
                      return;
                }
          }
          printf("Produto não encontrado.\n");
          return;
};

void removerProduto(Produto *produto, int codigo) {
          for (size_t i = 0; i < produto->cont; i++) {
                    if (produto->codigo[i] == codigo) {
                              free(produto->nome[i]);
                              for (size_t j = i; j < produto->cont - 1; j++) {
                                        produto->codigo[j] = produto->codigo[j + 1];
                                        strcpy(produto->nome[j], produto->nome[j + 1]);
                                        produto->quantidade[j] = produto->quantidade[j + 1];
                                }
                                produto->cont -= 1;
                                printf("Produto removido com sucesso!\n");
                                return;
                    }
                    
          }
          printf("Produto não encontrado.\n");
          return;
          
};