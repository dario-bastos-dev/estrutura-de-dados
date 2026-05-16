#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int main(void) {
    system("cls");

    Pilha *pilha = CriarPilha();

    if (pilha == NULL) {
    printf("Erro ao criar fila\n");
    return 1;
    }

    InserirElemento(&pilha);
    InserirElemento(&pilha);
    InserirElemento(&pilha);
    ExibirPilha(pilha);
    Removerelemento(&pilha);
    ExibirPilha(pilha);
    Removerelemento(&pilha);
    ExibirPilha(pilha);
    Removerelemento(&pilha);
    ExibirPilha(pilha);

    free(pilha);

    return 0;
}