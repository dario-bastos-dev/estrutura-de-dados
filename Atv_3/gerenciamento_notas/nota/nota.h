#ifndef NOTA_H
#define NOTA_H

typedef struct {
    float *notas;
    float media;
    float maior;
    float menor;
    int cont;
} Nota;

void adicionarNota(Nota *nota, float valor);
void mostrarNotas(Nota *nota);

#endif