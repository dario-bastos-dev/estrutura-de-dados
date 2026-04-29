#ifndef FILA_H
#define FILA_H

typedef struct Elemento {
    int num;
    struct Elemento *prox;
} Elemento;

typedef struct Fila {
    Elemento *inicio;
    Elemento *fim;
} Fila;

#endif

