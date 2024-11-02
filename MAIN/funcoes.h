// STRUCT CLIENTES
#ifndef CLIENTES_H
#define CLIENTES_H

struct clientes {
    char nome[50], cpf[12], cel[12];
};

typedef struct clientes clientes;

#endif

// VARIÁVEIS GLOBAIS
clientes *lista = NULL;
int qtd = 0;

// FUNÇÕES

/* FUNÇÕES NO ARQUIVO:
    cadClientes()
    exibeClientes()
    menuAdm()
    menuGeral()
    telaCaixa()
    telaClientes()
    telaInicial()
    telaUsuarios()
    descontoTotal()
    descontoProduto()
    exibeProdutos()
    limpaTela()
    sair()
*/

// LIMPA TELA (limpa a tela)
void limpaTela(){
    system("cls");
}

float descontoTotal(int i, float valorProdutos[], float totalSemDesc){
    float descontoPercentual, valorDesconto, valorFinal;

    do{
        exibeProdutos(i, valorProdutos, totalSemDesc);

        printf("\nTotal sem desconto: R$ %.2f\n", totalSemDesc);
        printf("\nDigite a porcentagem do desconto: ");
        scanf("%f", &descontoPercentual);

        if(descontoPercentual < 0 || descontoPercentual > 100){
            limpaTela();
            printf("***O valor do desconto deve estar entre 1 e 100!\n");
            printf("\n-------------------------------------------------\n");
        }
    }
    while(descontoPercentual <= 0 || descontoPercentual > 100);

    valorFinal = totalSemDesc - (totalSemDesc * descontoPercentual / 100);
    valorDesconto = totalSemDesc - valorFinal;

    limpaTela();

    printf("\nTotal sem desconto: R$ %.2f\n", totalSemDesc);
    printf("\n          Desconto: %.f%%", descontoPercentual);
    printf("\n  Valor descontado: R$ %.2f\n", valorDesconto);
    printf("\nTotal com desconto: R$ %.2f\n", valorFinal);

    return valorFinal;
}

// DESCONTO PRODUTO (aplica desconto apenas no produto escolhido)
float descontoProduto(float preco, float desconto){
    return preco * (1 - desconto / 100);
}


float telaCaixa(){
    float valorProdutos[100], total = 0, desconto;
    char op;
    int i = 0;

    do{
        exibeProdutos(i, valorProdutos, total);

        printf("\nDigite o valor do %dº produto: R$ ", i+1);
        scanf("%f", &valorProdutos[i]);

        total += valorProdutos[i];
        i++;

        limpaTela();

        exibeProdutos(i, valorProdutos, total);

        printf("\nAdicionar mais um produto? (S/N)\n");
        printf(" - Escolha: ");
        fflush(stdin);
        scanf("%c", &op);

        op = tolower(op);

        limpaTela();
    }
    while(op == 's' || op == '1');

    exibeProdutos(i, valorProdutos, total);

    printf("\nAdicionar desconto ao valor total? (S/N)?");
    printf("\n - Escolha: ");
    fflush(stdin);
    scanf("%c", &op);

    limpaTela();

    if(op == 's'){
        total = descontoTotal(i, valorProdutos, total);
    }
    else{
        exibeProdutos(i, valorProdutos, total);
    }

    printf("\n\nCompra finalizada");
    printf("\n\nAperte qualquer tecla para continuar");
    getch();
    limpaTela();

    return total;
}

void sair(){
    int op;

    do{
        printf("\n\nTem certeza que deseja encerrar o programa?\n");
        printf("\n  1. Sim\n  2. Não\n");
        printf("\n  - Escolha: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                limpaTela();
                printf("\n\nPrograma encerrado\n\n\n\n\n");
                exit(0);
            break;

            case 2:
                limpaTela();
                return;
            break;

            default:
                printf("\n\nOpção inválida! Aperte qualquer tecla para tentar novamente");
                getch();
                limpaTela();
            break;
        }
    }
    while(op != 1 && op != 2);
}

// MENU ADM

void menuAdm(){
    int op;

    while(1){
        printf("\n\n\t --- Menu ADM ---\n\n");
        printf("  1. Usuários\n");
        printf("  2. Produtos\n");
        printf("  3. Clientes\n");
        printf("  4. Caixa\n");
        printf("  5. Estoque\n\n");
        printf("\n  6. Trocar usuário\n");
        printf("  0. Sair\n");
        printf("\n  - Escolha: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                limpaTela();
                telaUsuarios();
            break;

            case 2:
                limpaTela();
                telaProdutos();
            break;

            case 3:
                limpaTela();
                telaClientes();
            break;

            case 4:
                limpaTela();
                telaCaixa();
            break;

            case 5:
                limpaTela();
                FuncaoEstoque();
            break;

            case 6:
                limpaTela();
                login_usuario();
            break;

            case 0:
                limpaTela();
                sair();
            break;

            default:
                printf("\n\nOpção inválida! Aperte qualquer tecla para tentar novamente");
                getch();
                limpaTela();
            break;
        }
    }
}



void telaUsuarios(){
    int op;

    while(1){
        printf("\n\n\t --- Usuários ---\n\n");
        printf("  1. Registrar Usuário\n");
        printf("  2. Lista de Usuários\n\n");
        printf("  0. Voltar\n");
        printf("\n  - Escolha: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                limpaTela();
                registrar_usuario();
            break;

            case 2:
                limpaTela();
                listarUsuarios();
            break;

            case 0:
                limpaTela();
                return;
            break;

            default:
                printf("\n\nOpção inválida! Aperte qualquer tecla para tentar novamente");
                getch();
                limpaTela();
            break;
        }
    }
}

// MENU PRINCIPAL
void telaInicial(){
    incluirAdm();

    int op;

    while(1){
        printf("\n\n\t --- Início ---\n\n");
        printf("  1. Login\n");
        printf("  0. Sair\n");
        printf("\n  - Escolha: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                limpaTela();
                login_usuario();
            break;

            case 0:
                limpaTela();
                printf("\n\nPrograma encerrado\n\n\n");
                exit(0);
            break;

            default:
                printf("Opção inválida! Aperte qualquer tecla para tentar novamente");
                getch();
                limpaTela();
            break;
        }
    }
}

// CADASTRO DE CLIENTES (cadastra os clientes)
// chamada: cadClientes(&lista, &qtd);
void cadClientes(clientes **lista, int *qtd) {
    char continuar;

    do {
        *lista = realloc(*lista, (*qtd + 1) * sizeof(clientes));

        if (*lista == NULL) {
            printf("Erro ao alocar memória!\n");
            exit(1);
        }

        printf("\n\t --- Cadastro de Clientes ---\n");

        printf("\nNome completo: ");
        scanf(" %49[^\n]s", (*lista)[*qtd].nome);
        fflush(stdin);

        printf("\nCPF(apenas números): ");
        scanf("%11s", (*lista)[*qtd].cpf);
        fflush(stdin);

        printf("\nCelular com DDD(apenas números): ");
        scanf("%11s", (*lista)[*qtd].cel);
        fflush(stdin);

        (*qtd)++;

        limpaTela();

        printf("\n\tCliente cadastrado com sucesso!");

        printf("\n\nDeseja cadastrar outro cliente? (S/N)");
        printf("\n - Escolha: ");
        scanf(" %c", &continuar);

        continuar = tolower(continuar);

        limpaTela();

    } while (continuar == 's');
}

// EXIBE CLIENTES (exibe os clientes)
// chamada: exibeClientes(lista, qtd);
void exibeClientes(const clientes *lista, int qtd) {
    printf("\n\t    --- Clientes ---\n");

    if(qtd <= 0){
        printf("\nNenhum cliente cadastrado\n");
    }

    for (int i = 0; i < qtd; i++) {
        printf("\n--------------- Cliente %d ---------------\n\n", i + 1);
        printf("\t   Nome: %s\n", lista[i].nome);
        printf("\t    CPF: %.3s.%.3s.%.3s-%.2s\n", lista[i].cpf, lista[i].cpf + 3, lista[i].cpf + 6, lista[i].cpf + 9);
        printf("\tCelular: (%.2s) %.1s%.4s-%.4s\n", lista[i].cel, lista[i].cel + 2, lista[i].cel + 3, lista[i].cel + 7);
    }
    printf("\n-----------------------------------------\n");

    printf("\n  Aperte qualquer tecla para voltar");
    getch();
    limpaTela();
}

void telaClientes(){
    int op;

    while(1){
        printf("\n\n\t --- Clientes ---\n\n");
        printf("  1. Cadastrar Clientes\n");
        printf("  2. Exibir Clientes\n");
        printf("  0. Voltar\n");
        printf("\n  - Escolha: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                limpaTela();
                cadClientes(&lista, &qtd);
            break;

            case 2:
                limpaTela();
                exibeClientes(lista, qtd);
            break;

            case 0:
                limpaTela();
                return;
            break;

            default:
                printf("\nOpção inválida! Aperte qualquer tecla para tentar novamente");
                getch();
                limpaTela();
            break;
        }
    }
}

// EXIBE PRODUTOS (exibe os produtos)
void exibeProdutos(int i, float valorProdutos[], float total){
    for(int j = 0; j < i; j++){
        printf("\n\tProduto %d: R$ %.2f", j + 1, valorProdutos[j]);
    }

    if(i > 0) printf("\n\t\t-");

    printf("\n\t  Total: R$ %.2f \n", total);
    printf("\n----------------------------------\n");
}

// MÓDULO CAIXA DESCONTO (calcula o desconto total da compra)

void menuGeral(){
    int op;

    while(1){
        printf("\n\n\t --- Menu ---\n\n");
        printf("  1. Produtos\n");
        printf("  2. Clientes\n");
        printf("  3. Caixa\n");
        printf("  4. Estoque\n\n");
        printf("  5. Trocar usuário\n");
        printf("  0. Sair\n");
        printf("\n  - Escolha: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                limpaTela();
                telaProdutos();
            break;

            case 2:
                limpaTela();
                telaClientes();
            break;

            case 3:
                limpaTela();
                telaCaixa();
            break;

            case 4:
                limpaTela();
                //estoque();
            break;

            case 5:
                limpaTela();
                login_usuario();
            break;

            case 0:
                limpaTela();
                sair();
            break;

            default:
                printf("\n\nOpção inválida! Aperte qualquer tecla para tentar novamente");
                getch();
                limpaTela();
            break;
        }
    }
}


