#include <stdio.h>
#include <locale.h>
float aplicarDesconto(float preco, float desconto) {
    return preco * (1 - desconto / 100);
}
int main() {
setlocale(LC_ALL,"portuguese");
    float precoProduto;
    float desconto;
    char aplicarDescontoOption;
    printf("Digite o preço do produto: R$ ");
    scanf("%f", &precoProduto);
    printf("Deseja aplicar um desconto neste produto? (s/n): ");
    scanf(" %c", &aplicarDescontoOption);
    if (aplicarDescontoOption == 's' || aplicarDescontoOption == 'S') {
        printf("Digite o valor do desconto em porcentagem: ");
        scanf("%f", &desconto);
        precoProduto = aplicarDesconto(precoProduto, desconto);
    }
    printf("Preço final do produto: R$ %.2f\n", precoProduto);
    return 0;
}
