
// FUNÇÕES NO ARQUIVO

/*
    adicionar_produto()
    adicionar_usuario(const char* nome_usuario, const char* senha_usuario)
    autenticar(const char* nome_usuario, const char* senha_usuario)
    limpar_buffer()
    listar_produtos()
    listarUsuarios()
    login_usuario()
    obter_opcao_menu()
    registrar_usuario()
    remover_produto()
    substituir_virgula_por_ponto(char* string)
    tela_boas_vindas()
    telaProdutos()
    verificar_usuario_existente()
*/

/// ---------- MACROS ----------

#define USER_ADM "adm"
#define SENHA_ADM "123"

#include <locale.h>
#ifndef TIPOS_H
#define TIPOS_H

#define TAMANHO_NOME_FUNCIONARIO 20
#define TAMANHO_SENHA_FUNCIONARIO 20
#define TAMANHO_NOME_ITEM 50
#define MAX_FUNCIONARIOS 10
#define MAX_ITENS 50

/// ---------- STRUCTS ----------

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

// ---------- VARIÁVEIS GLOBAIS ----------

Funcionario lista_funcionarios[MAX_FUNCIONARIOS];
Item lista_itens[MAX_ITENS];
int total_funcionarios = 0;
int total_itens = 0;


/// ---------- FUNCOES ITENS ----------

void listar_itens() {
    limpaTela();
    printf("\n\t--- Lista de Itens ---\n\n");
    if (total_itens == 0) {
        printf("\nNenhum item no estoque.\n");
        return;
    }

    for (int i = 0; i < total_itens; i++) {
        float preco = lista_itens[i].preco_item;
        int inteiro = (int)preco;
        int centavos = (int)((preco - inteiro) * 100);
        printf("Item: %s | Quantidade: %d | Preço: R$ %d,%02d\n",
               lista_itens[i].nome_item, lista_itens[i].quantidade_item, inteiro, centavos);
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


void adicionar_item() {
    if (total_itens >= MAX_ITENS) {
        printf("\nEstoque cheio! Não é possível adicionar mais itens.\n");
        return;
    }

    char nome_item[TAMANHO_NOME_ITEM];
    int quantidade_item;
    char preco_str[20];
    float preco_item;

    printf("\n\t --- Adicionar Item ---\n\n");
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
    lista_itens[total_itens].nome_item[TAMANHO_NOME_ITEM - 1] = '\0';  // Terminação nula
    lista_itens[total_itens].quantidade_item = quantidade_item;
    lista_itens[total_itens].preco_item = preco_item;
    total_itens++;

    limpaTela();

    printf("\nItem adicionado com sucesso!\n");
}


void remover_item() {
    listar_itens();
    char nome_item[TAMANHO_NOME_ITEM];

    printf("\n\t --- Remover Item ---\n\n");
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


void telaItens() {
    int opcao;

    while(1){
        printf("\n\n\t --- Itens ---\n\n");
        printf("1. Adicionar Item\n");
        printf("2. Listar Itens\n");
        printf("3. Remover Item\n\n");
        printf("0. Voltar\n\n");

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

void incluirAdm(){
    strcpy(lista_funcionarios[0].nome_funcionario, USER_ADM);
    strcpy(lista_funcionarios[0].senha_funcionario, SENHA_ADM);

    total_funcionarios++;
}


void registrar_funcionario() {
    char nome_funcionario[TAMANHO_NOME_FUNCIONARIO];
    char senha_funcionario[TAMANHO_SENHA_FUNCIONARIO];

    printf("\n\n\t --- Registro de Usuário ---\n\n");
    printf("Digite o nome de usuário: ");
    scanf(" %[^\n]", nome_funcionario);
    printf("          Digite a senha: ");
    scanf(" %[^\n]", senha_funcionario);

    adicionar_funcionario(nome_funcionario, senha_funcionario);
}

int verificar_funcionario_existente(const char *nome_funcionario) {
    for (int i = 0; i < total_funcionarios; i++) {
        if (strcmp(lista_funcionarios[i].nome_funcionario, nome_funcionario) == 0) {
            return 1;
        }
    }
    return 0;
}

void listarFuncionarios(){
    printf("\n\n\t --- Usuários ---\n\n");
    printf("Total de usuários cadastrados: %d\n\n", total_funcionarios);

    for(int i = 0; i < total_funcionarios; i++){
        printf("%d - %s\n", i + 1, lista_funcionarios[i].nome_funcionario);
    }

    printf("\n\nAperte qualquer tecla para voltar");
    getch();
    limpaTela();
    return;
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



void login_funcionario() {
    char nome_funcionario[TAMANHO_NOME_FUNCIONARIO];
    char senha_funcionario[TAMANHO_SENHA_FUNCIONARIO];

    printf("\n\n\t --- Login ---\n\n");
    printf("Nome de usuário: ");
    scanf(" %[^\n]", nome_funcionario);
    printf("          Senha: ");
    scanf(" %[^\n]", senha_funcionario);

    if(strcmp(USER_ADM, nome_funcionario) == 0 && strcmp(SENHA_ADM, senha_funcionario) == 0){
        limpaTela();
        printf("Login bem-sucedido! Bem-vindo(a), ADM");
        menuAdm();
    }

    if (autenticar(nome_funcionario, senha_funcionario)) {
        limpaTela();
        printf("Login bem-sucedido! Bem-vindo(a), %s!", nome_funcionario);
        menuGeral();
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

// FUNÇÕES NO ARQUIVO

/*
    adicionar_produto()
    adicionar_usuario(const char* nome_usuario, const char* senha_usuario)
    autenticar(const char* nome_usuario, const char* senha_usuario)
    limpar_buffer()
    listar_produtos()
    listarUsuarios()
    login_usuario()
    obter_opcao_menu()
    registrar_usuario()
    remover_produto()
    substituir_virgula_por_ponto(char* string)
    tela_boas_vindas()
    telaProdutos()
    verificar_usuario_existente()
*/

/// ---------- MACROS ----------

#define USER_ADM "adm"
#define SENHA_ADM "123"

#include <locale.h>
#ifndef TIPOS_H
#define TIPOS_H

#define TAMANHO_NOME_FUNCIONARIO 20
#define TAMANHO_SENHA_FUNCIONARIO 20
#define TAMANHO_NOME_ITEM 50
#define MAX_FUNCIONARIOS 10
#define MAX_ITENS 50

/// ---------- STRUCTS ----------

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

// ---------- VARIÁVEIS GLOBAIS ----------

Funcionario lista_funcionarios[MAX_FUNCIONARIOS];
Item lista_itens[MAX_ITENS];
int total_funcionarios = 0;
int total_itens = 0;


/// ---------- FUNCOES ITENS ----------

void listar_itens() {
    limpaTela();
    printf("\n\t--- Lista de Itens ---\n\n");
    if (total_itens == 0) {
        printf("\nNenhum item no estoque.\n");
        return;
    }

    for (int i = 0; i < total_itens; i++) {
        float preco = lista_itens[i].preco_item;
        int inteiro = (int)preco;
        int centavos = (int)((preco - inteiro) * 100);
        printf("Item: %s | Quantidade: %d | Preço: R$ %d,%02d\n",
               lista_itens[i].nome_item, lista_itens[i].quantidade_item, inteiro, centavos);
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


void adicionar_item() {
    if (total_itens >= MAX_ITENS) {
        printf("\nEstoque cheio! Não é possível adicionar mais itens.\n");
        return;
    }

    char nome_item[TAMANHO_NOME_ITEM];
    int quantidade_item;
    char preco_str[20];
    float preco_item;

    printf("\n\t --- Adicionar Item ---\n\n");
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
    lista_itens[total_itens].nome_item[TAMANHO_NOME_ITEM - 1] = '\0';  // Terminação nula
    lista_itens[total_itens].quantidade_item = quantidade_item;
    lista_itens[total_itens].preco_item = preco_item;
    total_itens++;

    limpaTela();

    printf("\nItem adicionado com sucesso!\n");
}


void remover_item() {
    listar_itens();
    char nome_item[TAMANHO_NOME_ITEM];

    printf("\n\t --- Remover Item ---\n\n");
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


void telaItens() {
    int opcao;

    while(1){
        printf("\n\n\t --- Itens ---\n\n");
        printf("1. Adicionar Item\n");
        printf("2. Listar Itens\n");
        printf("3. Remover Item\n\n");
        printf("0. Voltar\n\n");

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

void incluirAdm(){
    strcpy(lista_funcionarios[0].nome_funcionario, USER_ADM);
    strcpy(lista_funcionarios[0].senha_funcionario, SENHA_ADM);

    total_funcionarios++;
}


void registrar_funcionario() {
    char nome_funcionario[TAMANHO_NOME_FUNCIONARIO];
    char senha_funcionario[TAMANHO_SENHA_FUNCIONARIO];

    printf("\n\n\t --- Registro de Usuário ---\n\n");
    printf("Digite o nome de usuário: ");
    scanf(" %[^\n]", nome_funcionario);
    printf("          Digite a senha: ");
    scanf(" %[^\n]", senha_funcionario);

    adicionar_funcionario(nome_funcionario, senha_funcionario);
}

int verificar_funcionario_existente(const char *nome_funcionario) {
    for (int i = 0; i < total_funcionarios; i++) {
        if (strcmp(lista_funcionarios[i].nome_funcionario, nome_funcionario) == 0) {
            return 1;
        }
    }
    return 0;
}

void listarFuncionarios(){
    printf("\n\n\t --- Usuários ---\n\n");
    printf("Total de usuários cadastrados: %d\n\n", total_funcionarios);

    for(int i = 0; i < total_funcionarios; i++){
        printf("%d - %s\n", i + 1, lista_funcionarios[i].nome_funcionario);
    }

    printf("\n\nAperte qualquer tecla para voltar");
    getch();
    limpaTela();
    return;
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



void login_funcionario() {
    char nome_funcionario[TAMANHO_NOME_FUNCIONARIO];
    char senha_funcionario[TAMANHO_SENHA_FUNCIONARIO];

    printf("\n\n\t --- Login ---\n\n");
    printf("Nome de usuário: ");
    scanf(" %[^\n]", nome_funcionario);
    printf("          Senha: ");
    scanf(" %[^\n]", senha_funcionario);

    if(strcmp(USER_ADM, nome_funcionario) == 0 && strcmp(SENHA_ADM, senha_funcionario) == 0){
        limpaTela();
        printf("Login bem-sucedido! Bem-vindo(a), ADM");
        menuAdm();
    }

    if (autenticar(nome_funcionario, senha_funcionario)) {
        limpaTela();
        printf("Login bem-sucedido! Bem-vindo(a), %s!", nome_funcionario);
        menuGeral();
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
