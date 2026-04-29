#include <stdio.h>
#include <string.h>
#include "livro.h"

// Função para cadastrar um livro
void cadastrar_livro(Livro *livro, int codigo) {
    livro->codigo = codigo;
    livro->emprestado = 0;  // Livro começa disponível
    
    printf("Digite o título do livro: ");
    fflush(stdin);
    fgets(livro->titulo, 100, stdin);
    livro->titulo[strcspn(livro->titulo, "\n")] = '\0';
    
    printf("Digite o autor do livro: ");
    fflush(stdin);
    fgets(livro->autor, 100, stdin);
    livro->autor[strcspn(livro->autor, "\n")] = '\0';
    
    printf("\nLivro cadastrado com sucesso!\n");
}

// Função para exibir dados de um livro
void exibir_livro(Livro livro) {
    char status[20];
    if (livro.emprestado == 0) {
        strcpy(status, "Disponível");
    } else {
        strcpy(status, "Emprestado");
    }
    
    printf("  Código: %d | Título: %s | Autor: %s | Status: %s\n", 
           livro.codigo, livro.titulo, livro.autor, status);
}