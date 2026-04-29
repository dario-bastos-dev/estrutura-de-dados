#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "banco.h"

Fila *CriarFila() {
    Fila *fi = (Fila *)malloc(sizeof(Fila));

    if (fi == NULL) {
        printf("Erro ao criar ao alocar a memória da fila\n");
        return NULL;
    }

    fi->inicio = NULL;
    fi->fim = NULL;
    fi->total = 0;

    printf("Fila iniciada!\n");

    return fi;
}

void InserirCliente(Fila **fi, TempoAtendimento **temp) {
    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    
    time_t agora;
    time(&agora);

    if (novo == NULL) {
        printf("Erro ao criar ao alocar a memória do Cliente\n");
        return;
    }

    printf("\nDigite o número de identificação: \n");
    scanf("%d", &novo->id);
    novo->prox = NULL;

    // Adcionando novo cliente na fila
    if ((*fi)->inicio == NULL) {
        (*fi)->inicio = novo;
        (*fi)->fim = novo;
    } else {
        (*fi)->fim->prox = novo;
        (*fi)->fim = novo;
    }
    (*fi)->total++; // Incrementando contador

    // Salvando inicio do atendimento
    if ((*temp)->inicio == NULL) {
        (*temp)->inicio = (time_t *)malloc(sizeof(time_t));
        (*temp)->inicio[0] = agora;
        (*temp)->numb = 0;
    } else {
        (*temp)->numb++;
        (*temp)->inicio = (time_t *)realloc((*temp)->inicio, sizeof(time_t) * (*temp)->numb);
        (*temp)->inicio[(*temp)->numb] = agora;
    }
    
    printf("\nNovo cliente inserido.\n");

    printf("\nAperte qualquer tecla para voltar\n");

    getchar();
    getchar();

}

void ExibirFila(Fila *fi, TempoAtendimento *temp) {
     if (fi->inicio != NULL) {
        printf("Fila vazia!\n");
        
        // Exibir clientes restantes
        Cliente *cliente = fi->inicio;
        do
        {
            printf("Id do cliente: %d\n", cliente->id);
            cliente = cliente->prox;
        } while (cliente != NULL);
    }

    // Exibir tempo médio de atendimento
    int horas = (int)temp->media / 3600;
    int minutos = ((int)temp->media % 3600) / 60;
    int segundos = (int)temp->media % 60;

    printf("\nTempo médio: %02d:%02d:%02d\n", horas, minutos, segundos);

    printf("\nAperte qualquer tecla para voltar\n");
    
    getchar();
    getchar();

}

void RemoverCliente(Fila **fi, TempoAtendimento **temp) {
    static int atendidos = 0;

    time_t agora;
    time(&agora);

    if ((*fi)->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    // Salvar o tempo de finalização de atendimento
    if ((*temp)->fim == NULL) {
        (*temp)->fim = (time_t *)malloc(sizeof(time_t));
        (*temp)->fim[atendidos] = agora;
    } else {
        (*temp)->fim = (time_t *)realloc((*temp)->fim, sizeof(time_t) * (*temp)->numb);
        (*temp)->fim[atendidos] = agora;
    }

    // Calculando tempo médio do atendimento
    double mediaTotal = 0;
    for (int i = 0; i <= atendidos; i++) {
        mediaTotal += difftime((*temp)->fim[i], (*temp)->inicio[i]);
    }
    (*temp)->media = mediaTotal / (atendidos + 1);

    // removendo cliente
    printf("\nCliente removido: %d\n", (*fi)->inicio->id);

    Cliente *removeClient = (*fi)->inicio;
    (*fi)->inicio = (*fi)->inicio->prox;
    free(removeClient); 
    (*fi)->total--; // Decrementando contador
    
    if ((*fi)->inicio == NULL) {
        (*fi)->fim = NULL;
        printf("\nFila terminou.\n");
    }

    printf("\nAperte qualquer tecla para voltar\n");

    getchar();
    getchar();
}