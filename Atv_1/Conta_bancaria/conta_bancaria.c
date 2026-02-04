#include <stdio.h>
#include "conta_bancaria.h"
#include "../core.h"

void cadastrarContaBancaria () { 
          ContaBancaria conta;

          printf("Digite o numero da conta: ");
          scanf("%d", &conta.numero);    
          printf("Digite o titular da conta: "); 
          scanf(" %[^\n]s", conta.titular);
          printf("Digite o saldo da conta: "); 
          scanf("%f", &conta.saldo);

          printf("Cadastrando conta bancaria...\n");
          int resultado = cadastrar(&conta, sizeof(ContaBancaria),"Conta_bancaria/contas_bancarias.txt"); 
          if (resultado) {
              printf("Conta bancaria cadastrada com sucesso!\n");
          } else {
              printf("Falha ao cadastrar conta bancaria.\n");
              return;
          }

          printf("\nDados da Conta Bancaria:\n");
          printf("Numero: %d\n", conta.numero);
          printf("Titular: %s\n", conta.titular);
          printf("Saldo: %.2f\n", conta.saldo);

}

void exibirContasBancarias(void *dados) {
    ContaBancaria *conta = (ContaBancaria*) dados; 
    
    printf("Numero: %d | Titular: %s | Saldo: %.2f\n", conta->numero, conta->titular, conta->saldo);
}