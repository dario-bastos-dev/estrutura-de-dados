#ifndef PROFESSOR_H
#define PROFESSOR_H

typedef struct {
          int id;
          char nome[100];
          float salario;
} Professor;

void cadastrarProfessor();
void exibirProfessores(void *dados);

#endif