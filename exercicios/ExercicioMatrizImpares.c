/*
 Objetivo : Construir uma matriz A so com números ímpares e uma matriz B só com números pares, e uma matriz C que e a junção das duas
 Entrada : Números.
 Saida :  Matriz C.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0, j = 0;
    // int matriz[3][3], A[3][3], B[3][3], C[3][3];
    int A[3][3] = {{1, 3, 5},
                   {7, 9, 11},
                   {13, 15, 17}};
    int B[3][3] = {{2, 4, 6},
                   {8, 10, 12},
                   {14, 16, 18}};
    int C[3][3];

    // Criando matriz C
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Imprimindo Matriz A
    printf("\nMatriz A \n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%2d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Imprimindo Matriz B
    printf("\nMatriz B\n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%2d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Imprimindo Matriz C
    printf("\nMatriz C \n\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%2d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
