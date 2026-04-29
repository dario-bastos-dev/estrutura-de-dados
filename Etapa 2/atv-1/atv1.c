#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

Fila *CriarFila() {
    Fila *fi = (Fila *)malloc(sizeof(Fila));

    if (fi == NULL) {
        printf("Erro ao criar ao alocar a memória da fila\n");
        return NULL;
    }

    printf("Fila iniciada!\n");
    fi->inicio = NULL;
    fi->fim = NULL;
    return fi;
}

void InserirElemento(Fila **fi) {
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));

    if (novo == NULL) {
        printf("Erro ao criar ao alocar a memória do elemento\n");
        return;
    }

    printf("\nInsira o número: \n");
    scanf("%d", &novo->num);
    novo->prox = NULL;

    if ((*fi)->inicio == NULL) {
        (*fi)->inicio = novo;
        (*fi)->fim = novo;
    } else {
        (*fi)->fim->prox = novo;
        (*fi)->fim = novo;
        
    }
    
    printf("\nNovo numero inserido.\n");
    getchar();

}

void ExibirFila(Fila *fi) {
    if (fi->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    Elemento *elemento = fi->inicio;
    
    do
    {
        printf("\nValor: %d\n", elemento->num);
        elemento = elemento->prox;
    } while (elemento != NULL);
    
    getchar();

}

void RemoverElemento(Fila **fi) {
    if ((*fi)->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("\nElemento removido: %d\n", (*fi)->inicio->num);
    Elemento *temp = (*fi)->inicio;
    (*fi)->inicio = (*fi)->inicio->prox;
    free(temp); 
    
    if ((*fi)->inicio == NULL) {
        (*fi)->fim = NULL;
        printf("\nFila terminou.\n");
    }

    getchar();

}

int main(void) {
    system("cls");

    Fila *fila = CriarFila();

    if (fila == NULL) {
    printf("Erro ao criar fila\n");
    return 1;
    }


    InserirElemento(&fila);
    InserirElemento(&fila);
    InserirElemento(&fila);
    ExibirFila(fila);
    RemoverElemento(&fila);
    ExibirFila(fila);
    RemoverElemento(&fila);
    ExibirFila(fila);
    RemoverElemento(&fila);
    ExibirFila(fila);

    free(fila);
    return 0;
}