//ARQUIVO DE FUNÇÕES

//MÓDULO CAIXA DESCONTO

void moduloCaixaDesconto(){
    float valorCompra, descontoPercentual, valorFinal;

    do{
        printf("\nDigite o valor da compra: R$ ");
        scanf("%f", &valorCompra);

        if(valorCompra <= 0){
            system("cls");
            printf("***O valor da compra não pode ser 0!\n");
        }
    }
    while(valorCompra <= 0);

    system("cls");

    do{
        printf("\nValor da compra: R$ %.2f\n", valorCompra);
        printf("\nDigite a porcentagem do desconto: ");
        scanf("%f", &descontoPercentual);

        if(descontoPercentual <= 0 || descontoPercentual > 100){
            system("cls");
            printf("***O valor do desconto deve estar entre 1 e 100!\n");
        }
    }
    while(descontoPercentual <= 0 || descontoPercentual > 100);

    valorFinal = valorCompra - (valorCompra * descontoPercentual / 100);

    system("cls");

    printf("\nValor da compra: R$ %.2f\n", valorCompra);
    printf("\nDesconto: %.f%%\n", descontoPercentual);
    printf("\nValor final: R$ %.2f\n", valorFinal);
}
