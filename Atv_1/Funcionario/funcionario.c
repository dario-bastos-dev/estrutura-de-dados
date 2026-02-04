#include <stdio.h>
#include "funcionario.h"
#include "../core.h"

void cadastrarFuncionario () { 
          Funcionario funcionario;

          printf("Digite a matricula do funcionario: ");
          scanf("%d", &funcionario.matricula);    
          printf("Digite o nome do funcionario: "); 
          scanf(" %[^\n]s", funcionario.nome);
          printf("Digite o salario do funcionario: "); 
          scanf("%f", &funcionario.salario);

          printf("Cadastrando funcionario...\n");
          int resultado = cadastrar(&funcionario, sizeof(Funcionario), "Funcionario/funcionarios.txt");
          if (resultado) {
              printf("Funcionario cadastrado com sucesso!\n");
          } else {
              printf("Falha ao cadastrar funcionario.\n");
              return;
          }
          printf("\nDados do Funcionario:\n");
          printf("Matricula: %d\n", funcionario.matricula);
          printf("Nome: %s\n", funcionario.nome);
          printf("Salario: %.2f\n", funcionario.salario);
}

void exibirFuncionarios(void *dados) {
    Funcionario *funcionario = (Funcionario*) dados; 
    
    printf("Matricula: %d | Nome: %s | Salario: %.2f\n", funcionario->matricula, funcionario->nome, funcionario->salario);
}
          