/*
Objetivo : Calcular uma equacao do 2 grau.
Entrada : Coeficientes A,B,C.
Saida : Delta, X1 e X2.
Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int A, B, C;
    float delta, x1, x2;

    printf("Digite o coeficiente A: ");
    scanf("%d", &A);
    fflush(stdin);

    printf("Digite o coeficiente B: ");
    scanf("%d", &B);
    fflush(stdin);

    printf("Digite o coeficiente C: ");
    scanf("%d", &C);
    fflush(stdin);

    delta = (B * B) - 4 * A * B;

    x1 = (-B + sqrt(delta)) / (2 * A);
    x2 = (-B - sqrt(delta)) / (2 * A);
    printf("O valor de delta e: %f", delta);
    printf("O resultado e X1: %.2f e X2: %.2f\n", x1, x2);

    return (0);
}
