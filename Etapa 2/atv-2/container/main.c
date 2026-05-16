#include <stdlib.h>
#include <stdio.h>
#include "container.h"

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

    while (op != 5) { 
        system("cls");

        printf("Selecione uma opção: \n1 - Adicionar container\n2 - Desembargar container\n3 - Ver todos os containers\n4 - Ver próximo container\n5 - Encerrar\n");
        scanf("%d", &op);
        clearStdin();

        switch (op)
        {
        case 1:
            InserirContainer(&pilha);
            break;
        
        case 2:
            DesembargarContainer(&pilha);
            break;
            
        case 3:
            ExibirTodosContainers(pilha);
            break;    

        case 4:
            ExibirProximoContainer(pilha);
            break;   

        case 5:
            Esvaziar(&pilha);
            break;
        
        default:
            break;
        }
    }

    free(pilha);

    return 0;
}