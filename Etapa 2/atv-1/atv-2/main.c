#include <stdlib.h>
#include <stdio.h>
#include "banco.h"

int main(void) {
    // Limpando a tela
    system("cls");

    // Iniciando a fila
    Fila *fila = CriarFila();
    if (fila == NULL) return 1;

    // Iniciando histórico de atendimento
    TempoAtendimento *tempoAtendimento = (TempoAtendimento *)malloc(sizeof(TempoAtendimento));
    if (tempoAtendimento == NULL) {
        printf("Erro ao alocar memória");
        free(fila);
        return 1;
    }
    
    tempoAtendimento->inicio = NULL;
    tempoAtendimento->fim = NULL;
    tempoAtendimento->media = 0;
    tempoAtendimento->numb = 0;

    // Abrindo menu
    int op = -1;
    while (op != 0) {
        system("cls");
        printf("\n----------------------------\n");
        printf("ATENDIMENTO DE FILA DO BANCO\n");
        printf("----------------------------\n");
        printf("1. Adicionar novo cliente na fila\n");
        printf("2. Finalizar atendimento de um cliente na fila\n");
        printf("3. Conferir restante da fila\n");
        printf("0. Encerrar\n");
        scanf("%d", &op);

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
             if (fila != NULL && fila->total > 0) {
                printf("\nAinda há %d clientes na fila. Atenda-os antes de fechar!\n", fila->total);
                op = -1;

                getchar();
                getchar();
            
            } else {
                printf("\nEncerrando atendimento do banco...\n");
            }
        
            break;
        
        default:
            break;
        }
    }
    
    if(tempoAtendimento->inicio != NULL) free(tempoAtendimento->inicio);
    if(tempoAtendimento->fim != NULL)free(tempoAtendimento->fim);
    free(tempoAtendimento);
    free(fila);
    return 0;
}