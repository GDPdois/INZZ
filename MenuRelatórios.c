#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "");
    int opcao;

    printf ("1. Relatório de vendas \n");
    printf ("2. Relatório de estoque \n");
    printf ("0. Sair \n");
    printf ("Qual deles deseja acessar? \n");
    scanf ("%i", &opcao);

    switch (opcao) {

        case 1:
            printf("Relatório de vendas \n"); //Função relatório vai entrar aqui.
        break;

        case 2:
            printf("Relatório de estoque \n"); //Função relatório vai entrar aqui.
        break;

        case 0:
            printf ("Saindo do menu relatórios");
            exit(0);
        break;
    }
}

//FUNCIONANDO
