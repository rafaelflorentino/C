/*
Objetivo : Calcular e mostrar a média aritmética entre as 3 notas.
Entrada : 3 Notas.
Saida : Média.
Autor : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num1, num2, num3;
    int media;

    printf("Digite a primeira nota: ");
    scanf("%d", &num1);
    fflush(stdin);

    printf("Digite a segunda nota: ");
    scanf("%d", &num2);
    fflush(stdin);

    printf("Digite a terceira nota: ");
    scanf("%d", &num3);
    fflush(stdin);

    media = (num1 + num2 + num3) / 3;

    printf("A media das tres notas e: %d", media);

    return 0;
}
