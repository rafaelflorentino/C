/*
 Objetivo : Escreva um programa em C que gere uma matriz e preencha com numeros aleatorios, depois calcule as medias e soma das colunas.
 Entrada : Sem Entrada.
 Saida : Matriz com números aleatorios, médias e somas das linhas ou colunas.
 Aluno: Rafael Florentino.
*/
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
int main()
{
    int i = 0, j = 0, cont, cont2 = 0;
    float m[10][10];
    float v = 0, soma = 0, soma2 = 0, soma3 = 0, soma4 = 0, soma5 = 0, mediaA = 0, mediaH = 0, mediaColuSete = 0, a = 0, Y = 0, Z = 0;
    
    // Gerar a matriz e preencher com os numeros aleatorios
    printf("\n\n                            Matriz 10 X 10\n\n ");    
    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            //m[i][j] = (rand() % (502 - 1 + 1) + 1) / 100.0;
            m[i][j] = (rand() % 101) / 10.0;

            // Calculo da Média Aritmética de toda a Matriz
            soma = soma + m[i][j];
            mediaA = soma / 100;
            // Soma da quarta linha
            if (i == 3)
            {
                soma2 = soma2 + m[i][j];
            }
            // Média Aritmética da setima coluna
            if (j == 6)
            {
                cont = cont + 1;
                soma3 = soma3 + m[i][j];
                mediaColuSete = soma3 / cont;
            }
            // Média Geométrica da Diagonal Principal;
            if (i == j)
            {
                soma5 = soma5 + m[i][j];
            }
            // Média Harmonica da Diagonal secundaria;
            if ( i + j == 9){
                Y = 1 / m[i][j];
                Z = Z + Y;
            }

        }
    }
    mediaH = 100 / Z;

    // Imprimir a matriz
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("\t%.2f", m[i][j]);
        }
        printf("\n");
    }   
    printf("\nMedia aritimetica da matriz e: %f\n", mediaA);
    printf("\nA Soma da Quarta linha e: %f\n", soma2);
    printf("\nMedia aritimetica da setima coluna e: %f\n", mediaColuSete);
    printf("\nMedia geometrica da diagonal principal e: %f\n", pow(soma5, (float)1 / 10));
    printf("\nMedia harmonica da diagonal secundaria e: %f\n", mediaH);
    printf("\n\n");
    system("pause");
}
