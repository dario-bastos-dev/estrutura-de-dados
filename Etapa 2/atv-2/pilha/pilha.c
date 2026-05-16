#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

Pilha *CriarPilha() {
    Pilha *pi = (Pilha *)malloc(sizeof(Pilha));

    if (pi == NULL) {
        printf("Erro ao criar ao alocar a memória da fila\n");
        return NULL;
    }

    printf("Pilha iniciada!\n");

    pi->topo = NULL;

    return pi;
}

void InserirElemento(Pilha **pi) {
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));

    if (novo == NULL) {
        printf("Erro ao criar ao alocar a memória do elemento\n");
        return;
    }

    printf("Insira o número: \n");
    scanf("%d", &novo->num);

    if ((*pi)->topo == NULL) {
        novo->prox = NULL;
        (*pi)->topo = novo;
    } else {
        novo->prox = (*pi)->topo;
        (*pi)->topo = novo;
    }

    printf("Novo número adicionado.\n");
 
};

void ExibirPilha(Pilha *pi) {
    if (pi->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    Elemento *elemento = pi->topo;
    int cont = 0;
    
    do
    {
        printf("Valor: %d\n", elemento->num);
        elemento = elemento->prox;
        cont++;
    } while (elemento != NULL);

    printf("Total de elementos na pilha: %d\n", cont);

}

void Removerelemento(Pilha **pi) {
    if ((*pi)->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Elemento removido: %d\n", (*pi)->topo->num);
    Elemento *temp = (*pi)->topo;
    (*pi)->topo = (*pi)->topo->prox;
    free(temp);

    if ((*pi)->topo == NULL) {
        printf("A pilha teminou!\n");
    }
    
}