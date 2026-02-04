#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
          int id;
          char nome[100];
          float nota1;
          float nota2;
} Aluno;

void cadastrarAluno();
void exibirAlunos(void *dados);

#endif