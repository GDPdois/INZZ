#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <locale.h>

#include "funcoes.h"
#include "funcoesStructsInterfaceGeral.h"

int main(){
    setlocale(LC_ALL, "");

    char op = '1';

    tela_boas_vindas();
    Sleep(2000);
    limpaTela();

    do{
        printf("\n\n\t - Menu Principal -\n\n");
        printf("  1. Registrar\n");
        printf("  2. Login\n");
        printf("  3. Sair\n");
        printf("\n  - Escolha: ");
        scanf(" %c", &op);

        switch(op){
            case '1':
                limpaTela();
                registrar_usuario();
            break;

            case '2':
                limpaTela();
                login_usuario();
            break;

            case '3':
                limpaTela();
                printf("\n\nPrograma encerrado\n\n\n");
                exit(0);
            break;

            default:
                printf("Opção inválida! Aperte qualquer tecla para tentar novamente");
                getch();
                limpaTela();
            break;
        }
    }
    while(op < '1' || op > '3');

    return 0;
}
