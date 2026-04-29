#include <stdio.h>
#include "aluno.h"
#include "../core.h"

void cadastrarAluno () { 
          Aluno aluno;

          printf("Digite o ID do aluno: ");
          scanf("%d", &aluno.id);    
          printf("Digite o nome do aluno: "); 
          scanf(" %[^\n]s", aluno.nome);
          printf("Digite a primeira nota do aluno: "); 
          scanf("%f", &aluno.nota1);
          printf("Digite a segunda nota do aluno: "); 
          scanf("%f", &aluno.nota2);

          printf("Cadastrando aluno...\n");
          int resultado = cadastrar(&aluno, sizeof(Aluno), "Aluno/alunos.txt");
          if (resultado) {
              printf("Aluno cadastrado com sucesso!\n");
          } else {
              printf("Falha ao cadastrar aluno.\n");
              return;
          }

          printf("\nDados do aluno cadastrado:\n");
          printf("ID: %d\n", aluno.id);
          printf("Nome: %s\n", aluno.nome);
          printf("Nota 1: %.2f\n", aluno.nota1);
          printf("Nota 2: %.2f\n", aluno.nota2);
          printf("Media das notas: %.2f\n", (aluno.nota1 + aluno.nota2) / 2);
      
}

void exibirAlunos(void *dados) {
    Aluno *aluno = (Aluno*) dados; 
    
    printf("Id: %d | Nome: %s | Nota 1: %.2f | Nota 2: %.2f | Media: %.2f\n", aluno->id, aluno->nome, aluno->nota1, aluno->nota2, (aluno->nota1 + aluno->nota2) / 2);
}