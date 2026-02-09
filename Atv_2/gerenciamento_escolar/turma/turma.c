#include <stdio.h>
#include <string.h>
#include "turma.h"

/* Função para cadastrar uma turma */
void cadastrar_turma(Turma *turma, int codigo) {
    turma->codigo = codigo;
    turma->quantidade_alunos = 0;  /* Inicia sem alunos */
    
    printf("Digite o nome da turma: ");
    fflush(stdin);
    fgets(turma->nome, 100, stdin);
    turma->nome[strcspn(turma->nome, "\n")] = '\0';
    
    printf("\nTurma cadastrada com sucesso!\n");
}

/* Função para associar (cadastrar) um aluno em uma turma */
void associar_aluno_turma(Turma *turma) {
    int novo_id;
    
    if (turma->quantidade_alunos >= MAX_ALUNOS) {
        printf("\nTurma cheia! Não é possível adicionar mais alunos.\n");
        return;
    }
    
    printf("\n=== Cadastrar Aluno na Turma %s ===\n", turma->nome);
    
    /* Gera um ID automático baseado na quantidade atual */
    novo_id = turma->quantidade_alunos + 1;
    
    /* Cadastra o aluno no vetor de alunos da turma */
    cadastrar_aluno(&turma->alunos[turma->quantidade_alunos], novo_id);
    
    turma->quantidade_alunos++;
    
    printf("\nAluno cadastrado e associado à turma com sucesso!\n");
}

/* Função para listar todos os alunos de uma turma */
void listar_alunos_turma(Turma turma) {
    int i;
    
    printf("\n=== Alunos da Turma: %s ===\n", turma.nome);
    printf("Código da Turma: %d\n", turma.codigo);
    printf("Total de alunos: %d\n\n", turma.quantidade_alunos);
    
    if (turma.quantidade_alunos == 0) {
        printf("Nenhum aluno cadastrado nesta turma.\n");
        return;
    }
    
    for (i = 0; i < turma.quantidade_alunos; i++) {
        exibir_aluno(turma.alunos[i]);
    }
}

/* Função para exibir informações resumidas da turma */
void exibir_turma(Turma turma) {
    printf("  Código: %d | Nome: %s | Alunos: %d\n", 
           turma.codigo, turma.nome, turma.quantidade_alunos);
}