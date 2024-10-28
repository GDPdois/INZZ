
// ARQUIVO DE FUNÇÕES

// FUNÇÕES NO ARQUIVO:
// somaProdutos()
// descontoTotal()
// descontoProduto()
// exibeProdutos()
// limpaTela()

// LIMPA TELA (limpa a tela)
void limpaTela(){
    system("cls");
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
