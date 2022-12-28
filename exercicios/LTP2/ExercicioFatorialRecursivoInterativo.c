/*
 Objetivo : Escreva um programa em C mostre o fatorial interativo e recursivo.
 Entrada : Número inteiro.
 Saida : O fatorial interativo e recursivo.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int fatIter(int N);
int fatRec(int N);

int main()
{
    int num = 0, fatIter(int N), fatRec(int N);

    printf("Digite um numero inteiro entre 0 a 13: ");
    scanf("%d", &num);

    while (num < 0 || num > 13)
    {
        printf("\n numero invalido \n");
        printf("Digite um numero inteiro entre 0 a 13: ");
        scanf("%d", &num);
    }
    printf("Fatorial Interativo: %d \n", fatIter(num));
    printf("Fatorial Recursiva: %d \n", fatRec(num));

    return 0;
}

int fatIter(int N)
{
    int fatorial = 1, cont;
    for (cont = 1; cont <= N; cont++){
        fatorial = fatorial * cont;
    }
    return (fatorial);
}

int fatRec(int N)
{
    if (N == 0){
        return 1;
    }else{
        return (fatRec(N - 1) * N);
    }
}
