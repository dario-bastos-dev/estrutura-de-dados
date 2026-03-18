#include <stdio.h>
#include <stdlib.h> 

int temperaturas[7][3] = {0}; // inicialização correta

void lerTemperatura(int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("\nOBS: DIA 1 = SEGUNDA, 2 = TERÇA, 3 = QUARTA, 4 = QUINTA, 5 = SEXTA, 6 = SÁBADO, 7 = DOMINGO\n");
            printf("OBS: TURNO 1 = MANHÃ, 2 = TARDE, 3 = NOITE\n");
            printf("Digite a temperatura no dia %d da semana e no turno %d: ", i + 1, j + 1);
            scanf("%d", &temperaturas[i][j]);   
        }
    }
} 

// Média das temperaturas por dia e por turno
void mediaTemperatura(int linhas, int colunas) {

    // Média por dia
    for (int i = 0; i < linhas; i++) {
        int soma = 0;
        for (int j = 0; j < colunas; j++) {
            soma += temperaturas[i][j];
        }
        float media = (float)soma / colunas;
        printf("Média de temperatura do dia %d: %.2f\n", i + 1, media);
    }

    // Média por turno
    for (int j = 0; j < colunas; j++) {
        int soma = 0;
        for (int i = 0; i < linhas; i++) {
            soma += temperaturas[i][j];
        }
        float media = (float)soma / linhas;
        printf("Média de temperatura do turno %d: %.2f\n", j + 1, media);
    }
}

// Dia mais quente da semana (maior média diária)
void diaMaisQuente(int linhas, int colunas) {
    int dia = 0;
    float maiorMedia = -9999;

    for (int i = 0; i < linhas; i++) {
        int soma = 0;
        for (int j = 0; j < colunas; j++) {
            soma += temperaturas[i][j];
        }

        float media = (float)soma / colunas;

        if (media > maiorMedia) {
            maiorMedia = media;
            dia = i;
        }
    }

    printf("Dia mais quente da semana: %d com média %.2f\n", dia, maiorMedia);
}

int main() {
    int linhas = 7;
    int colunas = 3;

    lerTemperatura(linhas, colunas);
    mediaTemperatura(linhas, colunas);
    diaMaisQuente(linhas, colunas);

    return 0;
}