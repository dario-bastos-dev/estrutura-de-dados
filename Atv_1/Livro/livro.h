#ifndef LIVRO_H
#define LIVRO_H

typedef struct {
          int isbn;
          char titulo[100];
          char autor[100];
} Livro;

void cadastrarLivro();
void exibirLivros(void *dados);

#endif