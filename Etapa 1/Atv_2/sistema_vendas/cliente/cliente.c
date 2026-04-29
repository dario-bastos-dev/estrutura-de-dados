#include <stdio.h>
#include <string.h>
#include "cliente.h"

/* Função para cadastrar um cliente */
void cadastrar_cliente(Cliente *cliente, int id) {
    cliente->id = id;
    
    printf("Digite o nome do cliente: ");
    fflush(stdin);
    fgets(cliente->nome, 100, stdin);
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0';
    
    printf("\nCliente cadastrado com sucesso!\n");
}

/* Função para exibir dados de um cliente */
void exibir_cliente(Cliente cliente) {
    printf("  ID: %d | Nome: %s\n", cliente.id, cliente.nome);
}