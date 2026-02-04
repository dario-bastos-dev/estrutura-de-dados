#include <stdio.h>
#include <stdlib.h>
#include "core.h" 

int cadastrar (void *caixa, int tamanho, char *arquivo) { 

          FILE *file = fopen(arquivo, "ab");
           if (file == NULL) {
                    printf("Erro Crítico: Não foi possível abrir o arquivo para escrita!\n");
                    return 0;
          }
          fwrite(caixa, tamanho, 1, file);
          fclose(file);
          return 1;
      
}

void exibir(char *arquivo, int tamanho, void (*imprimir)(void*)) {
          FILE *file = fopen(arquivo, "rb");
          if (file == NULL) {
                    printf("Aviso: Nenhum dado encontrado (o arquivo ainda nao existe).\n");
                    return;
          }

          void *buffer = malloc(tamanho);

          while (fread(buffer, tamanho, 1, file)) {
                    imprimir(buffer);    
          }

          free(buffer);
          fclose(file);
           
};