#include <C:\Users\atumo\OneDrive\Documentos\PROG\PIM esse\funcoes.h> // tá assim pq eu tava testando no meu pc, só mudar o caminho depois
/// STRUCT INTERFACE (EL BOLA)
#define TIPOS_H
#define TIPOS_H

#define TAMANHO_NOME_FUNCIONARIO 20
#define TAMANHO_SENHA_FUNCIONARIO 20
#define TAMANHO_NOME_ITEM 50
#define MAX_FUNCIONARIOS 10
#define MAX_ITENS 50

typedef struct {
    char nome_funcionario[TAMANHO_NOME_FUNCIONARIO];
    char senha_funcionario[TAMANHO_SENHA_FUNCIONARIO];
} Funcionario;

typedef struct {
    char nome_item[TAMANHO_NOME_ITEM];
    int quantidade_item;
    float preco_item;
} Item;

#endif

// VARIÁVEIS GLOBAIS

Funcionario lista_funcionarios[MAX_FUNCIONARIOS];
Item lista_itens[MAX_ITENS];
int total_funcionarios = 0;
int total_itens = 0;

/// Funções Interface

int verificar_funcionario_existente(const char *nome_funcionario) {
    for (int i = 0; i < total_funcionarios; i++) {
        if (strcmp(lista_funcionarios[i].nome_funcionario, nome_funcionario) == 0) {
            return 1;
        }
    }
    return 0;
}

void adicionar_funcionario(const char *nome_funcionario, const char *senha_funcionario) {
    if (verificar_funcionario_existente(nome_funcionario)) {
        limpaTela();
        printf("\nErro: Nome de usuário já existe. Tente outro.\n");
        return;
    }

    if (total_funcionarios >= MAX_FUNCIONARIOS) {
        limpaTela();
        printf("\nNúmero máximo de usuários atingido.\n");
        return;
    }

    strncpy(lista_funcionarios[total_funcionarios].nome_funcionario, nome_funcionario, TAMANHO_NOME_FUNCIONARIO - 1);
    lista_funcionarios[total_funcionarios].nome_funcionario[TAMANHO_NOME_FUNCIONARIO - 1] = '\0';
    strncpy(lista_funcionarios[total_funcionarios].senha_funcionario, senha_funcionario, TAMANHO_SENHA_FUNCIONARIO - 1);
    lista_funcionarios[total_funcionarios].senha_funcionario[TAMANHO_SENHA_FUNCIONARIO - 1] = '\0';
    total_funcionarios++;

    limpaTela();
    printf("\nUsuário registrado com sucesso!\n");
}

int autenticar(const char *nome_funcionario, const char *senha_funcionario) {
    for (int i = 0; i < total_funcionarios; i++) {
        if (strcmp(lista_funcionarios[i].nome_funcionario, nome_funcionario) == 0 &&
            strcmp(lista_funcionarios[i].senha_funcionario, senha_funcionario) == 0) {
            return 1;
        }
    }
    return 0;
}

void listar_itens() {
    limpaTela();
    printf("\n--- Lista de Itens ---\n");
    if (total_itens == 0) {
        printf("Nenhum item no estoque.\n");
        return;
    }

    for (int i = 0; i < total_itens; i++) {
        float preco = lista_itens[i].preco_item;
        int inteiro = (int)preco;
        int centavos = (int)((preco - inteiro) * 100);
        printf("Item: %s | Quantidade: %d | Preço: R$ %d,%02d\n",
               lista_itens[i].nome_item, lista_itens[i].quantidade_item, inteiro, centavos);
    }
}

void limpar_buffer() {
    while (getchar() != '\n');
}

void substituir_virgula_por_ponto(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ',') {
            string[i] = '.';
        }
    }
}

void adicionar_item() {
    if (total_itens >= MAX_ITENS) {
        printf("\nEstoque cheio! Não é possível adicionar mais itens.\n");
        return;
    }

    char nome_item[TAMANHO_NOME_ITEM];
    int quantidade_item;
    char preco_str[20];
    float preco_item;

    printf("\n--- Adicionar Item ---\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", nome_item);

    printf("Quantidade: ");
    scanf("%d", &quantidade_item);

    limpar_buffer();

    printf("Preço: ");
    scanf("%s", preco_str);
    substituir_virgula_por_ponto(preco_str);
    preco_item = atof(preco_str);

    strncpy(lista_itens[total_itens].nome_item, nome_item, TAMANHO_NOME_ITEM - 1);
    lista_itens[total_itens].nome_item[TAMANHO_NOME_ITEM - 1] = '\0';
    lista_itens[total_itens].quantidade_item = quantidade_item;
    lista_itens[total_itens].preco_item = preco_item;
    total_itens++;

    limpaTela();
    printf("\nItem adicionado com sucesso!\n");
}

void remover_item() {
    listar_itens();
    char nome_item[TAMANHO_NOME_ITEM];

    printf("\n--- Remover Item ---\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", nome_item);

    for (int i = 0; i < total_itens; i++) {
        if (strcmp(lista_itens[i].nome_item, nome_item) == 0) {
            for (int j = i; j < total_itens - 1; j++) {
                lista_itens[j] = lista_itens[j + 1];
            }
            total_itens--;

            limpaTela();
            printf("\nItem removido com sucesso!\n");
            return;
        }
    }
    limpaTela();
    printf("\nItem não encontrado.\n");
}

int obter_opcao_menu() {
    int opcao;
    while (1) {
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) == 1) {
            limpar_buffer();
            limpaTela();
            return opcao;
        } else {
            limpaTela();
            printf("Entrada inválida! Tente novamente.\n");
            limpar_buffer();
        }
    }
}

void menu_estoque() {
    int opcao;
    while (1) {
        printf("\n--- Menu de Estoque ---\n");
        printf("1. Adicionar Item\n");
        printf("2. Listar Itens\n");
        printf("3. Remover Item\n");
        printf("4. Voltar ao Menu Principal\n");

        opcao = obter_opcao_menu();

        switch (opcao) {
            case 1:
                limpaTela();
                adicionar_item();
                break;
            case 2:
                limpaTela();
                listar_itens();
                break;
            case 3:
                limpaTela();
                remover_item();
                break;
            case 4:
                return;
            default:
                limpaTela();
                printf("\nOpção inválida! Tente novamente.\n");
        }
    }
}

void registrar_funcionario() {
    char nome_funcionario[TAMANHO_NOME_FUNCIONARIO];
    char senha_funcionario[TAMANHO_SENHA_FUNCIONARIO];

    printf("\n--- Registro de Usuário ---\n");
    printf("Digite o nome de usuário: ");
    scanf(" %[^\n]", nome_funcionario);
    printf("Digite a senha: ");
    scanf(" %[^\n]", senha_funcionario);

    adicionar_funcionario(nome_funcionario, senha_funcionario);
}

void login_funcionario() {
    char nome_funcionario[TAMANHO_NOME_FUNCIONARIO];
    char senha_funcionario[TAMANHO_SENHA_FUNCIONARIO];

    printf("\n--- Login ---\n");
    printf("Nome de usuário: ");
    scanf(" %[^\n]", nome_funcionario);
    printf("Senha: ");
    scanf(" %[^\n]", senha_funcionario);

    if (autenticar(nome_funcionario, senha_funcionario)) {
        limpaTela();
        printf("\nLogin bem-sucedido! Bem-vindo(a), %s!\n", nome_funcionario);
        menu_estoque();
    } else {
        limpaTela();
        printf("\nNome de usuário ou senha incorretos.\n");
    }
}

void tela_boas_vindas() {
    printf("\n");
    printf("****************************************\n");
    printf("*                                      *\n");
    printf("*          BEM-VINDO AO MERCADO        *\n");
    printf("*                                      *\n");
    printf("****************************************\n");
}
