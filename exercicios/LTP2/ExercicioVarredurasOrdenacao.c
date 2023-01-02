/*
 Objetivo : Escreva um programa em C que gere números aleatórios e os ordene.
 Entrada : Sem Entrada.
 Saida : Números aleatórios ordenados.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int V[30], I, Varreduras, Aux;

    srand(time(NULL));
    for (I = 0; I < 30; I++)
    {
        V[I] = (rand() % 900 + 100);
    }

    for (Varreduras = 0; Varreduras <= 28; Varreduras++)
    {
        for (I = 0; I <= 28; I++)
        {
            if (V[I] > V[I + 1])
            {
                Aux = V[I];
                V[I] = V[I + 1];
                V[I + 1] = Aux;
            }
        }
    }
    printf("\n\tNumeros Aleatorios Ordenados:\n\n");
    for (I = 0; I < 30; I++)
    {
        printf("\nV[%2d] = %d", I, V[I]);
    }
    return 0;
}
