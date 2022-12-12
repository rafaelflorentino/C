/*
 Objetivo : Reajuste salarial de 20 pessoas.
 Entrada : Nome, sálario.
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

    for (i = 1; i <= 20; i++)
    {
        printf("Usuario numero: %d \n Informe seu nome: \n", i+1);
        scanf(" %[^\n]", &nome[i]);
        printf("Informe seu salario: \n");
        scanf("%f", &salario[i]);
        fflush(stdin);

        reajuste[i] = salario[i] + (salario[i] * 0.06);
        printf("\n");
        system("cls");
    }
    for (i = 1; i <= 20; i++)
    {
        printf("%d. %s:  reajuste salarial: %0.2f \n", i, nome[i], reajuste[i]);
    }
    system("pause");
    return (0);
}
