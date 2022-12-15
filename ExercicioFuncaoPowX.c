/* 
 Objetivo : Calcule, por meio de funções o valor de x(real) elevado a n(inteiro).
 Entrada : X real n inteiro.
 Saida : Resultado.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <math.h>

float elevado(float num1, int num2);

int main()
{
    float num1, resultado;
    int num2;

    printf("Digite o valor de x: ");
    scanf("%f", &num1);
    fflush(stdin);

    printf("Digite o valor de n: ");
    scanf("%d", &num2);
    fflush(stdin);

    resultado = elevado(num1, num2);

    printf("\nResultado: %f", resultado);
    printf("\n\n");
    return 0;
}

float elevado(float num1, int num2)
{
    return pow(num1, num2);
}
