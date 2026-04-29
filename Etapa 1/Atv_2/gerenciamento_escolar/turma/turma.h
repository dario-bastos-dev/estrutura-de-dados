#ifndef TURMA_H
#define TURMA_H

#include "../aluno/aluno.h"

#define MAX_ALUNOS 50  // Máximo de alunos por turma

// Definição da estrutura Turma
typedef struct {
    int codigo;
    char nome[100];
    int quantidade_alunos;
    Aluno alunos[MAX_ALUNOS];
} Turma;

// Protótipos das funções
void cadastrar_turma(Turma *turma, int codigo);
void associar_aluno_turma(Turma *turma);
void listar_alunos_turma(Turma turma);
void exibir_turma(Turma turma);

#endif