#include <stdlib.h>
#include <stdio.h>
#include "banco.h"

int main(void) {
    // Limpando a tela
    system("cls");

    // Iniciando a fila
    Fila *fila = CriarFila();

    // Iniciando histórico de atendimento
    TempoAtendimento *tempoAtendimento;
    tempoAtendimento->inicio = NULL;
    tempoAtendimento->fim = NULL;
    tempoAtendimento->media = 0;
    tempoAtendimento->numb = 0;

    // Abrindo menu
    int op;
    while (op != 0) {
        printf("----------------------------");
        printf("ATENDIMENTO DE FILA DO BANCO");
        printf("----------------------------");
        printf("1. Adicionar novo cliente na fila");
        printf("2. Finalizar atendimento de um cliente na fila");
        printf("3. Conferir restante da fila");
        printf("0. Encerrar");
        scanf(&op);

        switch (op)
        {
        case 1:
            InserirCliente(&fila, &tempoAtendimento);
            break;
            
        case 2:
            RemoverCliente(&fila, &tempoAtendimento);
            break;
        
        case 3:
            ExibirFila(fila, tempoAtendimento);
            break;
            
        case 0:
            printf("\nEncerrando atendimento do banco...\n");
            break;
        
        default:
            break;
        }
    }
    
    free(fila);
    free(tempoAtendimento);
    return 0;
}