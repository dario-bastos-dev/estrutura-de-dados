#include <stdio.h>
#include <stdlib.h>
#include "utilidades/utilidades.h"
#include "lista/lista.h"

int main() {

    // Inicializando a lista com vetor NULL e contador 0
    Lista lista = { NULL, 0 };
    
    int n, valor;

    limpar_tela();
    printf("==================================\n");
    printf("Ordenacao e compactacao de numeros\n");
    printf("==================================\n");

    // Lê a quantidade de valores
    printf("\nQuantos numeros deseja inserir? ");
    scanf("%d", &n);

    // Lê os N valores e armazena no vetor
    for (int i = 0; i < n; i++) {
        printf("Digite o %d° numero: ", i + 1);
        scanf("%d", &valor);
        adicionarElemento(&lista, valor);
    }

    // Mostra o vetor ANTES da remoção
    printf("\n--- Vetor ANTES da remocao de duplicatas ---\n");
    imprimirLista(&lista);

    // Remove duplicatas e compacta
    removerDuplicatas(&lista);
    compactarLista(&lista);

    // Mostra o vetor APÓS a compactação
    printf("\n--- Vetor APOS a compactacao ---\n");
    imprimirLista(&lista);

    // Libera a memória
    liberarLista(&lista);

    pausar();
    return 0;
}