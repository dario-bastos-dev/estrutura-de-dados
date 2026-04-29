#include <stdio.h>
#include "endereco.h"
#include "../core.h"

void cadastrarEndereco () { 
          Endereco endereco;

          printf("Digite a rua do endereco: ");
          scanf(" %[^\n]s", endereco.rua);    
          printf("Digite o numero do endereco: "); 
          scanf("%d", &endereco.numero);
          printf("Digite a cidade do endereco: "); 
          scanf(" %[^\n]s", endereco.cidade);

          printf("Cadastrando endereco...\n");
          int resultado = cadastrar(&endereco, sizeof(Endereco), "Endereco/enderecos.txt");
          if (resultado) {
              printf("Endereco cadastrado com sucesso!\n");
          } else {
              printf("Falha ao cadastrar endereco.\n");
              return;
          }

          printf("\nDados do Endereco:\n");
          printf("Rua: %s\n", endereco.rua);
          printf("Numero: %d\n", endereco.numero);
          printf("Cidade: %s\n", endereco.cidade);        
}

void exibirEnderecos(void *dados) {
    Endereco *endereco = (Endereco*) dados; 
    
    printf("Rua: %s | Numero: %d | Cidade: %s\n", endereco->rua, endereco->numero, endereco->cidade);
}