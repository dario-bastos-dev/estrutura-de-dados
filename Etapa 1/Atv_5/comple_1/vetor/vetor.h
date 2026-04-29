#ifndef VETOR_H
#define VETOR_H

typedef struct {
    int *array;
    int count;
} Vetor;

Vetor* criarVetor(Vetor *vetor);
void exibirValor(Vetor *vetor, int posicao);

#endif