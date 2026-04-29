#include <stdio.h>
#include <stdlib.h> 

int main(){

int matriz[3][3];
int i, j;

    printf("Digite os elementos da matriz 3x3:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

//Soma dos elementos da matriz
    int soma = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            soma += matriz[i][j];
        }
    }

    printf("Soma dos elementos da matriz: %d\n", soma);

    return 0;
}