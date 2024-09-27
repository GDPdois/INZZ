#include <stdio.h>
#include <conio.h>


struct cliente
{
 char cpf [15];
 char nome [70];
 int numero;
};

int main()
{

struct cliente Thales;
printf ("Insira o CPF do cliente \n");
gets (Thales.cpf);
fflush(stdin);
printf ("Insira o número de telefone do cliente \n");
scanf("%d", &Thales.numero);
fflush (stdin);
printf ("Insira o nome do cliente \n");
gets(Thales.nome);
printf ("Cadastro do cliente \n");
printf ("Nome: %c \n",Thales.nome);
printf ("CPF: %c \n", Thales.cpf);
printf ("Número: %d \n", Thales.numero);




}

