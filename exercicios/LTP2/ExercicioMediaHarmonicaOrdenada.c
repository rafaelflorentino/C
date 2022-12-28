/*
 Objetivo : Escreva um programa em C que gere varias notas e calcule a media harmonica e a media aritimetica.
 Entrada : Sem Entrada.
 Saida : Os números aleatorios e seus fatoriais.
 Aluno: Rafael Florentino.
*/
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include<time.h>
int main()
{
    int I, Aux, Varreduras;
    float X, Y, Z, V[30], mediaA, mediaH;
    srand(time(NULL));
    system("color 03");

    // Geracao os 30 valores
    for (I = 0; I < 30; I++)
    {
       // V[I] = (rand() % (918 - 26 + 1) + 26) / 10.0;
        V[I] = (rand() % 110) / 10.0;
        X = X + V[I];
    }
    // Ordenacao Crescente
    for (Varreduras = 0; Varreduras < 28; Varreduras++)
    {
        for (I = 0; I < 28; I++)
        {
            if (V[I] > V[I + 1])
            {
                Aux = V[I];
                V[I] = V[I + 1];
                V[I + 1] = Aux;
            }
        }
    }
    // Calculo da Media harmonica
    //  Media harmonica: (30/((1/numero1)+(1/numero2)+(1/numero3)+(........)+(........))));
    for (I = 0; I < 30; I++)
    {
        Y = 1 / V[I];
        Z = Z + Y;
    }
    // Escrita dos valores
    printf("\n\nNumeros Ordenados CRESCENTE: \n");
    for (I = 0; I < 30; I++)
    {
        printf("\nV[%2d] = %.1f", I, V[I]);
    }
    // Escrita das Medias
    mediaA = X / 30;
    mediaH = 30 / Z;
    printf("\n\nA Media Aritmetica e : %.1f \n", mediaA);
    printf("\n\nA Media Harmonica e : %.1f \n", mediaH);

    // Numeros que estejam acima da Media Aritmetica
    printf("\n\nNumeros Acima da Media Aritimetica: \n");
    for (I = 0; I < 30; I++)
    {
        if (V[I] > mediaA)
        {
            printf("\nV[%2d] = %.1f", I, V[I]);
        }
    }
    // Numeros que estejam abaixo da Media Harmonica
    printf("\n\nNumeros Abaixo da Media Harmonica: \n");
    for (I = 0; I < 30; I++)
    {
        if (V[I] < mediaH)
        {
            printf("\nV[%2d] = %.1f", I, V[I]);
        }
    }
    // Ordenacao dos 30 valores Decrescente
    for (Varreduras = 0; Varreduras <= 28; Varreduras++)
    {
        for (I = 28; I >= 0; I--)
        {
            if (V[I] > V[I - 1])
            {
                Aux = V[I];
                V[I] = V[I - 1];
                V[I - 1] = Aux;
            }
        }
    }

    printf("\n\n Numeros Ordenados Decrescente: \n");
    for (I = 0; I < 30; I++)
    {
        printf("\nV[%2d] = %.1f", I, V[I]);
    }

    // Finalizacao
    printf("\n\nPressione qualquer TECLA para TERMINAR ...");
    getch();
    return 0;
}
