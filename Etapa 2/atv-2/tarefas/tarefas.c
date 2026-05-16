#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tarefas.h"


Pilha *IniciarPilha() {
    Pilha *pi = (Pilha *)malloc(sizeof(Pilha));

    if (pi == NULL) {
        printf("Erro ao criar ao alocar a memória da fila\n");
        return NULL;
    }

    printf("Pilha de tarefas iniciada!\n");

    pi->topo = NULL;

    return pi;
}

void InserirTarefa(Pilha **pi) {
    Tarefa *novo = (Tarefa *)malloc(sizeof(Tarefa));

    if (novo == NULL) {
        printf("Erro ao criar ao alocar a memória do elemento\n");
        return;
    }

    printf("Insira o nome da tarefa:\n");
    fgets(novo->nome,sizeof(novo->nome),stdin);

    novo->nome[strcspn(novo->nome,"\n")] = '\0';
    

    if ((*pi)->topo == NULL) {
        novo->prox = NULL;
        (*pi)->topo = novo;
    } else {
        novo->prox = (*pi)->topo;
        (*pi)->topo = novo;
    }

    printf("Nova tarefa adicionada!\n");

    printf("Pressiona qualquer botão para sair.\n");
    getchar();
};

void ExibirProximaTarefa(Pilha *pi) {
    if (pi->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    Tarefa *tarefa = pi->topo;
    int cont = 0;
    
    do
    {
        printf("Valor: %s\n", tarefa->nome);
        tarefa = tarefa->prox;
        cont++;
    } while (tarefa != NULL);

    printf("Total de elementos na pilha: %d\n", cont);

    printf("Pressiona qualquer botão para sair.\n");
    getchar();

}

void EsvaziarPilha(Pilha **pi) {
    if ((*pi)->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Removendo tarefas restantes...\n");

    while ((*pi)->topo != NULL) {   
        printf("Tarefa removida: %s\n", (*pi)->topo->nome);
        Tarefa *temp = (*pi)->topo;
        (*pi)->topo = (*pi)->topo->prox;
        free(temp);
    }

    printf("Todas as tarefas foram apagadas!\n");
    
}