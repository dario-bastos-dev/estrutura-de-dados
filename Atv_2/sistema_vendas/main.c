#include <stdio.h>
#include <stdlib.h>
#include "produto/produto.h"
#include "cliente/cliente.h"
#include "venda/venda.h"
#include "utilidades/utilidades.h"

#define MAX_CLIENTES 50
#define MAX_VENDAS 100

/* Função para exibir o menu principal */
void exibir_menu() {
    printf("\n========================================\n");
    printf("   SISTEMA DE VENDAS - cJSON Edition\n");
    printf("========================================\n");
    printf("1. Carregar Produtos do JSON\n");
    printf("2. Cadastrar Cliente\n");
    printf("3. Cadastrar Produto Manualmente\n");
    printf("4. Criar Nova Venda\n");
    printf("5. Listar Todos os Clientes\n");
    printf("6. Listar Todos os Produtos\n");
    printf("7. Listar Todas as Vendas\n");
    printf("8. Buscar Produto por Código\n");
    printf("9. Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    Cliente clientes[MAX_CLIENTES];
    Venda vendas[MAX_VENDAS];
    
    int total_produtos = 0;
    int total_clientes = 0;
    int total_vendas = 0;
    
    int opcao, id_cliente, codigo_produto, quantidade;
    
    /* Variáveis auxiliares */
    int i, j;
    int novo_id, novo_codigo;
    int cliente_encontrado, produto_encontrado;
    int continuar_adicionando;
    int codigo_busca;
    
    printf("\n========================================\n");
    printf("  BEM-VINDO AO SISTEMA DE VENDAS!\n");
    printf("  Usando biblioteca cJSON para JSON\n");
    printf("========================================\n");
    pausar();
    
    do {
        limpar_tela();
        exibir_menu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:  /* Carregar Produtos do JSON */
                limpar_tela();
                printf("\n=== CARREGAR PRODUTOS DO JSON ===\n");
                
                total_produtos = carregar_produtos_json("products.txt", produtos);
                
                if (total_produtos > 0) {
                    printf("\n%d produtos carregados com sucesso!\n", total_produtos);
                    printf("\nPrimeiros 5 produtos:\n");
                    for (i = 0; i < 5 && i < total_produtos; i++) {
                        exibir_produto(produtos[i]);
                    }
                } else {
                    printf("\nErro ao carregar produtos.\n");
                    printf("Verifique se o arquivo 'products.txt' existe.\n");
                }
                
                pausar();
                break;
                
            case 2:  /* Cadastrar Cliente */
                limpar_tela();
                printf("\n=== CADASTRAR CLIENTE ===\n");
                
                if (total_clientes >= MAX_CLIENTES) {
                    printf("\nLimite de clientes atingido!\n");
                } else {
                    novo_id = total_clientes + 1;
                    cadastrar_cliente(&clientes[total_clientes], novo_id);
                    total_clientes++;
                }
                
                pausar();
                break;
                
            case 3:  /* Cadastrar Produto Manualmente */
                limpar_tela();
                printf("\n=== CADASTRAR PRODUTO ===\n");
                
                if (total_produtos >= MAX_PRODUTOS) {
                    printf("\nLimite de produtos atingido!\n");
                } else {
                    /* Gera código baseado no maior código existente */
                    novo_codigo = 1;
                    for (i = 0; i < total_produtos; i++) {
                        if (produtos[i].codigo >= novo_codigo) {
                            novo_codigo = produtos[i].codigo + 1;
                        }
                    }
                    cadastrar_produto(&produtos[total_produtos], novo_codigo);
                    total_produtos++;
                }
                
                pausar();
                break;
                
            case 4:  /* Criar Nova Venda */
                limpar_tela();
                printf("\n=== CRIAR NOVA VENDA ===\n");
                
                if (total_clientes == 0) {
                    printf("\nNenhum cliente cadastrado!\n");
                    printf("Cadastre um cliente primeiro (opção 2).\n");
                } else if (total_produtos == 0) {
                    printf("\nNenhum produto cadastrado!\n");
                    printf("Carregue produtos do JSON primeiro (opção 1).\n");
                } else {
                    /* Lista clientes */
                    printf("\nClientes disponíveis:\n");
                    for (i = 0; i < total_clientes; i++) {
                        exibir_cliente(clientes[i]);
                    }
                    
                    printf("\nDigite o ID do cliente: ");
                    scanf("%d", &id_cliente);
                    
                    /* Valida cliente */
                    cliente_encontrado = 0;
                    for (i = 0; i < total_clientes; i++) {
                        if (clientes[i].id == id_cliente) {
                            cliente_encontrado = 1;
                            break;
                        }
                    }
                    
                    if (!cliente_encontrado) {
                        printf("\nCliente não encontrado!\n");
                    } else {
                        /* Cria a venda */
                        novo_codigo = total_vendas + 1;
                        criar_venda(&vendas[total_vendas], novo_codigo, id_cliente);
                        
                        printf("\nVenda #%d criada!\n", novo_codigo);
                        printf("Cliente: %s\n", clientes[id_cliente - 1].nome);
                        
                        /* Adiciona produtos à venda */
                        continuar_adicionando = 1;
                        while (continuar_adicionando) {
                            printf("\n--- Adicionar Produtos ---\n");
                            printf("Digite o código do produto (0 para finalizar): ");
                            scanf("%d", &codigo_produto);
                            
                            if (codigo_produto == 0) {
                                continuar_adicionando = 0;
                            } else {
                                /* Busca e exibe o produto */
                                produto_encontrado = 0;
                                for (j = 0; j < total_produtos; j++) {
                                    if (produtos[j].codigo == codigo_produto) {
                                        produto_encontrado = 1;
                                        printf("\nProduto encontrado:\n");
                                        exibir_produto(produtos[j]);
                                        break;
                                    }
                                }
                                
                                if (produto_encontrado) {
                                    printf("\nDigite a quantidade: ");
                                    scanf("%d", &quantidade);
                                    
                                    if (quantidade > 0) {
                                        adicionar_produto_venda(&vendas[total_vendas], 
                                                               codigo_produto, quantidade,
                                                               produtos, total_produtos);
                                    } else {
                                        printf("\nQuantidade inválida!\n");
                                    }
                                } else {
                                    printf("\nProduto não encontrado! Use opção 6 para ver todos.\n");
                                }
                            }
                        }
                        
                        if (vendas[total_vendas].total_itens > 0) {
                            /* Calcula o total */
                            calcular_total_venda(&vendas[total_vendas], produtos, total_produtos);
                            
                            /* Exibe a venda */
                            exibir_venda(vendas[total_vendas], clientes, total_clientes,
                                        produtos, total_produtos);
                            
                            total_vendas++;
                            printf("\nVenda registrada com sucesso!\n");
                        } else {
                            printf("\nVenda cancelada (nenhum produto adicionado).\n");
                        }
                    }
                }
                
                pausar();
                break;
                
            case 5:  /* Listar Todos os Clientes */
                limpar_tela();
                printf("\n=== TODOS OS CLIENTES ===\n");
                
                if (total_clientes == 0) {
                    printf("\nNenhum cliente cadastrado!\n");
                } else {
                    for (i = 0; i < total_clientes; i++) {
                        exibir_cliente(clientes[i]);
                    }
                    printf("\nTotal: %d clientes\n", total_clientes);
                }
                
                pausar();
                break;
                
            case 6:  /* Listar Todos os Produtos */
                limpar_tela();
                printf("\n=== TODOS OS PRODUTOS ===\n");
                
                if (total_produtos == 0) {
                    printf("\nNenhum produto cadastrado!\n");
                } else {
                    printf("\nListando %d produtos:\n\n", total_produtos);
                    for (i = 0; i < total_produtos; i++) {
                        exibir_produto(produtos[i]);
                    }
                    printf("\nTotal: %d produtos\n", total_produtos);
                }
                
                pausar();
                break;
                
            case 7:  /* Listar Todas as Vendas */
                limpar_tela();
                printf("\n=== TODAS AS VENDAS ===\n");
                
                if (total_vendas == 0) {
                    printf("\nNenhuma venda realizada!\n");
                } else {
                    printf("\nTotal de vendas: %d\n", total_vendas);
                    for (i = 0; i < total_vendas; i++) {
                        exibir_venda(vendas[i], clientes, total_clientes,
                                    produtos, total_produtos);
                    }
                }
                
                pausar();
                break;
                
            case 8:  /* Buscar Produto por Código */
                limpar_tela();
                printf("\n=== BUSCAR PRODUTO ===\n");
                
                if (total_produtos == 0) {
                    printf("\nNenhum produto cadastrado!\n");
                } else {
                    printf("Digite o código do produto: ");
                    scanf("%d", &codigo_busca);
                    
                    produto_encontrado = 0;
                    for (i = 0; i < total_produtos; i++) {
                        if (produtos[i].codigo == codigo_busca) {
                            printf("\nProduto encontrado:\n");
                            printf("Código: %d\n", produtos[i].codigo);
                            printf("Nome: %s\n", produtos[i].nome);
                            printf("Preço: R$ %.2f\n", produtos[i].preco);
                            printf("Categoria: %s\n", produtos[i].categoria);
                            printf("Descrição: %s\n", produtos[i].descricao);
                            produto_encontrado = 1;
                            break;
                        }
                    }
                    
                    if (!produto_encontrado) {
                        printf("\nProduto não encontrado!\n");
                    }
                }
                
                pausar();
                break;
                
            case 9:  /* Sair */
                printf("\nEncerrando o sistema...\n");
                printf("Total de vendas realizadas: %d\n", total_vendas);
                printf("Obrigado por usar o Sistema de Vendas!\n");
                break;
                
            default:
                printf("\nOpção inválida!\n");
                pausar();
        }
        
    } while(opcao != 9);
    
    return 0;
}