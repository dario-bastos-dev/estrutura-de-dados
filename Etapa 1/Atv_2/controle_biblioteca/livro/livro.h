#ifndef LIVRO_H
#define LIVRO_H

// Definição da estrutura Livro
typedef struct {
    int codigo;
    char titulo[100];
    char autor[100];
    int emprestado;  // 0 = disponível, 1 = emprestado
} Livro;

// Protótipos das funções
void cadastrar_livro(Livro *livro, int codigo);
void exibir_livro(Livro livro);

#endif