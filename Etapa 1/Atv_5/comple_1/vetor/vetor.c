#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

Vetor* criarVetor(Vetor *vetor) {
     int tamanho;

     printf("Digite o tamanho do vetor: ");
     scanf("%d", &tamanho);

     Vetor *novoVetor = (Vetor*)malloc(sizeof(Vetor));
     if (novoVetor == NULL) {
          printf("Erro ao alocar memoria para o vetor.\n");
          return NULL;
     }

     novoVetor->array = (int*)malloc(sizeof(int) * tamanho);
     if (novoVetor->array == NULL) {
          printf("Erro ao alocar memoria para o array do vetor.\n");
          free(novoVetor);
          return NULL;
     }

     novoVetor->count = tamanho;

     for (size_t i = 0; i < tamanho; i++) {
          printf("Digite o valor para a posicao %zu: ", i);
          scanf("%d", &novoVetor->array[i]);
     }

     printf("\nVetor criado com sucesso!\n");
     
     return novoVetor;
}

void exibirValor(Vetor *vetor, int posicao) {
     if (posicao < 0 || posicao >= vetor->count) {
          printf("Posicao invalida. Por favor, insira um valor entre 0 e %d.\n", vetor->count - 1);
          return;
     }
     printf("Valor na posicao %d: %d\n", posicao, vetor->array[posicao]);
}