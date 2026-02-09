#include <stdio.h>
#include <string.h>
#include "emprestimo.h"

/* Função para registrar um empréstimo */
void registrar_emprestimo(Emprestimo *emprestimo, int codigo, int id_usuario, 
                          int codigo_livro, char *data) {
    emprestimo->codigo_emprestimo = codigo;
    emprestimo->id_usuario = id_usuario;
    emprestimo->codigo_livro = codigo_livro;
    strcpy(emprestimo->data_emprestimo, data);
    emprestimo->ativo = 1;  /* Empréstimo ativo */
}

/* Função para exibir dados de um empréstimo */
void exibir_emprestimo(Emprestimo emprestimo, Usuario usuarios[], 
                       int total_usuarios, Livro livros[], int total_livros) {
    int i;
    char nome_usuario[100] = "Não encontrado";
    char titulo_livro[100] = "Não encontrado";
    char status[20];
    
    /* Busca o nome do usuário */
    for (i = 0; i < total_usuarios; i++) {
        if (usuarios[i].id == emprestimo.id_usuario) {
            strcpy(nome_usuario, usuarios[i].nome);
            break;
        }
    }
    
    /* Busca o título do livro */
    for (i = 0; i < total_livros; i++) {
        if (livros[i].codigo == emprestimo.codigo_livro) {
            strcpy(titulo_livro, livros[i].titulo);
            break;
        }
    }
    
    if (emprestimo.ativo == 1) {
        strcpy(status, "Ativo");
    } else {
        strcpy(status, "Devolvido");
    }
    
    printf("  Cód. Empréstimo: %d | Usuário: %s | Livro: %s | Data: %s | Status: %s\n",
           emprestimo.codigo_emprestimo, nome_usuario, titulo_livro, 
           emprestimo.data_emprestimo, status);
}