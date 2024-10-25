#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "");
    int opcao = -1;

    while (opcao != 0)
    {
        printf("Menu:\n");
        printf("1. Relatório de Vendas\n");
        printf("2. Relatório de Estoque\n");
        printf("0. Sair\n");
        printf("Digite o numero: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("Relatório de Vendas...\n"); // Aqui vai uma função de relatorio de vendas
        }
        else if (opcao == 2)
        {
            printf("Relatório de Estoque...\n"); // Aqui vai uma função de relatório de estoque
        }
        else
        {
            printf("Opção Inválida!\n");
        }
    }

    return 0;
}