#include <stdio.h>
#include <string.h>
#include "venda.h"

/* Função para criar uma nova venda */
void criar_venda(Venda *venda, int codigo, int id_cliente) {
    venda->codigo_venda = codigo;
    venda->id_cliente = id_cliente;
    venda->total_itens = 0;
    venda->valor_total = 0.0;
}

/* Função para adicionar produto à venda */
void adicionar_produto_venda(Venda *venda, int codigo_produto, int quantidade,
                             Produto produtos[], int total_produtos) {
    int i;
    int produto_existe = 0;
    
    /* Verifica se o produto existe */
    for (i = 0; i < total_produtos; i++) {
        if (produtos[i].codigo == codigo_produto) {
            produto_existe = 1;
            break;
        }
    }
    
    if (!produto_existe) {
        printf("\nProduto não encontrado!\n");
        return;
    }
    
    if (venda->total_itens >= MAX_PRODUTOS_VENDA) {
        printf("\nLimite de produtos na venda atingido!\n");
        return;
    }
    
    /* Adiciona produto à venda */
    venda->codigos_produtos[venda->total_itens] = codigo_produto;
    venda->quantidades[venda->total_itens] = quantidade;
    venda->total_itens++;
    
    printf("\nProduto adicionado à venda!\n");
}

/* Função para calcular o total da venda */
void calcular_total_venda(Venda *venda, Produto produtos[], int total_produtos) {
    int i, j;
    float total = 0.0;
    
    for (i = 0; i < venda->total_itens; i++) {
        for (j = 0; j < total_produtos; j++) {
            if (produtos[j].codigo == venda->codigos_produtos[i]) {
                total += produtos[j].preco * venda->quantidades[i];
                break;
            }
        }
    }
    
    venda->valor_total = total;
}

/* Função para exibir uma venda completa */
void exibir_venda(Venda venda, Cliente clientes[], int total_clientes,
                  Produto produtos[], int total_produtos) {
    int i, j, k;
    char nome_cliente[100] = "Não encontrado";
    
    /* Busca o nome do cliente */
    for (i = 0; i < total_clientes; i++) {
        if (clientes[i].id == venda.id_cliente) {
            strcpy(nome_cliente, clientes[i].nome);
            break;
        }
    }
    
    printf("\n========================================\n");
    printf("VENDA #%d\n", venda.codigo_venda);
    printf("========================================\n");
    printf("Cliente: %s (ID: %d)\n", nome_cliente, venda.id_cliente);
    printf("\nProdutos:\n");
    
    /* Lista produtos da venda */
    for (j = 0; j < venda.total_itens; j++) {
        for (k = 0; k < total_produtos; k++) {
            if (produtos[k].codigo == venda.codigos_produtos[j]) {
                printf("  %d x %s\n", venda.quantidades[j], produtos[k].nome);
                printf("      R$ %.2f cada (Subtotal: R$ %.2f)\n",
                       produtos[k].preco,
                       produtos[k].preco * venda.quantidades[j]);
                break;
            }
        }
    }
    
    printf("\n----------------------------------------\n");
    printf("VALOR TOTAL: R$ %.2f\n", venda.valor_total);
    printf("========================================\n");
}