#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Adiciona um elemento ao final do vetor dinâmico
void adicionarElemento(Lista *lista, int valor) {
    int *novo_vetor = realloc(lista->vetor, sizeof(int) * (lista->cont + 1));
    if (novo_vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    lista->vetor = novo_vetor;
    lista->vetor[lista->cont] = valor;
    lista->cont += 1;
}

// Imprime todos os elementos do vetor
void imprimirLista(Lista *lista) {
    printf("[ ");
    for (int i = 0; i < lista->cont; i++) {
        printf("%d ", lista->vetor[i]);
    }
    printf("]\n");
    printf("Tamanho: %d\n", lista->cont);
}

// Remove valores duplicados
void removerDuplicatas(Lista *lista) {
    for (int i = 0; i < lista->cont; i++) {
        for (int j = i + 1; j < lista->cont; j++) {
            if (lista->vetor[j] == lista->vetor[i]) {
                for (int k = j; k < lista->cont - 1; k++) {
                    lista->vetor[k] = lista->vetor[k + 1];
                }
                lista->cont -= 1;
                j--;
            }
        }
    }
}

// Compacta o vetor realocando a memória para o tamanho exato
void compactarLista(Lista *lista) {
    if (lista->cont == 0) {
        free(lista->vetor);
        lista->vetor = NULL;
        return;
    }
    int *novo_vetor = realloc(lista->vetor, sizeof(int) * lista->cont);
    if (novo_vetor == NULL) {
        printf("Erro ao compactar memória.\n");
        return;
    }
    lista->vetor = novo_vetor;
}

// Libera toda a memória alocada
void liberarLista(Lista *lista) {
    free(lista->vetor);
    lista->vetor = NULL;
    lista->cont = 0;
}
