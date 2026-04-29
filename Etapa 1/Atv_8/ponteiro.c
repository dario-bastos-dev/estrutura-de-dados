#include <stdio.h>
#include <stdlib.h>

void allocate_vector(int **ptr, int *size) {
    printf("Digite o tamanho do vetor: ");
    scanf("%d", size);
    
    *ptr = (int *)calloc(*size, sizeof(int));
    if (*ptr == NULL) {
        printf("Erro na alocação!\n");
        exit(1);
    }
}

void fill_vector(int *ptr, int size) {
    printf("Digite %d valores:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &ptr[i]);
    }
}

void display_vector(int *ptr, int size) {
    printf("Valores do vetor: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

int main() {
    int *vector = NULL;
    int size = 0;
    
    allocate_vector(&vector, &size);
    fill_vector(vector, size);
    display_vector(vector, size);
    
    int new_size;
    printf("Digite o novo tamanho do vetor: ");
    scanf("%d", &new_size);
    
    vector = (int *)realloc(vector, new_size * sizeof(int));
    if (vector == NULL) {
        printf("Erro no realloc!\n");
        exit(1);
    }
    
    if (new_size > size) {
        for (int i = size; i < new_size; i++) {
            vector[i] = 0;
        }
    }
    
    printf("Digite os %d valores para o novo vetor:\n", new_size);
    fill_vector(vector, new_size);
    display_vector(vector, new_size);
    
    free(vector);
    vector = NULL;
    
    return 0;
}