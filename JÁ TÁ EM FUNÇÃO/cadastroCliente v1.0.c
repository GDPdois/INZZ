#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

struct clientes{
    char nome[50], cpf[12], cel[12];
};

typedef struct clientes clientes;

int main(){
    setlocale(LC_ALL, "");

    clientes *lista = NULL;
    int qtd = 0;
    char continuar;

    //---CADASTRO CLIENTES---
    do{
        lista = realloc(lista, (qtd + 1) * sizeof(clientes));
        if (lista == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1;
        }

        printf("\n\t - Cadastro de Clientes -\n");

        printf("\nNome completo: ");
        scanf(" %49[^\n]s", &lista[qtd].nome);
        fflush(stdin);

        printf("\nCPF(apenas números): ");
        scanf("%11s", &lista[qtd].cpf);
        fflush(stdin);

        printf("\nCelular com DDD(apenas números): ");
        scanf("%11s", &lista[qtd].cel);
        fflush(stdin);

        qtd++;

        printf("\n\tCliente cadastrado com sucesso!");

        printf("\n\nDeseja cadastrar outro cliente? (S/N)");
        printf("\nResposta: ");
        scanf(" %c", &continuar);

        continuar = tolower(continuar);

        if(continuar == 's'){
            system("cls");
        }
    }
    while(continuar == 's');

    //---EXIBE CLIENTES---

    system("cls");

    printf("\n\t - Clientes Cadastrados -\n");

    for(int i = 0; i < qtd; i++){
        printf("\n--------------- Cliente %d ---------------\n\n", i+1);
        printf("\t   Nome: %s\n", lista[i].nome);
        printf("\t    CPF: %.3s.%.3s.%.3s-%.2s\n", lista[i].cpf, lista[i].cpf+3, lista[i].cpf+6, lista[i].cpf+9);
        printf("\tCelular: (%.2s) %.1s%.4s-%.4s\n", lista[i].cel, lista[i].cel+2, lista[i].cel+3, lista[i].cel+7);
    }
    printf("\n-----------------------------------------\n");
}
