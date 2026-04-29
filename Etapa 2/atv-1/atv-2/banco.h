#ifndef BANCO_H
#define BANCO_H
#include <time.h>

typedef struct Cliente {
    int id;
    struct Cliente *prox;
} Cliente;

typedef struct Fila {
    Cliente *inicio;
    Cliente *fim;
    int total;
} Fila;

typedef struct TempoAtendimento {
    time_t *inicio;
    time_t *fim;
    double media;
    int numb;
} TempoAtendimento;

Fila *CriarFila();
void InserirCliente(Fila **fi, TempoAtendimento **temp);
void ExibirFila(Fila *fi, TempoAtendimento *temp);
void RemoverCliente(Fila **fi, TempoAtendimento **temp);

#endif

