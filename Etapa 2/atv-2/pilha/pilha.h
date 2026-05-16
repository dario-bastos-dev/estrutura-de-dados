#ifndef PIHA_H
#define PIHA_H

typedef struct Elemento {
    int num;
    struct Elemento *prox;
} Elemento;

typedef struct Pilha {
    Elemento *topo;
} Pilha;

#endif

