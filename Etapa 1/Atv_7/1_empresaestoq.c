#include <stdio.h>

int main() {

    int i, j;
    float soma = 0;
    float somasetor;

    char *setores[3] = {"Financeiro", "Marketing", "RH"};

    char *produtos[3][3] = {
        {"Calculadora", "Planilha", "Relatorio"},
        {"Camera", "Notebook", "Banner"},
        {"Curriculo", "Contrato", "Ficha"}
    };

    int estoque[3][3] = {
        {15, 30, 20},
        {10, 8, 25},
        {40, 12, 18}
    };

    // Impressão da matriz
    printf("\nDados do estoque:\n");
    
    for(i = 0; i < 3; i++) {
        somasetor = 0;

        for(j = 0; j < 3; j++) {
            printf("Produto: %s", produtos[i][j]);
            printf(" | Setor: %s", setores[i]);
            printf(" | Estoque: %d\n", estoque[i][j]);

            soma += estoque[i][j];
            somasetor += estoque[i][j];
        }
        
        printf("Soma do setor %s: %.2f\n\n", setores[i], somasetor);
    }

    printf("Soma total do estoque: %.2f\n", soma);

    return 0;
}