#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro/livro.h"
#include "usuario/usuario.h"
#include "emprestimo/emprestimo.h"
#include "utilidades/utilidades.h"

#define MAX_LIVROS 50
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 100

/* Função para exibir o menu principal */
void exibir_menu() {
    printf("\n========================================\n");
    printf("  SISTEMA DE CONTROLE DE BIBLIOTECA\n");
    printf("========================================\n");
    printf("1. Cadastrar Usuário\n");
    printf("2. Cadastrar Livro\n");
    printf("3. Registrar Empréstimo\n");
    printf("4. Registrar Devolução\n");
    printf("5. Listar Todos os Usuários\n");
    printf("6. Listar Todos os Livros\n");
    printf("7. Listar Empréstimos por Usuário\n");
    printf("8. Listar Todos os Empréstimos\n");
    printf("9. Sair\n");
    printf("========================================\n");
    printf("Escolha uma opção: ");
}

int main() {
    Usuario usuarios[MAX_USUARIOS];
    Livro livros[MAX_LIVROS];
    Emprestimo emprestimos[MAX_EMPRESTIMOS];
    
    int total_usuarios = 0;
    int total_livros = 0;
    int total_emprestimos = 0;
    
    int opcao, id_usuario, codigo_livro;
    char data[11];
    
    /* Variáveis auxiliares declaradas no início */
    int i, j;
    int novo_id, novo_codigo, novo_codigo_emp;
    int usuario_encontrado, livro_encontrado, emprestimo_encontrado;
    int indice_livro, codigo_emp;
    int tem_livro_disponivel, tem_emprestimo_ativo, encontrou;
    
    do {
        limpar_tela();
        exibir_menu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:  /* Cadastrar Usuário */
                limpar_tela();
                printf("\n=== CADASTRAR USUÁRIO ===\n");
                
                if (total_usuarios >= MAX_USUARIOS) {
                    printf("\nLimite de usuários atingido!\n");
                } else {
                    novo_id = total_usuarios + 1;
                    cadastrar_usuario(&usuarios[total_usuarios], novo_id);
                    total_usuarios++;
                }
                
                pausar();
                break;
                
            case 2:  /* Cadastrar Livro */
                limpar_tela();
                printf("\n=== CADASTRAR LIVRO ===\n");
                
                if (total_livros >= MAX_LIVROS) {
                    printf("\nLimite de livros atingido!\n");
                } else {
                    novo_codigo = total_livros + 1;
                    cadastrar_livro(&livros[total_livros], novo_codigo);
                    total_livros++;
                }
                
                pausar();
                break;
                
            case 3:  /* Registrar Empréstimo */
                limpar_tela();
                printf("\n=== REGISTRAR EMPRÉSTIMO ===\n");
                
                if (total_usuarios == 0) {
                    printf("\nNenhum usuário cadastrado!\n");
                } else if (total_livros == 0) {
                    printf("\nNenhum livro cadastrado!\n");
                } else {
                    /* Lista usuários */
                    printf("\nUsuários cadastrados:\n");
                    for (i = 0; i < total_usuarios; i++) {
                        exibir_usuario(usuarios[i]);
                    }
                    
                    printf("\nDigite o ID do usuário: ");
                    scanf("%d", &id_usuario);
                    
                    /* Valida usuário */
                    usuario_encontrado = 0;
                    for (i = 0; i < total_usuarios; i++) {
                        if (usuarios[i].id == id_usuario) {
                            usuario_encontrado = 1;
                            break;
                        }
                    }
                    
                    if (!usuario_encontrado) {
                        printf("\nUsuário não encontrado!\n");
                    } else {
                        /* Lista livros disponíveis */
                        printf("\nLivros disponíveis:\n");
                        tem_livro_disponivel = 0;
                        for (i = 0; i < total_livros; i++) {
                            if (livros[i].emprestado == 0) {
                                exibir_livro(livros[i]);
                                tem_livro_disponivel = 1;
                            }
                        }
                        
                        if (!tem_livro_disponivel) {
                            printf("Nenhum livro disponível no momento.\n");
                        } else {
                            printf("\nDigite o código do livro: ");
                            scanf("%d", &codigo_livro);
                            
                            /* Valida livro */
                            livro_encontrado = 0;
                            indice_livro = -1;
                            for (i = 0; i < total_livros; i++) {
                                if (livros[i].codigo == codigo_livro) {
                                    livro_encontrado = 1;
                                    indice_livro = i;
                                    break;
                                }
                            }
                            
                            if (!livro_encontrado) {
                                printf("\nLivro não encontrado!\n");
                            } else if (livros[indice_livro].emprestado == 1) {
                                printf("\nLivro já está emprestado!\n");
                            } else {
                                printf("Digite a data do empréstimo (dd/mm/aaaa): ");
                                scanf("%s", data);
                                
                                /* Registra o empréstimo */
                                novo_codigo_emp = total_emprestimos + 1;
                                registrar_emprestimo(&emprestimos[total_emprestimos], 
                                                    novo_codigo_emp, id_usuario, 
                                                    codigo_livro, data);
                                
                                /* Marca o livro como emprestado */
                                livros[indice_livro].emprestado = 1;
                                
                                total_emprestimos++;
                                
                                printf("\nEmpréstimo registrado com sucesso!\n");
                            }
                        }
                    }
                }
                
                pausar();
                break;
                
            case 4:  /* Registrar Devolução */
                limpar_tela();
                printf("\n=== REGISTRAR DEVOLUÇÃO ===\n");
                
                if (total_emprestimos == 0) {
                    printf("\nNenhum empréstimo registrado!\n");
                } else {
                    /* Lista empréstimos ativos */
                    printf("\nEmpréstimos ativos:\n");
                    tem_emprestimo_ativo = 0;
                    for (i = 0; i < total_emprestimos; i++) {
                        if (emprestimos[i].ativo == 1) {
                            exibir_emprestimo(emprestimos[i], usuarios, 
                                            total_usuarios, livros, total_livros);
                            tem_emprestimo_ativo = 1;
                        }
                    }
                    
                    if (!tem_emprestimo_ativo) {
                        printf("Nenhum empréstimo ativo no momento.\n");
                    } else {
                        printf("\nDigite o código do empréstimo: ");
                        scanf("%d", &codigo_emp);
                        
                        emprestimo_encontrado = 0;
                        for (i = 0; i < total_emprestimos; i++) {
                            if (emprestimos[i].codigo_emprestimo == codigo_emp && 
                                emprestimos[i].ativo == 1) {
                                
                                /* Marca empréstimo como devolvido */
                                emprestimos[i].ativo = 0;
                                
                                /* Marca livro como disponível */
                                for (j = 0; j < total_livros; j++) {
                                    if (livros[j].codigo == emprestimos[i].codigo_livro) {
                                        livros[j].emprestado = 0;
                                        break;
                                    }
                                }
                                
                                emprestimo_encontrado = 1;
                                printf("\nDevolução registrada com sucesso!\n");
                                break;
                            }
                        }
                        
                        if (!emprestimo_encontrado) {
                            printf("\nEmpréstimo não encontrado ou já devolvido!\n");
                        }
                    }
                }
                
                pausar();
                break;
                
            case 5:  /* Listar Todos os Usuários */
                limpar_tela();
                printf("\n=== TODOS OS USUÁRIOS ===\n");
                
                if (total_usuarios == 0) {
                    printf("\nNenhum usuário cadastrado!\n");
                } else {
                    for (i = 0; i < total_usuarios; i++) {
                        exibir_usuario(usuarios[i]);
                    }
                }
                
                pausar();
                break;
                
            case 6:  /* Listar Todos os Livros */
                limpar_tela();
                printf("\n=== TODOS OS LIVROS ===\n");
                
                if (total_livros == 0) {
                    printf("\nNenhum livro cadastrado!\n");
                } else {
                    for (i = 0; i < total_livros; i++) {
                        exibir_livro(livros[i]);
                    }
                }
                
                pausar();
                break;
                
            case 7:  /* Listar Empréstimos por Usuário */
                limpar_tela();
                printf("\n=== EMPRÉSTIMOS POR USUÁRIO ===\n");
                
                if (total_usuarios == 0) {
                    printf("\nNenhum usuário cadastrado!\n");
                } else if (total_emprestimos == 0) {
                    printf("\nNenhum empréstimo registrado!\n");
                } else {
                    printf("\nUsuários cadastrados:\n");
                    for (i = 0; i < total_usuarios; i++) {
                        exibir_usuario(usuarios[i]);
                    }
                    
                    printf("\nDigite o ID do usuário: ");
                    scanf("%d", &id_usuario);
                    
                    printf("\n=== Empréstimos do Usuário %d ===\n", id_usuario);
                    encontrou = 0;
                    for (i = 0; i < total_emprestimos; i++) {
                        if (emprestimos[i].id_usuario == id_usuario) {
                            exibir_emprestimo(emprestimos[i], usuarios, 
                                            total_usuarios, livros, total_livros);
                            encontrou = 1;
                        }
                    }
                    
                    if (!encontrou) {
                        printf("Nenhum empréstimo encontrado para este usuário.\n");
                    }
                }
                
                pausar();
                break;
                
            case 8:  /* Listar Todos os Empréstimos */
                limpar_tela();
                printf("\n=== TODOS OS EMPRÉSTIMOS ===\n");
                
                if (total_emprestimos == 0) {
                    printf("\nNenhum empréstimo registrado!\n");
                } else {
                    for (i = 0; i < total_emprestimos; i++) {
                        exibir_emprestimo(emprestimos[i], usuarios, 
                                        total_usuarios, livros, total_livros);
                    }
                }
                
                pausar();
                break;
                
            case 9:  /* Sair */
                printf("\nEncerrando o sistema...\n");
                break;
                
            default:
                printf("\nOpção inválida!\n");
                pausar();
        }
        
    } while(opcao != 9);
    
    return 0;
}