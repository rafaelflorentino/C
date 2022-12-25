/* 
Objetivo : Calcular a media de 5 números.
Entrada : 5 números quaisquer.
Saida : A média dos 5 números.
Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
main()
{
    int i;
    float soma = 0.0, numero = 0.0, media = 0.0;

    for (soma = 0, i = 0; i < 5; i = i + 1)
    {
        printf("Digite o numero %d ", i+1);
        scanf("%f", &numero);
        fflush(stdin);
        soma = soma + numero;        
    }

    media = soma/i;   
    printf("A soma dos 5 numeros e: %2.2f", soma);
    printf("\nA media dos 5 numeros e: %2.2f", media);    
}
