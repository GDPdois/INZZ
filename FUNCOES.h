
//ARQUIVO DE FUNÇÕES

//SOMA PRODUTOS

float somaProdutos(){
    float preco[100], total=0;
    char controle='S';
    int i=0;
    do{

    printf("\nO valor total da compra está em %.2f \n", total);
    printf("Digite o valor do %dº produto \n", i+1);
    scanf("%f", &preco[i]);
    total += preco[i];
    i++;


    printf("Quer mais? Caso sim digite S \n");
    fflush(stdin);
    scanf("%c", &controle);
    controle=tolower(controle);
    system("cls");

    }
    while(controle == 's');

    printf("O valor da compra foi %.2f", total);

    return total;
}

//MÓDULO CAIXA DESCONTO

void moduloCaixaDesconto(float totalSemDesc){
    float /*valorCompra,*/ descontoPercentual, valorFinal;

    /*do{
        printf("\nDigite o valor da compra: R$ ");
        scanf("%f", &valorCompra);

        if(valorCompra <= 0){
            system("cls");
            printf("***O valor da compra não pode ser 0!\n");
        }
    }
    while(valorCompra <= 0);

    system("cls");*/

    do{
        printf("\nValor da compra: R$ %.2f\n", totalSemDesc);
        printf("\nDigite a porcentagem do desconto: ");
        scanf("%f", &descontoPercentual);

        if(descontoPercentual <= 0 || descontoPercentual > 100){
            system("cls");
            printf("***O valor do desconto deve estar entre 1 e 100!\n");
        }
    }
    while(descontoPercentual <= 0 || descontoPercentual > 100);

    valorFinal = totalSemDesc - (totalSemDesc * descontoPercentual / 100);

    system("cls");

    printf("\nValor da compra: R$ %.2f\n", totalSemDesc);
    printf("\nDesconto: %.f%%\n", descontoPercentual);
    printf("\nValor final: R$ %.2f\n", valorFinal);
}
