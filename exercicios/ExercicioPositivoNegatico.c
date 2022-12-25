/*
 Objetivo : Mostre se um número é positivo, negativo ou nulo (zero).
 Entrada : Um número.
 Saida : Positivo , negativo ou nulo.
 Aluno : Rafael Florentino.
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int num1;
    
    printf("Digite um numero: ");
    scanf("%d", &num1);
    fflush(stdin);

    if (num1 == 0)
        printf("O numero: %d e nulo(zero).", num1);

    if (num1 < 0)
        printf("O numero: %d e negativo.", num1);

    if (num1 > 0)
        printf("O numero: %d e positivo.", num1);
    getch();

    return 0;
}
