#include <stdio.h>

int main() {
    float p1, p2, total;

    printf("\nInsira o valor do primeiro produto: ");
    scanf("%f", &p1);
    
    printf("\nInsira o valor do segundo produto: ");
    scanf("%f", &p2);

    total = p1 + p2;

    printf("\nTotal a pagar: %.2f\n", total);

    return 0;
}
