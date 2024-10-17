
// ARQUIVO DE FUNÇÕES

// EXIBE PRODUTOS

void exibeProdutos(int i, float valorProdutos[], float total){
    for(int j = 0; j < i; j++){
        printf("\n\tProduto %d: R$ %.2f", j + 1, valorProdutos[j]);
    }

    if(i > 0) printf("\n\t\t-");

    printf("\n\t  Total: R$ %.2f \n", total);
    printf("\n----------------------------------\n");
}

// MÓDULO CAIXA DESCONTO

float moduloCaixaDesconto(int i, float valorProdutos[], float totalSemDesc){
    float descontoPercentual, valorDesconto, valorFinal;

    do{
        exibeProdutos(i, valorProdutos, totalSemDesc);

        printf("\nTotal sem desconto: R$ %.2f\n", totalSemDesc);
        printf("\nDigite a porcentagem do desconto: ");
        scanf("%f", &descontoPercentual);

        if(descontoPercentual < 0 || descontoPercentual > 100){
            system("cls");
            printf("***O valor do desconto deve estar entre 0 e 100!\n");
            printf("\n-------------------------------------------------\n");
        }
    }
    while(descontoPercentual <= 0 || descontoPercentual > 100);

    valorFinal = totalSemDesc - (totalSemDesc * descontoPercentual / 100);
    valorDesconto = totalSemDesc - valorFinal;

    system("cls");

    printf("\nTotal sem desconto: R$ %.2f\n", totalSemDesc);
    printf("\nDesconto: %.f%% -> -%.2f\n", descontoPercentual, valorDesconto);
    printf("\nTotal com desconto: R$ %.2f\n", valorFinal);

    return valorFinal;
}

// SOMA PRODUTOS

float somaProdutos(){
    float valorProdutos[100], total = 0;
    char op;
    int i = 0;

    do{
        exibeProdutos(i, valorProdutos, total);


        printf("\nDigite o valor do %dº produto: R$ ", i+1);
        scanf("%f", &valorProdutos[i]);

        total += valorProdutos[i];
        i++;

        system("cls");

        exibeProdutos(i, valorProdutos, total);

        printf("\nAdicionar mais um produto? (S/N)\n");
        printf(" - Escolha: ");
        fflush(stdin);
        scanf("%c", &op);

        op = tolower(op);
        system("cls");
    }
    while(op == 's' || op == '1');

    total = moduloCaixaDesconto(i, valorProdutos, total);

    return total;
}
