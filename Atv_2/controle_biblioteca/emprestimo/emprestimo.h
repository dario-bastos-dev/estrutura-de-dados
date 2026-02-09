#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "../livro/livro.h"
#include "../usuario/usuario.h"

// Definição da estrutura Emprestimo
typedef struct {
    int codigo_emprestimo;
    int id_usuario;
    int codigo_livro;
    char data_emprestimo[11];  // Formato: dd/mm/aaaa
    int ativo;  // 1 = empréstimo ativo, 0 = devolvido
} Emprestimo;

// Protótipos das funções
void registrar_emprestimo(Emprestimo *emprestimo, int codigo, int id_usuario, 
                          int codigo_livro, char *data);
void exibir_emprestimo(Emprestimo emprestimo, Usuario usuarios[], 
                       int total_usuarios, Livro livros[], int total_livros);

#endif