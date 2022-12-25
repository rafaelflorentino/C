/*
 Objetivo : Reajuste salarial.
 Entrada : Nome, salário.
 Saida : Nome, salário rejustado.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int i, quantidade;
    char nome[100][50];
    float salario[100], reajuste[100];

    printf("Informe a quantidade de pessoas: \n");
    scanf("%d", &quantidade);
    for (i = 1; i <= quantidade; i++)
    {
        printf("Usuario numero: %d \n Informe seu nome: \n", i);
        scanf(" %[^\n]", &nome[i]);
        printf("\nInforme seu salario: \n");
        scanf("%f", &salario[i]);
        fflush(stdin);
        if (salario[i] < 500.00)
        {
            reajuste[i] = salario[i] * 1.08;
        }
        else
        {
            reajuste[i] = salario[i] * 1.05;
        }
        system("pause");
        system("cls");
    }
    for (i = 1; i <= quantidade; i++)
    {
        printf("%d) %s:  reajuste salarial: %0.2f \n", i, nome[i], reajuste[i]);
    }
    system("pause");
    return (0);
}
