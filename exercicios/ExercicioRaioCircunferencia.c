/*
Objetivo : Calcular a area da circunferencia.
Entrada : O raio.
Saida : Medir area da circunferência.
Autor : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

int main()
{
    float raio;
    float area;

    printf("Digite o raio da circunferencia: ");
    scanf("%f", &raio);
    fflush(stdin);

    area = PI * (raio * raio);
    printf("A area da circunferencia e: %f", area);
    
    return 0;
}
