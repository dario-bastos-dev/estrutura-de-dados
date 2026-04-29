#include <stdio.h>
#include "filme.h"
#include "../core.h"

void cadastrarFilme () { 
          Filme filme;

          printf("Digite o titulo do filme: ");
          scanf(" %[^\n]s", filme.titulo);
          printf("Digite o genero do filme: "); 
          scanf(" %[^\n]s", filme.genero);
          printf("Digite a duracao do filme: "); 
          scanf("%d", &filme.duracao);

          printf("Cadastrando filme...\n");
          int resultado = cadastrar(&filme, sizeof(Filme), "Filme/filmes.txt");
          if (resultado) {
              printf("Filme cadastrado com sucesso!\n");
          } else {
              printf("Falha ao cadastrar filme.\n");
              return;
          }

          printf("\nDados do Filme:\n");
          printf("Titulo: %s\n", filme.titulo);
          printf("Genero: %s\n", filme.genero);
          printf("Duracao: %d\n", filme.duracao);
}

void exibirFilmes(void *dados) {
    Filme *filme = (Filme*) dados; 
    
    printf("Titulo: %s | Genero: %s | Duracao: %d minutos\n", filme->titulo, filme->genero, filme->duracao);
}