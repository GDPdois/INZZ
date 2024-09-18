#include <stdio.h>

int main () {
    float valorCompra, descontoPercentual, valorFinal;

    printf("Digite o valor da compra: R$ ");
    scanf("%f", &valorCompra);
    
    printf("Digite a porcentagem de desconto: ");
    scanf("%f", &descontoPercentual);

    valorFinal = valorCompra - (valorCompra * descontoPercentual / 100);

    printf("O valor final com o desconto é: R$ %.2f\n", valorFinal);

    return 0;
}
