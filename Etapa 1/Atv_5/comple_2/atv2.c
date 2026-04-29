#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;

    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho invalido! Deve ser maior que zero.\n");
        return 1;
    }

   
    int *vetor = (int*) malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

   
    printf("\nDigite os %d valores inteiros:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

   
    int maior = vetor[0];
    int menor = vetor[0];

   
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }

        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    
    printf("\nMaior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    
    free(vetor);

    return 0;
}