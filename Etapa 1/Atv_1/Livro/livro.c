#include <stdio.h>
#include "livro.h"
#include "../core.h"

void cadastrarLivro () { 
          Livro livro;

          printf("Digite o ISBN do livro: ");
          scanf("%d", &livro.isbn);    
          printf("Digite o titulo do livro: "); 
          scanf(" %[^\n]s", livro.titulo);
          printf("Digite o autor do livro: "); 
          scanf(" %[^\n]s", livro.autor);

          printf("Cadastrando livro...\n");
          int resultado = cadastrar(&livro, sizeof(Livro), "Livro/livros.txt");
          if (resultado) {
              printf("Livro cadastrado com sucesso!\n");
          } else {
              printf("Falha ao cadastrar livro.\n");
              return;
          }

          printf("\nDados do Livro:\n");
          printf("ISBN: %d\n", livro.isbn);
          printf("Titulo: %s\n", livro.titulo);
          printf("Autor: %s\n", livro.autor);
}

void exibirLivros(void *dados) {
    Livro *livro = (Livro*) dados; 
    
    printf("ISBN: %d | Titulo: %s | Autor: %s\n", livro->isbn, livro->titulo, livro->autor);
}