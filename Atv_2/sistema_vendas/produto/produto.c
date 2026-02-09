#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "produto.h"
#include "../json/cJSON.h"

/* Função para carregar produtos do arquivo JSON usando cJSON */
int carregar_produtos_json(const char *arquivo, Produto produtos[]) {
    FILE *fp;
    long tamanho_arquivo;
    char *conteudo_json;
    cJSON *json_root;
    cJSON *item;
    cJSON *campo;
    int count = 0;
    int i;
    int array_size;
    
    /* Abre o arquivo JSON */
    fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo);
        return 0;
    }
    
    /* Descobre o tamanho do arquivo */
    fseek(fp, 0, SEEK_END);
    tamanho_arquivo = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    /* Aloca memória para o conteúdo */
    conteudo_json = (char*)malloc(tamanho_arquivo + 1);
    if (conteudo_json == NULL) {
        printf("Erro ao alocar memória\n");
        fclose(fp);
        return 0;
    }
    
    /* Lê o conteúdo do arquivo */
    fread(conteudo_json, 1, tamanho_arquivo, fp);
    conteudo_json[tamanho_arquivo] = '\0';
    fclose(fp);
    
    printf("\nCarregando produtos do arquivo JSON usando cJSON...\n");
    
    /* Faz o parse do JSON */
    json_root = cJSON_Parse(conteudo_json);
    if (json_root == NULL) {
        printf("Erro ao fazer parse do JSON\n");
        free(conteudo_json);
        return 0;
    }
    
    /* Verifica se é um array */
    if (!cJSON_IsArray(json_root)) {
        printf("O JSON não é um array\n");
        cJSON_Delete(json_root);
        free(conteudo_json);
        return 0;
    }
    
    /* Percorre cada item do array */
    array_size = cJSON_GetArraySize(json_root);
    for (i = 0; i < array_size && count < MAX_PRODUTOS; i++) {
        item = cJSON_GetArrayItem(json_root, i);
        
        /* Extrai o ID */
        campo = cJSON_GetObjectItem(item, "id");
        if (cJSON_IsNumber(campo)) {
            produtos[count].codigo = campo->valueint;
        }
        
        /* Extrai o título (nome) */
        campo = cJSON_GetObjectItem(item, "title");
        if (cJSON_IsString(campo) && (campo->valuestring != NULL)) {
            strncpy(produtos[count].nome, campo->valuestring, 199);
            produtos[count].nome[199] = '\0';
        }
        
        /* Extrai o preço */
        campo = cJSON_GetObjectItem(item, "price");
        if (cJSON_IsNumber(campo)) {
            produtos[count].preco = (float)campo->valuedouble;
        }
        
        /* Extrai a categoria */
        campo = cJSON_GetObjectItem(item, "category");
        if (cJSON_IsString(campo) && (campo->valuestring != NULL)) {
            strncpy(produtos[count].categoria, campo->valuestring, 49);
            produtos[count].categoria[49] = '\0';
        }
        
        /* Extrai a descrição */
        campo = cJSON_GetObjectItem(item, "description");
        if (cJSON_IsString(campo) && (campo->valuestring != NULL)) {
            strncpy(produtos[count].descricao, campo->valuestring, 499);
            produtos[count].descricao[499] = '\0';
        } else {
            strcpy(produtos[count].descricao, "Sem descrição");
        }
        
        count++;
    }
    
    /* Libera a memória */
    cJSON_Delete(json_root);
    free(conteudo_json);
    
    printf("Total de %d produtos carregados com sucesso usando cJSON!\n", count);
    return count;
}

/* Função para cadastrar um produto manualmente */
void cadastrar_produto(Produto *produto, int codigo) {
    produto->codigo = codigo;
    
    printf("Digite o nome do produto: ");
    fflush(stdin);
    fgets(produto->nome, 200, stdin);
    produto->nome[strcspn(produto->nome, "\n")] = '\0';
    
    printf("Digite o preço do produto: R$ ");
    scanf("%f", &produto->preco);
    
    printf("Digite a categoria: ");
    fflush(stdin);
    fgets(produto->categoria, 50, stdin);
    produto->categoria[strcspn(produto->categoria, "\n")] = '\0';
    
    printf("Digite a descrição: ");
    fflush(stdin);
    fgets(produto->descricao, 500, stdin);
    produto->descricao[strcspn(produto->descricao, "\n")] = '\0';
    
    printf("\nProduto cadastrado com sucesso!\n");
}

/* Função para exibir dados de um produto */
void exibir_produto(Produto produto) {
    printf("  [%d] %s | R$ %.2f | %s\n", 
           produto.codigo, produto.nome, produto.preco, produto.categoria);
}