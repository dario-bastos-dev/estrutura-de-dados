#include <stdio.h>
#include <stdlib.h>
#include "core.h"
#include "menus.h"
#include "Livro/livro.h"
#include "Endereco/endereco.h"
#include "Aluno/aluno.h"
#include "Carro/carro.h"
#include "Cliente/cliente.h"
#include "Produto/produto.h"
#include "Funcionario/funcionario.h"
#include "Filme/filme.h"
#include "Professor/professor.h"
#include "Conta_bancaria/conta_bancaria.h"

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\nPressione ENTER para voltar...");
    getchar(); getchar();
}

void gerar_menu_padrao(char *titulo, void *entidade, size_t tamanho, char *arquivo, void (*funcSalvar)(void), void (*funcListar)(void *)) {
    int opcao;
    do {
        limpar_tela();
        printf("=== GESTAO DE %s ===\n", titulo);
        printf("1. Salvar %s\n", titulo);
        printf("2. Exibir %s\n", titulo);
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                funcSalvar(); 
                pausar();
                break;
            case 2:
                exibir(arquivo, tamanho, funcListar);
                pausar();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
                pausar();
        }
    } while (opcao != 0);
}

void menu_alunos() {
    Aluno aluno;
    gerar_menu_padrao("Alunos", &aluno, sizeof(Aluno), "Aluno/alunos.txt", cadastrarAluno, exibirAlunos);
}

void menu_carros() {
    Carro carro;
    gerar_menu_padrao("Carros", &carro, sizeof(Carro), "Carro/carros.txt", cadastrarCarro, exibirCarros);
}

void menu_clientes() {
    Cliente cliente;
    gerar_menu_padrao("Clientes", &cliente, sizeof(Cliente), "Cliente/clientes.txt", cadastrarCliente, exibirClientes);
}

void menu_conta_bancaria() {
    ContaBancaria conta;
    gerar_menu_padrao("Contas Bancarias", &conta, sizeof(ContaBancaria), "Conta_bancaria/contas_bancarias.txt", cadastrarContaBancaria, exibirContasBancarias);
}

void menu_endereco() {
    Endereco endereco;
    gerar_menu_padrao("Enderecos", &endereco, sizeof(Endereco), "Endereco/enderecos.txt", cadastrarEndereco, exibirEnderecos);
}

void menu_filme() {
    Filme filme;
    gerar_menu_padrao("Filmes", &filme, sizeof(Filme), "Filme/filmes.txt", cadastrarFilme, exibirFilmes);
}

void menu_funcionario() {
    Funcionario funcionario;
    gerar_menu_padrao("Funcionarios", &funcionario, sizeof(Funcionario), "Funcionario/funcionarios.txt", cadastrarFuncionario, exibirFuncionarios);
}

void menu_livro() {
    Livro livro;
    gerar_menu_padrao("Livros", &livro, sizeof(Livro), "Livro/livros.txt", cadastrarLivro, exibirLivros);
}

void menu_produto() {
    Produto produto;
    gerar_menu_padrao("Produtos", &produto, sizeof(Produto), "Produto/produtos.txt", cadastrarProduto, exibirProdutos);
}

void menu_professor() {
    Professor professor;
    gerar_menu_padrao("Professores", &professor, sizeof(Professor), "Professor/professores.txt", cadastrarProfessor, exibirProfessores);
}