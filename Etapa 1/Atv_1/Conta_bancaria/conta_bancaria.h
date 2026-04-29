#ifndef CONTA_BANCARIA_H
#define CONTA_BANCARIA_H

typedef struct {
          int numero;
          char titular[100];
          float saldo;
} ContaBancaria;

void cadastrarContaBancaria();
void exibirContasBancarias(void *dados);

#endif