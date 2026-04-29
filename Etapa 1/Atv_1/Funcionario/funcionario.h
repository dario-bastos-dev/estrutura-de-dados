#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct {
          int matricula;
          char nome[100];
          float salario;
} Funcionario;

void cadastrarFuncionario();
void exibirFuncionarios(void *dados);

#endif