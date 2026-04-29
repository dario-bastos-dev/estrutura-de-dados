#ifndef CLIENTE_H
#define CLIENTE_H

/* Definição da estrutura Cliente */
typedef struct {
    int id;
    char nome[100];
} Cliente;

/* Protótipos das funções */
void cadastrar_cliente(Cliente *cliente, int id);
void exibir_cliente(Cliente cliente);

#endif