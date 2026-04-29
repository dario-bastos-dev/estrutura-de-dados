#ifndef ALUNO_H
#define ALUNO_H

// Definição da estrutura Aluno
typedef struct {
    int id;
    char nome[100];
    float nota;
} Aluno;

// Protótipos das funções
void cadastrar_aluno(Aluno *aluno, int id);
void exibir_aluno(Aluno aluno);

#endif