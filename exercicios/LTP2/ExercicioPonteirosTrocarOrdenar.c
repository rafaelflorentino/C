/*
 Objetivo : Escreva um programa em C que troque o valores entre dois vetores, valores gerados de forma aleatoria, e no final ordene imprima em ordem crescente.
 Entrada : Sem Entrada.
 Saida : Valores trocados e listados em ordem crescente.
 Aluno: Rafael Florentino.
*/
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void Trocar(int *V, int *Y) // Procedimento TROCAR
{
    int Aux1;
    Aux1 = *V;
    *V = *Y;
    *Y = Aux1;
}

int main()
{
    int I, X = 10, Y[4], V[4], Varreduras, Aux;

    printf("\nValores Aleatorios Gerados:\n");
    for (I = 0; I < 4; I++)
    {
        V[I] = (rand() % 20 + 10);
        Y[I] = (rand() % 20 + 10);
        printf("\nV[%d] = %d;  Y[%d] = %d", I, V[I], I, Y[I]);
    }
    // Troca dos valores
    for (I = 0; I < 4; I++)
    {
        printf("\n\n Troca %d", I+1);
        printf("\n\nV=%d    Y=%d\n", V[I], Y[I]);
        Trocar(&V[I], &Y[I]);
        printf("V=%d    Y=%d\n", V[I], Y[I]);
    }
    // Ordenação CRESCENTE
    for (Varreduras = 0; Varreduras <= 2; Varreduras++){
        for (I = 0; I <= 2; I++){
            if (V[I] > V[I + 1])
            {
                Aux = V[I];
                V[I] = V[I + 1];
                V[I + 1] = Aux;
            }
        }
    }
    // Escrita dos valores trocados Ordenados
    printf("\n\nNumeros Trocados Em Ordem CRESCENTE: \n");
    for (I = 0; I < 4; I++)
    {
        printf("\nV[%d] = %d", I, V[I]);
    }
     printf("\n ");
}
