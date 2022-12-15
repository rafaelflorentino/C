/*
 Objetivo: Implemente um programa em C que mostre os endereços, valores, das variaveis e ponteiros.
 Entrada : Sem entrada.
 Saida : Valores das variaveis, dos Ponteiros e endereços das variaveis.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 7, *px = &x;
    float y = 9, *py = &y;

    // Mostre os valores de x, y, px e py
    printf("\nValores de x, y e px, py\n");
    printf("x = %d\n", x);
    printf("px = %ld\n", px);
    printf("y = %.2f\n", y);
    printf("py = %ld\n", py);
    printf("\n");

    // Mostre os endereços de memória de x, y, px e py
    printf("\nEnderecos de memoria de x, y e px, py\n");
    printf("Enderecos de x = %d\n", &x);
    printf("Enderecos de px = %ld\n", &px);
    printf("Enderecos de y = %.2f\n", &y);
    printf("Enderecos de py = %ld\n", &py);
    printf("\n\n");

    // Valores apontados por px e py
    printf("\nValores apontados por px e py\n");
    printf("Enderecos de *px = %ld\n", *px);
    printf("Enderecos de *py = %.2f\n", *py);
    printf("\n");

    //O resultado do incremento +1 de x, y e px, py;
    printf("\nIncremento + 1 de x, y e px, py\n");
    printf("x + 1 = %d\n", x + 1);
    printf("px + 1 = %ld\n", px + 1);
    printf("y + 1 = %.2f\n", y + 1);
    printf("py + 1 = %ld\n", py + 1);
    printf("\n");

    //O resultado do decremento -1 de x, y e px, py;
    printf("\nDecremento - 1 de x, y e px, py\n");
    printf("x - 1 = %d\n", x - 1);
    printf("px - 1 = %ld\n", px - 1);
    printf("y - 1 = %.2f\n", y - 1);
    printf("py - 1 = %ld\n", py - 1);
    printf("\n");

    float *pA, *pB;//ponteiro
    int pa, pb;

    pa =  7;
    pb =  9;

    printf("\nValor de PA: %d Valor de PB: %d\n", pA, pB);
    printf("\nDiferenca entre os ponteiros PA - PB: %d\n", (pA - pB));
    printf("\n");
    
    // Converter inteiroa em float
    printf("\nValor de pa: %0.2f Valor de pb: %0.2f\n", (float)pa, (float)pb);
    printf("\nDiferenca entre PA - PB: %0.2f\n", (float)(pa - pb));
    printf("\n\n");

    return 0;
}
