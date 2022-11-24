/*
Objetivo :Calcular a area de um triangulo
Entrada : Base, Altura
Saida : Area do triangulo
Aluno : Rafael F Barbosa
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float base, altura;
    float area;

    printf("Digite a base do triangulo: ");
    scanf("%f", &base);
    fflush(stdin);

    printf("Digite a altura do triangulo: ");
    scanf("%f", &altura);
    fflush(stdin);

    area = (base * altura) / 2;

    printf("A area da circunferencia e: %f", area);

    return 0;
}
