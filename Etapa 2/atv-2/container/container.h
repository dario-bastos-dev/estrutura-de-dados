#ifndef PIHA_H
#define PIHA_H

typedef struct Container {
    int id;
    char nome[20];
    char destino[50];
    struct Container *prox;
} Container;

typedef struct Pilha {
    Container *topo;
} Pilha;

Pilha *IniciarPilha();
void InserirContainer(Pilha **pi);
void ExibirProximoContainer(Pilha *pi);
void ExibirTodosContainers(Pilha *pi);
void DesembargarContainer(Pilha **pi);
void Esvaziar(Pilha **pi);

#endif

