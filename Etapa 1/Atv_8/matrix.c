#include <stdio.h>
#include <stdlib.h>

int main() {
    int L, C;
    
    printf("Digite o número de linhas: ");
    scanf("%d", &L);
    printf("Digite o número de colunas: ");
    scanf("%d", &C);
    
    // Aloca ponteiro de ponteiros
    int **matriz = (int **)malloc(L * sizeof(int *));
    for (int i = 0; i < L; i++) {
        matriz[i] = (int *)malloc(C * sizeof(int));
    }
    
    // Lê os valores da matriz
    printf("\nDigite os valores da matriz:\n");
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // Calcula a soma de cada linha
    printf("\nSoma de cada linha:\n");
    for (int i = 0; i < L; i++) {
        int soma = 0;
        for (int j = 0; j < C; j++) {
            soma += matriz[i][j];
        }
        printf("Linha %d: %d\n", i, soma);
    }
    
    // Identifica o maior elemento
    int maior = matriz[0][0];
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }
    printf("\nMaior elemento: %d\n", maior);
    
    // Libera a memória
    for (int i = 0; i < L; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
    return 0;
}