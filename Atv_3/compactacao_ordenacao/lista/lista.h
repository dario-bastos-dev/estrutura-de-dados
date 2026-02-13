#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int *vetor;
    int cont;
} Lista;

void adicionarElemento(Lista *lista, int valor);
void imprimirLista(Lista *lista);
void removerDuplicatas(Lista *lista);
void compactarLista(Lista *lista);
void liberarLista(Lista *lista);

#endif