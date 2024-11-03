#define MaxProdutos 100
#define TamanhoNome 50

typedef struct
{
    int id;
    char nome[TamanhoNome];
    int quantidade;
    float preco_compra;
    float preco_venda;
    float desconto;
} Produto;

Produto estoque[MaxProdutos];
int total_produtos = 0;

// Função auxiliar para salvar todo o estoque no arquivo
void salvar_estoque()
{
    FILE *arquivo = fopen("estoque.txt", "w");
    if (arquivo != NULL)
    {
        for (int i = 0; i < total_produtos; i++)
        {
            fprintf(arquivo, "%d %s %d %.2f %.2f %.2f\n", estoque[i].id, estoque[i].nome, estoque[i].quantidade,
                    estoque[i].preco_compra, estoque[i].preco_venda, estoque[i].desconto);
        }
        fclose(arquivo);
    }
    else
    {
        perror("Erro ao salvar o estoque");
    }
}

// Função auxiliar para carregar o estoque do arquivo
void carregar_estoque()
{
    FILE *arquivo = fopen("estoque.txt", "r");
    if (arquivo != NULL)
    {
        total_produtos = 0;
        while (fscanf(arquivo, "%d %49[^\n] %d %f %f %f\n", &estoque[total_produtos].id, estoque[total_produtos].nome,
                      &estoque[total_produtos].quantidade, &estoque[total_produtos].preco_compra,
                      &estoque[total_produtos].preco_venda, &estoque[total_produtos].desconto) == 6)
        {
            total_produtos++;
        }
        fclose(arquivo);
    }
    else
    {
        perror("Erro ao carregar o estoque");
    }
}

// Função para buscar produto por ID
int buscar_produto_por_id(int id)
{
    for (int i = 0; i < total_produtos; i++)
    {
        if (estoque[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

// Função para adicionar um novo produto
void adicionar_produto()
{
    if (total_produtos >= MaxProdutos)
    {
        printf("Estoque cheio! Não é possível adicionar mais produtos.\n");
        printf("\nAperte qualquer tecla para continuar");
        getch();
        limpaTela();
        return;
    }

    Produto novo_produto;
    novo_produto.id = (total_produtos == 0) ? 1 : estoque[total_produtos - 1].id + 1;

    printf("\nDigite o nome do produto: ");
    scanf(" %49[^\n]", novo_produto.nome);
    printf("\nDigite a quantidade em estoque: ");
    scanf("%d", &novo_produto.quantidade);
    printf("\nDigite o preço de compra: ");
    scanf("%f", &novo_produto.preco_compra);
    printf("\nDigite o preço de venda: ");
    scanf("%f", &novo_produto.preco_venda);
    printf("\nDigite a porcentagem de desconto: ");
    scanf("%f", &novo_produto.desconto);

    estoque[total_produtos] = novo_produto;
    total_produtos++;

    salvar_estoque();

    printf("\n--------------------------------------\n");
    printf("\nProduto %s adicionado com sucesso!\n", novo_produto.nome);
    printf("\nO ID deste produto é %d", novo_produto.id);

    printf("\n\nAperte qualquer tecla para continuar");
    getch();
    limpaTela();
}

// Função para editar a quantidade de um produto existente
void editar_quantidade()
{
    int id;
    printf("Digite o ID do produto que deseja editar: ");
    scanf("%d", &id);

    int indice = buscar_produto_por_id(id);
    if (indice != -1)
    {
        printf("Produto encontrado: %s\n", estoque[indice].nome);
        printf("Quantidade atual: %d\n", estoque[indice].quantidade);
        printf("Digite a nova quantidade: ");
        scanf("%d", &estoque[indice].quantidade);

        salvar_estoque();
        printf("Quantidade atualizada com sucesso! Aperte qualquer tecla para voltar\n");
        getch();
        limpaTela();
    }
    else
    {
        printf("\nProduto com ID %d não encontrado. Aperte qualquer tecla para voltar\n", id);
        getch();
        limpaTela();
    }
}

void listar_produtos()
{
    if (total_produtos == 0)
    {
        carregar_estoque();
    }
    if (total_produtos == 0)
    {
        printf("\nNenhum produto no estoque. Aperte qualquer tecla para voltar\n");
        getch();
        limpaTela();
    }
    else
    {
        for (int i = 0; i < total_produtos; i++)
        {
            printf("ID: %d\nNome: %s\nQuantidade: %d\nPreço de Compra: %.2f\nPreço de Venda: %.2f\nDesconto: %.2f%%\n\n",
                   estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i].preco_compra, estoque[i].preco_venda,
                   estoque[i].desconto);

            printf("------------------------------------------\n\n");
        }
        printf("Aperte qualquer tecla para voltar");
        getch();
        limpaTela();
    }
}

void remover_produto()
{
    int id;
    printf("\nDigite o ID do produto que deseja remover: ");
    scanf("%d", &id);

    int indice = buscar_produto_por_id(id);
    if (indice != -1)
    {
        for (int i = indice; i < total_produtos - 1; i++)
        {
            estoque[i] = estoque[i + 1];
        }
        total_produtos--;

        salvar_estoque();
        printf("\nProduto removido com sucesso! Aperte qualquer tecla para voltar\n");
        getch();
        limpaTela();
    }
    else
    {
        printf("\nProduto com ID %d não encontrado. Aperte qualquer tecla para voltar\n", id);
        getch();
        limpaTela();
    }
}

void FuncaoEstoque()
{
    carregar_estoque();
    setlocale(LC_ALL, "");

    int opcao;
    do
    {
        printf("\n=== Sistema de Controle de Estoque ===\n\n");
        printf("  1. Adicionar produto\n");
        printf("  2. Editar quantidade do produto\n");
        printf("  3. Listar produtos\n");
        printf("  4. Remover produto\n\n");
        printf("  0. Voltar\n\n");
        printf("  - Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            limpaTela();
            adicionar_produto();
            break;
        case 2:
            limpaTela();
            editar_quantidade();
            break;
        case 3:
            limpaTela();
            listar_produtos();
            break;
        case 4:
            limpaTela();
            remover_produto();
            break;
        case 0:
            limpaTela();
            return;
            break;
        default:
            limpaTela();
            printf("Opção inválida! Aperte qualquer tecla para tentar novamente.\n");
            getch();
        }
    } while (opcao != 5);
}
