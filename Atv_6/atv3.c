#include <stdio.h>
#include <stdlib.h>


int main() {
    int matriz[3][3];
    int i, j;

    // Leitura da matriz
    printf("Digite os valores da matriz 3x3:\n");

    float soma;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            
        }
    }

    // Soma da Diagonal Principal
    printf("\nMatriz digitada:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if ( i == j ){
                soma += matriz[i][j];
            }

            printf("%d ", matriz[i][j]);

        }
        printf("\n");
    }
    printf("Soma: %.2f", soma);
        
  
}