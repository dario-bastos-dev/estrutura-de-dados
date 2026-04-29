#include <stdio.h>
#include "produto.h"
#include "../core.h"

void cadastrarProduto () { 
          Produto prod;

          printf("Digite o ID do produto: ");
          scanf("%d", &prod.codigo);    
          printf("Digite o nome do produto: "); 
          scanf(" %[^\n]s", prod.nome);
          printf("Digite o preco do produto: "); 
          scanf("%f", &prod.preco);

          printf("Cadastrando produto...\n");
          int resultado = cadastrar(&prod, sizeof(Produto), "Produto/produtos.txt");
          if (resultado) {
              printf("Produto cadastrado com sucesso!\n");
          } else {
              printf("Falha ao cadastrar produto.\n");
              return;
          }

          printf("\nDados do Produto:\n");
          printf("ID: %d\n", prod.codigo);
          printf("Nome: %s\n", prod.nome);
          printf("Preco: %.2f\n", prod.preco );
}

void exibirProdutos(void *dados) {
    Produto *produto = (Produto*) dados; 
    
    printf("Codigo: %d | Nome: %s | Preco: %.2f\n", produto->codigo, produto->nome, produto->preco);
}