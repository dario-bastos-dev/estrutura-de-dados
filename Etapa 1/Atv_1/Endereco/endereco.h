#ifndef ENDERECO_H
#define ENDERECO_H

typedef struct {
          char rua[100];
          int numero;
          char cidade[100];
} Endereco;

void cadastrarEndereco();
void exibirEnderecos(void *dados);

#endif