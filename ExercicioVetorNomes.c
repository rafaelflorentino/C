/*
 Objetivo : Armazenar 10 nomes em um vetor NOME e imprimir uma listagem numerada.
 Entrada : Nomes.
 Saida : Lista numerada.
 Aluno : Rafael Florentino.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main()
{
    char nome[10][10];
    int i;

    for (i = 1; i < 5; i++)
    {
        puts("Digite seu nome: ");
        gets(nome[i]);
        fflush(stdin);

    }
    printf("\n");

    for (i = 1; i < 5; i++)
    {
        printf("%d) ", i);
        puts(nome[i]);
    }

}
