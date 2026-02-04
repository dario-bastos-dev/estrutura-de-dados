#ifndef FILME_H
#define FILME_H

typedef struct {
          char titulo[20];
          char genero[20];
          int duracao;
} Filme;

void cadastrarFilme();
void exibirFilmes(void *dados);

#endif