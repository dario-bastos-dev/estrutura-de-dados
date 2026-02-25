#include <stdio.h>
#include <stdlib.h>
#include "vetor/vetor.h"
#include "utils/utilidades.h"

int main() {
     // instanciando o vetor
     Vetor vetor;
     // Criando variáveis
     int posicao;
     int opcao;
     // Menu de opções
     limpar_tela();
     while (opcao != 0) {
          printf("\nMenu: ");
          printf("1. Criar vetor\n");
          printf("2. Exibir valor em uma posicao\n");
          printf("0. Sair\n");
          printf("Escolha uma opcao: ");
          scanf("%d", &opcao);
          switch (opcao)
          {
          case 1:
               limpar_tela();
               free(vetor.array);
               vetor.array = NULL;
               vetor.count = 0;
               vetor = *criarVetor(&vetor);
               limpar_tela();
               pausar();
               break;
          case 2:
               limpar_tela();
               if (vetor.array == NULL) {
                    printf("Vetor nao criado. Por favor, crie um vetor primeiro.\n");
                    break;
               }
               printf("Digite a posicao que deseja acessar: ");
               scanf("%d", &posicao);
               exibirValor(&vetor, posicao);
               pausar();
               limpar_tela();
               break;
          case 0:
               limpar_tela();
               printf("Saindo...\n");
               break;
          
          default:
               printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
          }
     }    

     free(vetor.array);

     return 0;
}