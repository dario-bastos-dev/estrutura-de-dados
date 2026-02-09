#include <stdio.h>
#include <stdlib.h>
#include "aluno/aluno.h"
#include "turma/turma.h"
#include "utilidades/utilidades.h"

#define MAX_TURMAS 10

/* Função para exibir o menu principal */
void exibir_menu() {
    printf("\n========================================\n");
    printf("  SISTEMA DE GERENCIAMENTO ESCOLAR\n");
    printf("========================================\n");
    printf("1. Cadastrar Turma\n");
    printf("2. Cadastrar Aluno em uma Turma\n");
    printf("3. Listar Alunos de uma Turma\n");
    printf("4. Listar Todas as Turmas\n");
    printf("5. Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

int main() {
    Turma turmas[MAX_TURMAS];
    int total_turmas = 0;
    int opcao, codigo_turma;
    
    /* Variáveis auxiliares declaradas no início */
    int i;
    int novo_codigo;
    
    do {
        limpar_tela();
        exibir_menu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:  /* Cadastrar Turma */
                limpar_tela();
                printf("\n=== CADASTRAR TURMA ===\n");
                
                if (total_turmas >= MAX_TURMAS) {
                    printf("\nLimite de turmas atingido!\n");
                } else {
                    novo_codigo = total_turmas + 1;
                    cadastrar_turma(&turmas[total_turmas], novo_codigo);
                    total_turmas++;
                }
                
                pausar();
                break;
                
            case 2:  /* Cadastrar Aluno em uma Turma */
                limpar_tela();
                printf("\n=== CADASTRAR ALUNO ===\n");
                
                if (total_turmas == 0) {
                    printf("\nNenhuma turma cadastrada! Cadastre uma turma primeiro.\n");
                } else {
                    printf("\nTurmas disponíveis:\n");
                    for (i = 0; i < total_turmas; i++) {
                        exibir_turma(turmas[i]);
                    }
                    
                    printf("\nDigite o código da turma: ");
                    scanf("%d", &codigo_turma);
                    
                    if (codigo_turma < 1 || codigo_turma > total_turmas) {
                        printf("\nTurma não encontrada!\n");
                    } else {
                        associar_aluno_turma(&turmas[codigo_turma - 1]);
                    }
                }
                
                pausar();
                break;
                
            case 3:  /* Listar Alunos de uma Turma */
                limpar_tela();
                
                if (total_turmas == 0) {
                    printf("\nNenhuma turma cadastrada!\n");
                } else {
                    printf("\nTurmas disponíveis:\n");
                    for (i = 0; i < total_turmas; i++) {
                        exibir_turma(turmas[i]);
                    }
                    
                    printf("\nDigite o código da turma: ");
                    scanf("%d", &codigo_turma);
                    
                    if (codigo_turma < 1 || codigo_turma > total_turmas) {
                        printf("\nTurma não encontrada!\n");
                    } else {
                        listar_alunos_turma(turmas[codigo_turma - 1]);
                    }
                }
                
                pausar();
                break;
                
            case 4:  /* Listar Todas as Turmas */
                limpar_tela();
                printf("\n=== TODAS AS TURMAS ===\n");
                
                if (total_turmas == 0) {
                    printf("\nNenhuma turma cadastrada!\n");
                } else {
                    for (i = 0; i < total_turmas; i++) {
                        exibir_turma(turmas[i]);
                    }
                }
                
                pausar();
                break;
                
            case 5:  /* Sair */
                printf("\nEncerrando o sistema...\n");
                break;
                
            default:
                printf("\nOpção inválida!\n");
                pausar();
        }
        
    } while(opcao != 5);
    
    return 0;
}