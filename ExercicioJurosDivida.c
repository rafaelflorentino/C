/*
Objetivo : Calcular os juros de uma dívida.
Entrada : Valor da divida, taxa de juros.
Saida : Juros.
Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float divida, juros, calculo;

    printf("Digite o valor da divida: ");
    scanf("%f", &divida);
    fflush(stdin);

    printf("Digite a taxa de juros ao mes: ");
    scanf("%f", &juros);
    fflush(stdin);

    calculo = divida * (juros / 100);

    printf("O valor dos juros  e: R$ %2.2f", calculo);

    return 0;
}
