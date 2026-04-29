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


// Contagem de números pares 
    int Pares= 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(matriz[i][j] % 2 == 0){
                Pares++;
            }
        }
    }

    printf("Quantidade de numeros pares: %d\n", Pares);

    return 0;
}