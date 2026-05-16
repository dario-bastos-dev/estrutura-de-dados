#ifndef PIHA_H
#define PIHA_H

typedef struct Tarefa {
    char nome[50];
    struct Tarefa *prox;
} Tarefa;

typedef struct Pilha {
    Tarefa *topo;
} Pilha;

Pilha *IniciarPilha();
void InserirTarefa(Pilha **pi);
void ExibirProximaTarefa(Pilha *pi);
void EsvaziarPilha(Pilha **pi);

#endif

