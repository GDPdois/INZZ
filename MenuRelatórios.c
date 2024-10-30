#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main()
{

    setlocale(LC_ALL, "");
    int opcao;

    printf ("----Menu de Relatórios---- \n");
    printf ("Qual deles deseja acessar? \n");
    printf ("1. Relatório de vendas \n");
    printf ("2. Relatório de estoque \n");
    printf ("0. Sair \n");
    scanf ("%i", &opcao);

    switch (opcao) {

        case 1:
            printf("Relatório de vendas \n"); //Função relatório vai entrar aqui.
        break;

        case 2:
            printf("Relatório de estoque \n"); //Função relatório vai entrar aqui.
        break;

        case 0:
            printf ("Saindo do menu de relatórios");
            exit(0);
        break;
    }
}

//FUNCIONANDO
