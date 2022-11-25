/* 
Objetivo : Ler a idade de uma pessoa em anos e mostre sua idade em dias e em meses.
Entrada : Idade em anos.
Saida : Idade em dias e meses.
Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int idade, mes, dias;

    printf("Digite a suaidade: ");
    scanf("%d", &idade);
    fflush(stdin);

    mes = idade * 12;
    dias = idade * 360;

    printf("A sua idade em meses e: %d; A sua idade em dias e: %d.", mes, dias);

    return 0;
}
