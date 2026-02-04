#ifndef CARRO_H
#define CARRO_H

typedef struct {
          char placa[7];
          char modelo[100];
          int ano;
} Carro;

void cadastrarCarro();
void exibirCarros(void *dados);

#endif