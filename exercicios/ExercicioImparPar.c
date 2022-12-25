/* 
 Objetivo : Um algoritmo que leia um número e mostre se ele é par ou ímpar.
 Entrada : Um número inteiro qualquer.
 Saida : Mensagem de impar ou par.
 Aluno : Rafael Florentino.
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int num1;

    printf("Digite um numero: ");
    scanf("%i", &num1);
    fflush(stdin);

    if (num1 % 2 == 0)
        printf("O numero: %i e par.", num1);

    if (num1 % 2 == 1)
        printf("O numero: %i e impar.", num1);
    getch();

    return 0;
}
