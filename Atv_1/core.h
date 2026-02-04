#ifndef CORE_H
#define CORE_H

int cadastrar(void *caixa, int tamanho, char *arquivo);
void exibir(char *arquivo, int tamanho, void (*imprimir)(void*));

#endif