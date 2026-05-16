#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "container.h"

Pilha *IniciarPilha() {
    Pilha *pi = (Pilha *)malloc(sizeof(Pilha));

    if (pi == NULL) {
        printf("Erro ao criar ao alocar a memória da fila\n");
        return NULL;
    }

    printf("Pilha de containers iniciada!\n");

    pi->topo = NULL;

    return pi;
}

void InserirContainer(Pilha **pi) {
    static int TOTAL_CONTAINERS = 0;
    Container *novo = (Container *)malloc(sizeof(Container));

    if (novo == NULL) {
        printf("Erro ao criar e alocar a memória do container\n");
        return;
    }

    novo->id = TOTAL_CONTAINERS;
    TOTAL_CONTAINERS++;

    printf("\nInsira o nome do container:\n");
    if (fgets(novo->nome,sizeof(novo->nome),stdin) != NULL) {
        novo->nome[strcspn(novo->nome,"\n")] = '\0';
    }
    
    printf("\nInsira o destino do container:\n");
    if (fgets(novo->destino,sizeof(novo->destino),stdin) != NULL) {
        novo->destino[strcspn(novo->destino,"\n")] = '\0';
    }

    if ((*pi)->topo == NULL) {
        novo->prox = NULL;
        (*pi)->topo = novo;
    } else {
        novo->prox = (*pi)->topo;
        (*pi)->topo = novo;
    }

    printf("\nContainer adicionado:\nid: %d | Nome: %s | Destino: %s\n", novo->id, novo->nome, novo->destino);

    printf("\nNova tarefa adicionada!\n");

    printf("\nPressiona qualquer botão para sair.\n");
    getchar();
};

void ExibirProximoContainer(Pilha *pi) {
    if (pi->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    Container *container = pi->topo->prox;

    if (container == NULL) {
        printf("\nResta apenas um container na pilha.");

        printf("\nPressiona qualquer botão para sair.\n");
        getchar();
        
        return;
    }
    
    printf("\nProximo Container:\nid: %d | Nome: %s | Destino: %s\n", container->id, container->nome, container->destino);

    printf("\nPressiona qualquer botão para sair.\n");
    getchar();

}

void ExibirTodosContainers(Pilha *pi) {
    if (pi->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    Container *container = pi->topo;
    int cont = 0;

    printf("\n\n");

    while (container != NULL) {
        cont++;
        printf("Container %d\nid: %d | Nome: %s | Destino: %s\n", cont, container->id, container->nome, container->destino);
        container = container->prox;
    }

    printf("\nTotal de containers: %d\n", cont);

    printf("\nPressiona qualquer botão para sair.\n");
    getchar();

}

void DesembargarContainer(Pilha **pi) {
    if ((*pi)->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    Container *container = (*pi)->topo;
    printf("\nContainer removido:\nid: %d | Nome: %s | Destino: %s\n", container->id, container->nome, container->destino);
    (*pi)->topo = (*pi)->topo->prox;
    free(container);

    printf("\nPressiona qualquer botão para sair.\n");
    getchar();
    
}

void Esvaziar(Pilha **pi) {
    if ((*pi)->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("\nRemovendo containers restantes...\n\n");

    while ((*pi)->topo != NULL) {   
        Container *container = (*pi)->topo;
        printf("Container removido:\nid: %d | Nome: %s | Destino: %s\n", container->id, container->nome, container->destino);
        (*pi)->topo = (*pi)->topo->prox;
        free(container);
    }

    printf("\nTodos os containers foram apagados!\n");
    
}