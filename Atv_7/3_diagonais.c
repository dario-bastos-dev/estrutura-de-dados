#include <stdio.h>
#include <stdlib.h>

//Matriz quadrada N X N (Máximo 10x10)
int main() {
    int N;
    printf("Digite o tamanho da matriz quadrada (MÁX 10): ");
    scanf("%d", &N);
    if (N <= 0 || N > 10) {
        printf("Tamanho inválido. O tamanho deve ser entre 1 e 10.\n");
        return 1;
    }   

    int **matriz = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matriz[i] = (int *)malloc(N * sizeof(int));
    }

    // Leitura dos elementos da matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Digite o elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    //Soma dos elementos da diagonal principal
    int somaDiagonalPrincipal = 0;
    for (int i = 0; i < N; i++) {
        somaDiagonalPrincipal += matriz[i][i];
    }
    printf("Soma dos elementos da diagonal principal: %d\n", somaDiagonalPrincipal);

    //Soma dos elementos da diagonal secundária
    int somaDiagonalSecundaria = 0;
    for (int i = 0; i < N; i++) {
        somaDiagonalSecundaria += matriz[i][N - 1 - i];
    }
    printf("Soma dos elementos da diagonal secundária: %d\n", somaDiagonalSecundaria);

    //Quantidade de elementos acima da  média da matriz
    int somaTotal = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            somaTotal += matriz[i][j];
        }
    }

    
    float media = (float)somaTotal / (N * N);

    int countAcimaMedia = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] > media) {
                countAcimaMedia++;
            }
        }
    }
    printf("Quantidade de elementos acima da média (%.2f): %d\n", media, countAcimaMedia);


    //Verificação se a matriz é simétrica
    int simetrica = 1; // Assume que a matriz é simétrica até prova em contrário
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                simetrica = 0; // Não é simétrica
                break;
            }
        }
        if (!simetrica) {
            break;
        }
    }

    if (simetrica) {
        printf("A matriz é simétrica.\n");
    } else {
        printf("A matriz não é simétrica.\n");
    }

    //Resultados
        printf("Matriz digitada:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}