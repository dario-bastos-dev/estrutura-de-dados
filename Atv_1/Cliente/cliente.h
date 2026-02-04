#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
          int id;
          char nome[100];
          int telefone;
} Cliente;

void cadastrarCliente();
void exibirClientes(void *dados);

#endif