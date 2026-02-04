#include <stdio.h>
#include "cliente.h"
#include "../core.h"

void cadastrarCliente () { 
          Cliente cliente;

          printf("Digite o ID do cliente: ");
          scanf("%d", &cliente.id);    
          printf("Digite o nome do cliente: "); 
          scanf(" %[^\n]s", cliente.nome);
          printf("Digite o telefone do cliente: "); 
          scanf("%d", &cliente.telefone);

          printf("Cadastrando cliente...\n");
          int resultado = cadastrar(&cliente, sizeof(Cliente), "Cliente/clientes.txt"); 
          if (resultado) {
              printf("Cliente cadastrado com sucesso!\n");
          } else {
              printf("Falha ao cadastrar cliente.\n");
              return;
          }

          printf("\nDados do Cliente cadastrado:\n");
          printf("ID: %d\n", cliente.id);
          printf("Nome: %s\n", cliente.nome);
          printf("Telefone: %d\n", cliente.telefone);
}

void exibirClientes(void *dados) {
    Cliente *cliente = (Cliente*) dados; 
    
    printf("ID: %d | Nome: %s | Telefone: %d\n", cliente->id, cliente->nome, cliente->telefone);
}