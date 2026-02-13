#include <stdio.h>
#include <stdlib.h>
#include "utilidades/utilidades.h"
#include "produto/produto.h"

int main() {

    // Inicializando o produto
    Produto produto;
    produto.codigo = NULL;
    produto.nome = NULL;
    produto.quantidade = NULL;
    produto.cont = 0;
    
    // Variaveis para o menu
    int opcao;
    int codigo;
    char nome[100];
    int quantidade;

    limpar_tela();
    printf("======================\n");
    printf("Gerenciamento de Estoque\n");
    printf("======================\n");
    while (opcao != 0)
    {
          printf("\nMenu:\n");
          printf("1. Adicionar produto\n");
          printf("2. Mostrar produtos\n");
          printf("3. Editar produto\n");
          printf("4. Remover produto\n");
          printf("0. Sair\n");
          printf("Escolha uma opcao: ");
          scanf("%d", &opcao);
          
          switch (opcao) {
              case 1:
                    limpar_tela();
                    printf("Digite o código do produto a ser adicionado: ");
                    scanf("%d", &codigo);                
                    printf("Digite o nome do produto a ser adicionado: ");
                    scanf("%s", nome);
                    printf("Digite a quantidade do produto a ser adicionado: ");
                    scanf("%d", &quantidade);
                    adicionarProduto(&produto, codigo, nome, quantidade);
                    limpar_tela();
                    pausar();
                    break;
              case 2:
                    limpar_tela();
                    mostrarProdutos(&produto);
                    limpar_tela();
                    pausar();
                    break;
             case 3:
                    limpar_tela();
                    printf("Digite o código do produto a ser editado: ");
                    scanf("%d", &codigo);
                    printf("Digite a nova quantidade do produto: ");
                    scanf("%d", &quantidade);
                    editarProduto(&produto, codigo, quantidade);
                    limpar_tela();
                    pausar();
                    break;
             case 4:
                    limpar_tela();
                    printf("Digite o código do produto a ser removido: ");
                    scanf("%d", &codigo);
                    removerProduto(&produto, codigo);
                    limpar_tela();
                    pausar();
                    break;
              case 0:
                    limpar_tela();
                    printf("Saindo...\n");
                    limpar_tela();
                    break;
              default:
                    printf("Opcao invalida. Tente novamente.\n");
          }
    }
    
    return 0;
}