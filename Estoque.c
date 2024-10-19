#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#define MaxProdutos 100
#define TamanhoNome 50

typedef struct {
    int id;
    char nome[TamanhoNome];
    int quantidade;
    float preco_compra;
    float preco_venda;
    float desconto;
} Produto;

Produto estoque[MaxProdutos];
int total_produtos = 0;

void carregar_estoque() {
    FILE *arquivo = fopen("estoque.txt", "r");
    if (arquivo != NULL) {
        while (fscanf(arquivo, "%d %49s %d %f %f %f\n", &estoque[total_produtos].id, estoque[total_produtos].nome,
                      &estoque[total_produtos].quantidade, &estoque[total_produtos].preco_compra,
                      &estoque[total_produtos].preco_venda, &estoque[total_produtos].desconto) == 6) {
            total_produtos++;
        }
        fclose(arquivo);
    } else {
        // Se o arquivo não existir, cria um novo arquivo vazio
        arquivo = fopen("estoque.txt", "w");
        if (arquivo != NULL) {
            fclose(arquivo);
        }
    }
}

void salvar_estoque() {
    FILE *arquivo = fopen("estoque.txt", "w");
    if (arquivo != NULL) {
        for (int i = 0; i < total_produtos; i++) {
            fprintf(arquivo, "%d %s %d %.2f %.2f %.2f\n", estoque[i].id, estoque[i].nome, estoque[i].quantidade,
                    estoque[i].preco_compra, estoque[i].preco_venda, estoque[i].desconto);
        }
        fclose(arquivo);
    }
}

void adicionar_produto() {
    if (total_produtos >= MaxProdutos) {
        printf("Estoque cheio! Não é possível adicionar mais produtos.\n");
        return;
    }
    Produto novo_produto;
    novo_produto.id = (total_produtos == 0) ? 1 : estoque[total_produtos - 1].id + 1;
    printf("Digite o nome do produto: ");
    scanf("%s", novo_produto.nome);
    fflush(stdin);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novo_produto.quantidade);
    fflush(stdin);
    printf("Digite o preço de compra: ");
    scanf("%f", &novo_produto.preco_compra);
    fflush(stdin);
    printf("Digite o preço de venda: ");
    scanf("%f", &novo_produto.preco_venda);
    fflush(stdin);
    printf("Digite a porcentagem de desconto: ");
    scanf("%f", &novo_produto.desconto);
    fflush(stdin);
    
    estoque[total_produtos] = novo_produto;
    total_produtos++;
    salvar_estoque();
    printf("Produto %s adicionado com sucesso!\n", novo_produto.nome);
}

void editar_quantidade() {
    int id;
    printf("Digite o ID do produto que deseja editar: ");
    scanf("%d", &id);
    fflush(stdin);
    
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].id == id) {
            printf("Produto encontrado: %s\n", estoque[i].nome);
            printf("Quantidade atual: %d\n", estoque[i].quantidade);
            printf("Digite a nova quantidade: ");
            scanf("%d", &estoque[i].quantidade);
            fflush(stdin);
            salvar_estoque();
            printf("Quantidade atualizada com sucesso!\n");
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

void listar_produtos() {
    for (int i = 0; i < total_produtos; i++) {
        printf("ID: %d\nNome: %s\nQuantidade: %d\nPreço de Compra: %.2f\nPreço de Venda: %.2f\nDesconto: %.2f%%\n\n",
               estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i].preco_compra, estoque[i].preco_venda,
               estoque[i].desconto);
    }
}

int main() {
    carregar_estoque();
    int opcao;
    setlocale(LC_ALL,"");
    do {
        printf("\n=== Sistema de Controle de Estoque ===\n");
        printf("1. Adicionar produto\n");
        printf("2. Editar quantidade do produto\n");
        printf("3. Listar produtos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1:
                adicionar_produto();
                break;
            case 2:
                editar_quantidade();
                break;
            case 3:
                listar_produtos();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
