#include <stdio.h>
#include "carro.h"
#include "../core.h"

void cadastrarCarro () { 
          Carro carro;

          printf("Digite a placa do carro: ");
          scanf("%6s", carro.placa);    
          printf("Digite o modelo do carro: "); 
          scanf(" %[^\n]s", carro.modelo);
          printf("Digite o ano do carro: "); 
          scanf("%d", &carro.ano);

          printf("Cadastrando carro...\n");
          int resultado = cadastrar(&carro, sizeof(Carro), "Carro/carros.txt");
          if (resultado) {
              printf("Carro cadastrado com sucesso!\n");
          } else {
              printf("Falha ao cadastrar carro.\n");
              return;
          }

          printf("\nDados do Carro cadastrado:\n");
          printf("Placa: %s\n", carro.placa);
          printf("Modelo: %s\n", carro.modelo);
          printf("Ano: %d\n", carro.ano);
}

void exibirCarros(void *dados) {
    Carro *carro = (Carro*) dados; 
    
    printf("Placa: %s | Modelo: %s | Ano: %d\n", carro->placa, carro->modelo, carro->ano);
}