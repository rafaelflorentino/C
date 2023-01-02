/*
 Objetivo : Escreva um programa em C que receba números e faça a soma recursiva, -1 para cado laço do loop, interativa e recursiva.
 Entrada : Números.
 Saida : Lista dos Números.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
int fsomaIter(int N);
int fsomaRec(int N);
int main()
{
    int N, n[10], n1[10], n2[10], Q, i, aux, soma;
    printf("\nDigite a quantidade de numeros: ");
    scanf("%d", &Q);
    fflush(stdin);

    for (i = 0; i < Q; i++)
    {
        printf("\nNumero %d \n",i + 1);
        printf("Digite um numero positivo: ");
        scanf("%d", &n[i]);
        fflush(stdin);

        n1[i] = fsomaIter(n[i]);
        n2[i] = fsomaRec(n[i]);

        printf("\n");
        system("pause");
        system("cls");
    }
    printf("\n\t                 Lista de Todos os Numeros\n ");
    printf("\n\t                   \tInterativa        \tRecursiva \n");

    for (i = 0; i < Q; i++)
    {
    printf("\n\tNumero: %d ------> \tSomatorio = %d ------> \tSomatorio = %d ", n[i], n1[i], n2[i]);
        
    }
    printf("\n\n");
    return 0;
}

// Função Interativa
int fsomaIter(int N)
{
    int aux = 0, i, soma = 0;
    aux = N;

    for (i = 0; i < N; i++)
    {
        soma = soma + aux;
        aux--;
    }
    return soma;
}

// Função Recursiva
int fsomaRec(int N)
{
    if (N == 1)
    {
        return 1;
    }
    else
    {
        return (fsomaRec(N - 1) + N);
    }
}
