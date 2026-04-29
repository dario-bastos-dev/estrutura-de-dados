#include <stdio.h>
#include <string.h>
#include "aluno.h"

// Função para cadastrar um aluno
void cadastrar_aluno(Aluno *aluno, int id) {
    aluno->id = id;
    
    printf("Digite o nome do aluno: ");
    fflush(stdin);  // Limpa o buffer
    fgets(aluno->nome, 100, stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0';  // Remove o \n
    
    printf("Digite a nota do aluno: ");
    scanf("%f", &aluno->nota);
}

// Função para exibir dados de um aluno
void exibir_aluno(Aluno aluno) {
    printf("  ID: %d | Nome: %s | Nota: %.2f\n", 
           aluno.id, aluno.nome, aluno.nota);
}