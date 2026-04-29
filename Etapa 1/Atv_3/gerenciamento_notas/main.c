#include <stdio.h>
#include <stdlib.h>
#include "nota/nota.h"
#include "utilidades/utilidades.h"

int main() {
    /* Inicializa a estrutura Nota */
    Nota nota;  
    nota.notas = NULL;
    nota.media = 0;
    nota.maior = 0;
    nota.menor = 0;
    nota.cont = 0;

    int opcao;

    printf("======================\n");
    printf("Gerenciamento de Notas\n");
    printf("======================\n");
    while (opcao != 0)
    {
          printf("\nMenu:\n");
          printf("1. Adicionar nota\n");
          printf("2. Mostrar notas\n");
          printf("0. Sair\n");
          printf("Escolha uma opcao: ");
          scanf("%d", &opcao);
          
          switch (opcao) {
              case 1:
                    limpar_tela();
                    float valor;
                    printf("Digite a nota a ser adicionada: ");
                    scanf("%f", &valor);
                    adicionarNota(&nota, valor);
                    pausar();
                    break;
              case 2:
                    limpar_tela();
                    mostrarNotas(&nota);
                    pausar();
                    break;
              case 0:
                    limpar_tela();
                    printf("Saindo...\n");
                    break;
              default:
                    printf("Opção inválida. Tente novamente.\n");
          }
    }

    free(nota.notas);
    
    return 0;
}