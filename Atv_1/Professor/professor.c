#include <stdio.h>
#include "professor.h"
#include "../core.h"

void cadastrarProfessor () { 
          Professor prof;

          printf("Digite o ID do professor: ");
          scanf("%d", &prof.id);    
          printf("Digite o nome do professor: "); 
          scanf(" %[^\n]s", prof.nome);
          printf("Digite o salario do professor: "); 
          scanf("%f", &prof.salario);

          printf("Cadastrando professor...\n");
          int resultado = cadastrar(&prof, sizeof(Professor), "Professor/professores.txt");
          if (resultado) {
              printf("Professor cadastrado com sucesso!\n");
          } else {
              printf("Falha ao cadastrar professor.\n");
              return;
          }

          printf("\nDados do Professor:\n");
          printf("ID: %d\n", prof.id);
          printf("Nome: %s\n", prof.nome);
          printf("Salario: %.2f\n", prof.salario);     
}

void exibirProfessores(void *dados) {
    Professor *prof = (Professor*) dados; 
    
    printf("ID: %d | Nome: %s | Salario: %.2f\n", prof->id, prof->nome, prof->salario);
}