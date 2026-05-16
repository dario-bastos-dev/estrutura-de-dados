#include <stdlib.h>
#include <stdio.h>
#include "tarefas.h"

void clearStdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    system("cls");

    Pilha *pilha = IniciarPilha();
    int op = -1;

    if (pilha == NULL) {
    printf("Erro ao criar pilha.\n");
    return 1;
    }

    while (op != 3) { 
        system("cls");

        printf("Selecione uma opção: \n1 - Adicionar tarefa\n2 - Verificar próxima tarefa\n3 - Encerrar\n");
        scanf("%d", &op);
        clearStdin();

        switch (op)
        {
        case 1:
            InserirTarefa(&pilha);
            break;
        
        case 2:
            ExibirProximaTarefa(pilha);
            break;
            
        case 3:
            EsvaziarPilha(&pilha);
            break;
        
        default:
            break;
        }
    }

    free(pilha);

    return 0;
}