/*
 Objetivo : Escreva um programa em C que gere 20 numeros aleatorios e calcule o fatorial deles.
 Entrada : Sem Entrada.
 Saida : Os números aleatorios e seus fatoriais.
 Aluno: Rafael Florentino.
*/
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
int fatIter(int N);
int fatRec(int N);
int main()
{
    int I, j, numero = 0;
    srand (time(NULL));

    printf("Gerando 20 inteiros aleatorios entre -15 e 30...\n\n");
    for (I = 1; I <= 20; I++)
    {
        //numero = rand() % +30 - 15, rand() ^ 5;      
        numero = ( rand() % 45 ) + (-15); //entre -15 e 30
        printf("Numero aleatorio: %d   \n", numero);
        printf("Fatorial Interativo: %d \n", fatIter(numero));
        printf("Fatorial Recursiva: %d \n", fatIter(numero));
        printf("\n");
    }
    //printf("\nPressione qualquer TECLA  ...");
   // getch();
    return 0;
}
int fatIter(int N)
{

    int fatorial = 1, cont;
    for (cont = 1; cont <= N; cont++)
    {
        fatorial = fatorial * cont;
    }
    return (fatorial);
}

int fatRec(int N)
{
    if (N == 0)
    {
        return 1;
    }
    else
    {
        return (fatRec(N - 1) * N);
    }
}
