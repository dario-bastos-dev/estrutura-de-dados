#include <stdio.h>
#include <string.h>
#include "usuario.h"

// Função para cadastrar um usuário
void cadastrar_usuario(Usuario *usuario, int id) {
    usuario->id = id;
    
    printf("Digite o nome do usuário: ");
    fflush(stdin);
    fgets(usuario->nome, 100, stdin);
    usuario->nome[strcspn(usuario->nome, "\n")] = '\0';
    
    printf("\nUsuário cadastrado com sucesso!\n");
}

// Função para exibir dados de um usuário
void exibir_usuario(Usuario usuario) {
    printf("  ID: %d | Nome: %s\n", usuario.id, usuario.nome);
}