#ifndef USUARIO_H
#define USUARIO_H

// Definição da estrutura Usuario
typedef struct {
    int id;
    char nome[100];
} Usuario;

// Protótipos das funções
void cadastrar_usuario(Usuario *usuario, int id);
void exibir_usuario(Usuario usuario);

#endif