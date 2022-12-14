/*
 Objetivo : Exibir uma matriz 4X4.
 Entrada : Números.
 Saida :  Soma dos elementos.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int i = 0, j = 0, linha1 = 0, linha2 = 0, linha3 = 0, linha4 = 0;
    int coluna1 = 0, coluna2 = 0, coluna3 = 0, coluna4 = 0, diagonal1 =0, diagonal2 = 0;
    float matriz[4][4];

    printf("Entre com os dados da matriz: ");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
        // Entrada de números da matriz
            scanf("%f", &matriz[i][j]);
        // Soma linhas
            if (i == 0)
            {
                linha1 = linha1 + matriz[i][j];
            }
            if (i == 1)
            {
                linha2 = linha2 + matriz[i][j];
            }
            if (i == 2)
            {
                linha3 = linha3 + matriz[i][j];
            }
            if (i == 3)
            {
                linha4 = linha4 + matriz[i][j];
            }
        // Soma Colunas
            if (j == 0)
            {
                coluna1 = coluna1 + matriz[i][j];
            }
            if (j == 1)
            {
                coluna2 = coluna2 + matriz[i][j];
            }
            if (j == 2)
            {
                coluna3 = coluna3 + matriz[i][j];
            }
            if (j == 3)
            {
                coluna4 = coluna4 + matriz[i][j];
            }
        //Soma Diagonais
            if (i == j)
            {
                diagonal1 = diagonal1 + matriz[i][j];
            }
            if (i + j == 5)
            {
                diagonal2 = diagonal2 + matriz[i][j];
            }
        }
    }
    printf("\n");

    // Imprimindo Matriz 4X4
    printf("\nMatriz 4X4 \n\n");
        for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%0.0f ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Resultados Somas
    printf("\nLinhas\n\n");
    printf("A soma dos elementos da Linha 1 : %d \n", linha1);
    printf("A soma dos elementos da Linha 2 : %d \n", linha2);
    printf("A soma dos elementos da Linha 3 : %d \n", linha3);
    printf("A soma dos elementos da Linha 4 : %d \n", linha4);

    printf("\nColunas\n\n");
    printf("A soma dos elementos da Coluna 1 : %d \n", coluna1);
    printf("A soma dos elementos da Coluna 2 : %d \n", coluna2);
    printf("A soma dos elementos da Coluna 3 : %d \n", coluna3);
    printf("A soma dos elementos da Coluna 4 : %d \n", coluna4);
    printf("\nDiagonais\n\n");
    printf("A soma dos elementos da Diagonal Principal: %d \n", diagonal1);
    printf("A soma dos elementos da Diagonal Secundaria: %d \n", diagonal2);
    printf("\n\n");
    
    return 0;
}
