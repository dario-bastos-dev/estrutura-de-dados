#include <stdio.h>
#include <stdlib.h>

int main() {
    int *valores, tamanho;

    printf("Digite o número de elementos: ");
    scanf("%d", &tamanho);

    valores = calloc(tamanho, sizeof(int));
    if (valores == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o novo valor para a posição %d: ", i);
        scanf("%d", &valores[i]);
    }
    printf("\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n");
    free(valores);

    return 0;
}