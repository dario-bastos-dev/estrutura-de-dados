#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"

/* Função para limpar a tela */
void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/* Função para pausar e aguardar entrada do usuário */
void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}