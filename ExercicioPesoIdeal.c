/* 
 Objetivo :Algoritimo que calcule o peso ideal,
 Entrada : Peso , altura e sexo
 Saida : Peso ideal.
 Aluno : Rafael Florentino.
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    float altura, peso, idealm, idealf;
    char sexo;

    printf("Digite o seu sexo (m ou f): ");
    scanf("%c", &sexo);
    fflush(stdin);

    printf("Digite o seu peso: ");
    scanf("%f", &peso);
    fflush(stdin);

    printf("Digite a sua altura: ");
    scanf("%f", &altura);
    fflush(stdin);

    if (sexo == 'm')
    {
        idealm = (72.7 * altura) - 58;
        printf("O seu peso ideal e: %f", idealm);
    }
    if (sexo == 'f')
    {
        idealf = (62.1 * altura) - 44.7;
        printf("O seu peso ideal e: %f", idealf);
    }
    
    return 0;
}
