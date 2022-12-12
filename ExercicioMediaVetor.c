/* 
 Objetivo : Calcular e armazenar a média. Armazenar também a situação do aluno: AP (aprovado) ou RP (reprovado).
 Entrada : Nome, prova A, prova B.
 Saida : Média, aprovado ou reprovado.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main()
{
    int i;
    char nome[15][50], resultado[15][3];
    float provaA1[15], provaA2[15], media[15];

    for (i = 0; i < 4; i++)
    {
        printf("    Aluno n. %d    \n\n", i+1);
        printf("Informe o nome do aluno: ");
        gets(nome[i]);
        printf("Informe a valor da prova A1: ");
        scanf("%f", &provaA1[i]);
        printf("Informe o valor da prova A2: ");
        scanf("%f", &provaA2[i]);
        fflush(stdin);

        media[i] = (((provaA1[i]) + (provaA2[i])) / (2));
        if ((media[i]) >= (7))
        {
            strcpy(resultado[i], "AP");
        }
        else
        {
            strcpy(resultado[i], "RP");
        }
        printf("\n");
        system("pause");
        system("cls");
    }
    printf("Aluno\t\tMedia\t\tResultado\n");
    for (i = 0; i < 4; i++)
    {
        printf("%s\t\t%0.2f\t\t%s\n", nome[i], media[i], resultado[i]);
    }
    printf("\n");
    system("pause");

    return (0);
    
}
