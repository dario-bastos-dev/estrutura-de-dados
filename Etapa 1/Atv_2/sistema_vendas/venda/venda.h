#ifndef VENDA_H
#define VENDA_H

#include "../produto/produto.h"
#include "../cliente/cliente.h"

#define MAX_PRODUTOS_VENDA 20

/* Definição da estrutura Venda */
typedef struct {
    int codigo_venda;
    int id_cliente;
    int codigos_produtos[MAX_PRODUTOS_VENDA];
    int quantidades[MAX_PRODUTOS_VENDA];
    int total_itens;
    float valor_total;
} Venda;

/* Protótipos das funções */
void criar_venda(Venda *venda, int codigo, int id_cliente);
void adicionar_produto_venda(Venda *venda, int codigo_produto, int quantidade, 
                             Produto produtos[], int total_produtos);
void calcular_total_venda(Venda *venda, Produto produtos[], int total_produtos);
void exibir_venda(Venda venda, Cliente clientes[], int total_clientes, 
                  Produto produtos[], int total_produtos);

#endif