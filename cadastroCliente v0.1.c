#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 1

struct clientes{
    char nome[50], cpf[12], cel[12];
};

typedef struct clientes clientes;

int main(){
    setlocale(LC_ALL, "");

    clientes lista[TAM];

    //---CADASTRO CLIENTES---

    for(int i = 0; i < TAM; i++){
        printf("\nNome completo: ");
        scanf("%49[^\n]s", &lista[i].nome);

        printf("\nCPF(apenas números): ");
        scanf("%11s", &lista[i].cpf);

        printf("\nCelular com DDD(apenas números): ");
        scanf("%11s", &lista[i].cel);
    }

    //---EXIBE CLIENTES---

    for(int i = 0; i < TAM; i++){
        printf("\n--------------- Cliente %d ---------------\n\n", i+1);
        printf("\t   Nome: %s\n", lista[i].nome);
        printf("\t    CPF: %.3s.%.3s.%.3s-%.2s\n", lista[i].cpf, lista[i].cpf+3, lista[i].cpf+6, lista[i].cpf+9);
        printf("\tCelular: (%.2s) %.1s%.4s-%.4s\n", lista[i].cel, lista[i].cel+2, lista[i].cel+3, lista[i].cel+7);
    }
    printf("\n-----------------------------------------\n");
}




