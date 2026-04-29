#include <stdio.h>
#include <stdlib.h>

int main() {
    int *notas, alunos, maior, menor;
    float media = 0;

    printf("Digite o número de alunos: ");
    scanf("%d", &alunos);

    notas = malloc(alunos * sizeof(int));
    if (notas == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < sizeof(alunos); i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%d", &notas[i]);
    }

    for (int i = 0; i < sizeof(alunos); i++) {
        media += notas[i];
    }

    media /= sizeof(alunos);
    printf("A média das notas é: %.2f\n", media);

    for (int i = 0; i < sizeof(alunos); i++) {
        if (i == 0) {
            maior = notas[i];
            menor = notas[i];
        } else {
            if (notas[i] > maior) {
                maior = notas[i];
            }
            if (notas[i] < menor) {
                menor = notas[i];
            }
        }
    }
    printf("A maior nota é: %d\n", maior);
    printf("A menor nota é: %d\n", menor);

    free(notas);
    return 0;
}