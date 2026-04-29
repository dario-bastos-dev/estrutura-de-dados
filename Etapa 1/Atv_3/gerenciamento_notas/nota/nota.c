#include <stdio.h>
#include <stdlib.h>
#include "nota.h"

void adicionarNota(Nota *nota, float valor) {
    /* Aloca memória para a nova nota */
    float *nova_lista = realloc(nota->notas, (sizeof(float) * (nota->cont + 1)));
    if (nova_lista == NULL) {
        printf("Erro ao alocar memória para as notas.\n");
        return;
    }
    
    nota->notas = nova_lista;
    nota->notas[(int)nota->cont] = valor;  /* Adiciona a nova nota */
    nota->cont += 1;  /* Incrementa o contador de notas */
    
    /* Atualiza a média, maior e menor nota */
    if (nota->cont == 1) {
        nota->maior = valor;
        nota->menor = valor;
        nota->media = valor;
    } else {
        if (valor > nota->maior) {
            nota->maior = valor;
        }
        if (valor < nota->menor) {
            nota->menor = valor;
        }

        nota->media = 0;
        for (size_t i = 0; i < nota->cont; i++) {
            nota->media += nota->notas[i];
        }
        nota->media = nota->media / (nota->cont);
    }
    
    
    return;
}

void mostrarNotas(Nota *nota) {
    printf("Notas:\n");
    for (int i = 0; i < nota->cont; i++) {
        printf("%.2f ", nota->notas[i]);
    }
    printf("\nMedia: %.2f\n", nota->media);
    printf("Maior nota: %.2f\n", nota->maior);
    printf("Menor nota: %.2f\n", nota->menor);
}