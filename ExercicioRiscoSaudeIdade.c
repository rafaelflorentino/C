/* 
 Objetivo : Verificar o risco de saúde das pessoas, de acordo com a idade.
 Entrada : Idade
 Saida : Tipo de risco po idade.
 Aluno : Rafael Florentino.
 */
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void classificaRisco(int num1);

int main()
{
    int num1;

    printf("\nDigite a sua idade: ");
    scanf("%d", &num1);
    fflush(stdin);

    classificaRisco(num1);

    printf("\n");
    getch();
    return 0;
}

void classificaRisco(int num1)
{
    if ((num1 >= 0) && (num1 <= 20))
    {
        printf("    Baixa  ");
    }
    if ((num1 > 20) && (num1 <= 45))
    {
        printf("    Media  ");
    }
    if ((num1 > 45) && (num1 <= 65))
    {
        printf("    Alta  ");
    }
    if (num1 > 66)
    {
        printf("    Muito Alto  ");
    }
}
