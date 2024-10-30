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

    tela_boas_vindas();
    Sleep(2000);
    limpaTela();

    menuPrincipal();

    return 0;
}
