#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "menus.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        limpar_tela();
        printf("======================================\n");
        printf("      ESCOLHA UMA OPCAO        \n");
        printf("======================================\n");
        printf(" 1. Alunos\n");
        printf(" 2. Carros\n");
        printf(" 3. Clientes\n");
        printf(" 4. Conta Bancaria\n");
        printf(" 5. Endereco\n");
        printf(" 6. Filme\n");
        printf(" 7. Funcionario\n");
        printf(" 8. Livro\n");
        printf(" 9. Produto\n");
        printf("10. Professor\n");
        printf(" 0. SAIR\n");
        printf("======================================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            while(getchar() != '\n');
            opcao = -1;
        }

        switch(opcao) {
            case 1: menu_alunos(); break;
            case 2: menu_carros(); break;
            case 3: menu_clientes(); break;
            case 4: menu_conta_bancaria(); break;
            case 5: menu_endereco(); break;
            case 6: menu_filme(); break;
            case 7: menu_funcionario(); break;
            case 8: menu_livro(); break;
            case 9: menu_produto(); break;
            case 10: menu_professor(); break;
            case 0: 
                printf("\nEncerrando sistema...\nAte logo!\n"); 
                break;
            default: 
                printf("\nOpcao invalida!\n"); 
                pausar();
        }

    } while (opcao != 0);

    return 0;
}