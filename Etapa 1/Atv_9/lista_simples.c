#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int quant;
    float preco;
} Produto;

int cadastrarProduto(Produto produtos[], int index) {
    if (index < 100) {
        printf("Digite o nome do produto: ");
        scanf("%s", produtos[index].nome);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &produtos[index].quant);
        printf("Digite o preco do produto: ");
        scanf("%f", &produtos[index].preco);
        return index++;
    } else {
        printf("Limite de produtos atingido.\n");
        return index;
    }
}

void listarProdutos(Produto produtos[], int numProdutos) {
    printf("Lista de produtos:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d: %s, Quantidade: %d, Preco: %.2f\n", i + 1, produtos[i].nome, produtos[i].quant, produtos[i].preco);
    }
}

int removerProduto(Produto produtos[], int numProdutos, char nome[]) {
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            for (int j = i; j < numProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            return numProdutos - 1;
        }
    }
    printf("Produto nao encontrado.\n");
    return numProdutos;
}

void atualizarQuantidade(Produto produtos[], int numProdutos, char nome[], int novaQuant) {
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            produtos[i].quant = novaQuant;
            printf("Quantidade atualizada para o produto %s.\n", nome);
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void calcularValorTotal(Produto produtos[], int numProdutos) {
    float total = 0.0;
    for (int i = 0; i < numProdutos; i++) {
        total += produtos[i].quant * produtos[i].preco;
    }
    printf("Valor total da compra: %.2f\n", total);
}

int main() {
    Produto produtos[100];
    int numProdutos = 0;
    int opcao;
    char nome[50];

    opcao = -1; // Inicializa com um valor diferente de 0 para entrar no loop       
    while (opcao != 0) {
        printf("Selecione uma operacao:\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Remover produto\n");
        printf("4 - Atualizar quantidade do produto\n");
        printf("5 - Calcular valor total da compra\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                system("clear");
                numProdutos = cadastrarProduto(produtos, numProdutos);
                system("clear");
                break;
            case 2:
                system("clear");
                listarProdutos(produtos, numProdutos);
                break;
            case 3:
                system("clear");
                printf("Digite o nome do produto a ser removido: ");
                scanf("%s", nome);
                numProdutos = removerProduto(produtos, numProdutos, nome);
                system("clear");
                break;
            case 4:
                system("clear");
                int novaQuant;
                printf("Digite o nome do produto: ");
                scanf("%s", nome);
                printf("Digite a nova quantidade: ");
                scanf("%d", &novaQuant);
                atualizarQuantidade(produtos, numProdutos, nome, novaQuant);
                system("clear");
                break;
            case 5:
                system("clear");
                calcularValorTotal(produtos, numProdutos);
                system("clear");
                break;
            case 0:
                system("clear");
                printf("Saindo...\n");
                system("clear");
                break;
            default:
                system("clear");    
                printf("Opcao invalida. Tente novamente.\n");
                system("clear");
        }
    }
    

    return 0;
}