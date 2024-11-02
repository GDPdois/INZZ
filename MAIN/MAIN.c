#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <locale.h>

#include "funcoes.h"
#include "fncStrctsGeral.h"
#include "Estoque.c"

int main(){
    setlocale(LC_ALL, "");

    tela_boas_vindas();
    Sleep(1000);
    limpaTela();

    telaInicial();

    return 0;
}


