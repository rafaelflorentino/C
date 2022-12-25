/* 
 Objetivo  : Tamanho de uma organização populacional de acordo com a população(vila, distrito, cidade, metropole).
 Entrada : Número da População.
 Saida : Tipo de organização.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void classificaPopulacao(int num1);

int main()
{
    int num1;

    while (num1 != 0)
    {
        printf("\nDigite o numero da populacao ou (0)zero para sair: ");
        scanf("%d", &num1);
        fflush(stdin);

        classificaPopulacao(num1);
        printf("\n");
    }
    getch();
    return 0;
}

void classificaPopulacao(int num1)
{
    if ((num1 >= 1) && (num1 <= 5000))
    {
        printf("    Vila  ");
    }
    if ((num1 > 5000) && (num1 <= 15000))
    {
        printf("    Distrito  ");
    }
    if ((num1 > 15000) && (num1 <= 1000000))
    {
        printf("    Cidade  ");
    }
    if (num1 > 1000000)
    {
        printf("    Metropole  ");
    }
}
