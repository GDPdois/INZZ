#include <stdio.h>

int main() {
    int opcao = -1;
    
    while (opcao != 0) {
        printf("Menu:\n");
        printf("1. Menu de Vendas\n");
        printf("2. Menu de Estoque\n");
        printf("3. Menu de Clientes\n");
        printf("4. Menu de Funcionarios\n");
        printf("0. Sair\n");
        printf("Digite o numero: ");
        scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Relatório de Vendas...\n");
    } else if (opcao == 2) {
        printf("Relatório de Estoque...\n");
    } else if (opcao == 3) {
        printf("Relatório de Clientes...\n");
    } else if (opcao == 4) {
        printf("Relatório de Funcionários...\n");
    } else if (opcao == 0) {
        printf("Saindo...\n");
    } else {
        printf ("Invalido!\n");
    }
}

return 0;
}

//FUNCIONANDO

