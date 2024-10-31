
/// ---------- STRUCTS ----------

#define USER_ADM "adm"
#define SENHA_ADM "123"

#include <locale.h>
#ifndef TIPOS_H
#define TIPOS_H

#define TAMANHO_NOME_USUARIO 20
#define TAMANHO_SENHA 20
#define TAMANHO_NOME_PRODUTO 50
#define MAX_USUARIOS 10
#define MAX_PRODUTOS 50

typedef struct {
    char nome_usuario[TAMANHO_NOME_USUARIO];
    char senha_usuario[TAMANHO_SENHA];
} Usuario;

typedef struct {
    char nome_produto[TAMANHO_NOME_PRODUTO];
    int quantidade_produto;
    float preco_produto;
} Produto;

#endif

// ---------- VARIÁVEIS GLOBAIS ----------

Usuario lista_usuarios[MAX_USUARIOS];
Produto lista_produtos[MAX_PRODUTOS];
int total_usuarios = 0;
int total_produtos = 0;


/// ---------- FUNCOES PRODUTOS ----------

void listar_produtos() {
    limpaTela();
    printf("\n\t--- Lista de Produtos ---\n\n");
    if (total_produtos == 0) {
        printf("\nNenhum produto no estoque.\n");
        return;
    }

    for (int i = 0; i < total_produtos; i++) {
        float preco = lista_produtos[i].preco_produto;
        int inteiro = (int)preco;
        int centavos = (int)((preco - inteiro) * 100);
        printf("Produto: %s | Quantidade: %d | Preço: R$ %d,%02d\n",
               lista_produtos[i].nome_produto, lista_produtos[i].quantidade_produto, inteiro, centavos);
    }

    printf("\nAperte qualquer tecla para voltar");
    getch();
    limpaTela();
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

    printf("\n\t --- Adicionar Produto ---\n\n");
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

    limpaTela();

    printf("\nProduto adicionado com sucesso!\n");
}


void remover_produto() {
    listar_produtos();
    char nome_produto[TAMANHO_NOME_PRODUTO];

    printf("\n\t --- Remover Produto ---\n\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]", nome_produto);

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(lista_produtos[i].nome_produto, nome_produto) == 0) {
            for (int j = i; j < total_produtos - 1; j++) {
                lista_produtos[j] = lista_produtos[j + 1];
            }
            total_produtos--;

            limpaTela();

            printf("\nProduto removido com sucesso!\n");
            return;
        }
    }
    limpaTela();

    printf("\nProduto não encontrado.\n");
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


void telaProdutos() {
    int opcao;

    while (1) {
        printf("\n\n\t --- Produtos ---\n\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Remover Produto\n\n");
        printf("0. Voltar\n\n");

        opcao = obter_opcao_menu();

        switch (opcao) {
            case 1:
                limpaTela();
                adicionar_produto();
                break;
            case 2:
                limpaTela();
                listar_produtos();
                break;
            case 3:
                limpaTela();
                remover_produto();
                break;
            case 0:
                limpaTela();
                return;
            break;

            default:
                limpaTela();
                printf("\nOpção inválida! Tente novamente.\n");
        }
    }
}

// ---------- FUNCOES USUARIO ----------

void registrar_usuario() {
    char nome_usuario[TAMANHO_NOME_USUARIO];
    char senha_usuario[TAMANHO_SENHA];

    printf("\n\n\t --- Registro de Usuário ---\n\n");
    printf("Digite o nome de usuário: ");
    scanf(" %[^\n]", nome_usuario);
    printf("          Digite a senha: ");
    scanf(" %[^\n]", senha_usuario);

    adicionar_usuario(nome_usuario, senha_usuario);
}

int verificar_usuario_existente(const char *nome_usuario) {
    for (int i = 0; i < total_usuarios; i++) {
        if (strcmp(lista_usuarios[i].nome_usuario, nome_usuario) == 0) {
            return 1;
        }
    }
    return 0;
}

void listarUsuarios(){
    printf("\n\n\t --- Usuários ---\n\n");
    printf("Total de usuários cadastrados: %d\n", total_usuarios + 1);
    printf("\n1 - ADM\n");

    for(int i = 0; i < total_usuarios; i++){
        printf("%d - %s\n", i + 2, lista_usuarios[i].nome_usuario);
    }

    printf("\n\nAperte qualquer tecla para voltar");
    getch();
    limpaTela();
    return;
}


void adicionar_usuario(const char *nome_usuario, const char *senha_usuario) {
    if (verificar_usuario_existente(nome_usuario)) {
        limpaTela();

        printf("\nErro: Nome de usuário já existe. Tente outro.\n");
        return;
    }

    if (total_usuarios >= MAX_USUARIOS) {
        limpaTela();

        printf("\nNúmero máximo de usuários atingido.\n");
        return;
    }

    strncpy(lista_usuarios[total_usuarios].nome_usuario, nome_usuario, TAMANHO_NOME_USUARIO - 1);
    lista_usuarios[total_usuarios].nome_usuario[TAMANHO_NOME_USUARIO - 1] = '\0';
    strncpy(lista_usuarios[total_usuarios].senha_usuario, senha_usuario, TAMANHO_SENHA - 1);
    lista_usuarios[total_usuarios].senha_usuario[TAMANHO_SENHA - 1] = '\0';
    total_usuarios++;

    limpaTela();

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



void login_usuario() {
    char nome_usuario[TAMANHO_NOME_USUARIO];
    char senha_usuario[TAMANHO_SENHA];

    printf("\n\n\t --- Login ---\n\n");
    printf("Nome de usuário: ");
    scanf(" %[^\n]", nome_usuario);
    printf("          Senha: ");
    scanf(" %[^\n]", senha_usuario);

    if(strcmp(USER_ADM, nome_usuario) == 0 && strcmp(SENHA_ADM, senha_usuario) == 0){
        limpaTela();
        printf("Login bem-sucedido! Bem-vindo(a), ADM");
        menuAdm();
    }

    if (autenticar(nome_usuario, senha_usuario)) {
        limpaTela();
        printf("Login bem-sucedido! Bem-vindo(a), %s!", nome_usuario);
        menuNormal();
    } else {
        printf("\nNome de usuário ou senha incorretos.\n");
        printf("\n\nAperte qualquer tecla para voltar");
        getch();
        limpaTela();
    }
}


void tela_boas_vindas() {
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t****************************************\n");
    printf("\t\t\t\t*                                      *\n");
    printf("\t\t\t\t*          BEM-VINDO AO MERCADO        *\n");
    printf("\t\t\t\t*                                      *\n");
    printf("\t\t\t\t****************************************\n");
}

