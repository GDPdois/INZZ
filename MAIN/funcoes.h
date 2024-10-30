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
    cadCliente()
    exibeCliente()
    somaProdutos()
    descontoTotal()
    descontoProduto()
    exibeProdutos()
    limpaTela()
*/

// LIMPA TELA (limpa a tela)
void limpaTela(){
    system("cls");
}

// CADASTRO DE CLIENTES (cadastra os clientes)
// chamada: cadCliente(&lista, &qtd);
void cadCliente(clientes **lista, int *qtd) {
    char continuar;

    do {
        *lista = realloc(*lista, (*qtd + 1) * sizeof(clientes));

        if (*lista == NULL) {
            printf("Erro ao alocar memória!\n");
            exit(1);
        }

        printf("\n\t - Cadastro de Clientes -\n");

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
// chamada: exibeCliente(lista, qtd);
void exibeCliente(const clientes *lista, int qtd) {
    printf("\n\t - Clientes Cadastrados -\n");

    for (int i = 0; i < qtd; i++) {
        printf("\n--------------- Cliente %d ---------------\n\n", i + 1);
        printf("\t   Nome: %s\n", lista[i].nome);
        printf("\t    CPF: %.3s.%.3s.%.3s-%.2s\n", lista[i].cpf, lista[i].cpf + 3, lista[i].cpf + 6, lista[i].cpf + 9);
        printf("\tCelular: (%.2s) %.1s%.4s-%.4s\n", lista[i].cel, lista[i].cel + 2, lista[i].cel + 3, lista[i].cel + 7);
    }
    printf("\n-----------------------------------------\n");
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

// SOMA PRODUTOS (soma os produtos)
float somaProdutos(){
    float valorProdutos[100], total = 0, desconto;
    char op;
    int i = 0;

    do{
        exibeProdutos(i, valorProdutos, total);

        printf("\nDigite o valor do %dº produto: R$ ", i+1);
        scanf("%f", &valorProdutos[i]);

        printf("\nAplicar desconto no produto? (S/N)\n");
        printf(" - Escolha: ");
        fflush(stdin);
        scanf("%c", &op);

        op = tolower(op);

        limpaTela();

        if(op == 's') {
            do{
                exibeProdutos(i, valorProdutos, total);

                printf("\nValor sem desconto: %.2f", valorProdutos[i]);
                printf("\nDigite a porcentagem do desconto: ");
                scanf("%f", &desconto);

                if(desconto <= 0 || desconto > 100){
                    limpaTela();
                    printf("***O valor do desconto deve estar entre 1 e 100!\n");
                    printf("\n-------------------------------------------------\n");
                }
            }
            while(desconto <= 0 || desconto > 100);

            valorProdutos[i] = descontoProduto(valorProdutos[i], desconto);
        }

        op = '\0'; // limpa a variavel pra usar de novo

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

    op = '/0';

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

    return total;
}

