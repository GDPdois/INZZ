//Sprint 11/09 Interface Frontend (Nicolas)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_USUARIOS 10
#define TAMANHO_NOME_USUARIO 20
#define TAMANHO_SENHA 20
#define MAX_PRODUTOS 50
#define TAMANHO_NOME_PRODUTO 50

typedef struct {
    char nome_usuario[TAMANHO_NOME_USUARIO];
    char senha_usuario[TAMANHO_SENHA];
} Usuario;

typedef struct {
    char nome_produto[TAMANHO_NOME_PRODUTO];
    int quantidade_produto;
    float preco_produto;
} Produto;

Usuario lista_usuarios[MAX_USUARIOS];
Produto lista_produtos[MAX_PRODUTOS];
int total_usuarios = 0;
int total_produtos = 0;


int verificar_usuario_existente(const char *nome_usuario) {
    for (int i = 0; i < total_usuarios; i++) {
        if (strcmp(lista_usuarios[i].nome_usuario, nome_usuario) == 0) {
            return 1;
        }
    }
    return 0;
}


void adicionar_usuario(const char *nome_usuario, const char *senha_usuario) {
    if (verificar_usuario_existente(nome_usuario)) {
        printf("\nErro: Nome de usuário já existe. Tente outro.\n");
        return;
    }

    if (total_usuarios >= MAX_USUARIOS) {
        printf("\nNúmero máximo de usuários atingido.\n");
        return;
    }

    strncpy(lista_usuarios[total_usuarios].nome_usuario, nome_usuario, TAMANHO_NOME_USUARIO - 1);
    lista_usuarios[total_usuarios].nome_usuario[TAMANHO_NOME_USUARIO - 1] = '\0';
    strncpy(lista_usuarios[total_usuarios].senha_usuario, senha_usuario, TAMANHO_SENHA - 1);
    lista_usuarios[total_usuarios].senha_usuario[TAMANHO_SENHA - 1] = '\0';
    total_usuarios++;
    printf("\nUsuário registrado com sucesso!\n");
}


int autenticar(const char *nome_usuario, const char *senha_usuario) {
    for (int i = 0; i < total_usuarios; i++) {
        if (strcmp(lista_usuarios[i].nome_usuario, nome_usuario) == 0 &&
            strcmp(lista_usuarios[i].senha_usuario, senha_usuario) == 0) {
            return 1;
        }
    }
    return 0;
}


void listar_produtos() {
    printf("\n--- Lista de Produtos ---\n");
    if (total_produtos == 0) {
        printf("Nenhum produto no estoque.\n");
        return;
    }

    for (int i = 0; i < total_produtos; i++) {
        float preco = lista_produtos[i].preco_produto;
        int inteiro = (int)preco;
        int centavos = (int)((preco - inteiro) * 100);
        printf("Produto: %s | Quantidade: %d | Preço: %d,%02d\n",
               lista_produtos[i].nome_produto, lista_produtos[i].quantidade_produto, inteiro, centavos);
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


void adicionar_produto() {
    if (total_produtos >= MAX_PRODUTOS) {
        printf("\nEstoque cheio! Não é possível adicionar mais produtos.\n");
        return;
    }

    char nome_produto[TAMANHO_NOME_PRODUTO];
    int quantidade_produto;
    char preco_str[20];
    float preco_produto;

    printf("\n--- Adicionar Produto ---\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]", nome_produto);

    printf("Quantidade: ");
    scanf("%d", &quantidade_produto);

    limpar_buffer();

    printf("Preço: ");
    scanf("%s", preco_str);
    substituir_virgula_por_ponto(preco_str);
    preco_produto = atof(preco_str);

    strncpy(lista_produtos[total_produtos].nome_produto, nome_produto, TAMANHO_NOME_PRODUTO - 1);
    lista_produtos[total_produtos].nome_produto[TAMANHO_NOME_PRODUTO - 1] = '\0';  // Terminação nula
    lista_produtos[total_produtos].quantidade_produto = quantidade_produto;
    lista_produtos[total_produtos].preco_produto = preco_produto;
    total_produtos++;

    printf("\nProduto adicionado com sucesso!\n");
}


void remover_produto() {
    char nome_produto[TAMANHO_NOME_PRODUTO];

    printf("\n--- Remover Produto ---\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]", nome_produto);

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(lista_produtos[i].nome_produto, nome_produto) == 0) {
            for (int j = i; j < total_produtos - 1; j++) {
                lista_produtos[j] = lista_produtos[j + 1];
            }
            total_produtos--;
            printf("\nProduto removido com sucesso!\n");
            return;
        }
    }
    printf("\nProduto não encontrado.\n");
}


int obter_opcao_menu() {
    int opcao;
    while (1) {
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) == 1) {
            limpar_buffer();
            return opcao;
        } else {
            printf("Entrada inválida! Tente novamente.\n");
            limpar_buffer();
        }
    }
}


void menu_estoque() {
    int opcao;
    while (1) {
        printf("\n--- Menu de Estoque ---\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Remover Produto\n");
        printf("4. Voltar ao Menu Principal\n");

        opcao = obter_opcao_menu();

        switch (opcao) {
            case 1:
                adicionar_produto();
                break;
            case 2:
                listar_produtos();
                break;
            case 3:
                remover_produto();
                break;
            case 4:
                return;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    }
}


void registrar_usuario() {
    char nome_usuario[TAMANHO_NOME_USUARIO];
    char senha_usuario[TAMANHO_SENHA];

    printf("\n--- Registro de Usuário ---\n");
    printf("Digite o nome de usuário: ");
    scanf(" %[^\n]", nome_usuario);
    printf("Digite a senha: ");
    scanf(" %[^\n]", senha_usuario);

    adicionar_usuario(nome_usuario, senha_usuario);
}


void login_usuario() {
    char nome_usuario[TAMANHO_NOME_USUARIO];
    char senha_usuario[TAMANHO_SENHA];

    printf("\n--- Login ---\n");
    printf("Nome de usuário: ");
    scanf(" %[^\n]", nome_usuario);
    printf("Senha: ");
    scanf(" %[^\n]", senha_usuario);

    if (autenticar(nome_usuario, senha_usuario)) {
        printf("\nLogin bem-sucedido! Bem-vindo(a), %s!\n", nome_usuario);
        menu_estoque();
    } else {
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


int main() {
    int opcao;
    setlocale(LC_ALL, "pt_BR.UTF-8");
    tela_boas_vindas();

    while (1) {
        printf("\n--- Menu Principal ---\n");
        printf("1. Registrar\n");
        printf("2. Login\n");
        printf("3. Sair\n");
        opcao = obter_opcao_menu();

        switch (opcao) {
            case 1:
                registrar_usuario();
                break;
            case 2:
                login_usuario();
                break;
            case 3:
                printf("\nSaindo...\n");
                return 0;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    }
}

