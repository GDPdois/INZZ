#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
setlocale(LC_ALL,"");

    float preco[100], total=0;
    char controle='S';
int i=0;
do {

    printf ("\nO valor total da compra está em %.2f \n", total);
    printf ("Digite o valor do %dº produto \n", i+1);
    scanf ("%f", &preco[i]);
    total += preco[i];
    i++;


    printf ("Quer mais? Caso sim digite S \n");
    fflush(stdin);
    scanf ("%c", &controle);
    controle=tolower(controle);
    system("cls");

}
while (controle == 's');

printf ("O valor da compra foi %.2f", total);


}

//FUNCIONANDO
