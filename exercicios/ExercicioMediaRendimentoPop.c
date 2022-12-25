/*
 Objetivo : Média dos rendimentos da população e a média do número de filhos.
 Entrada : Rendimento da populacao, numero de filhos.
 Saida : Média dos rendimentos da população e a média do número de filhos.
 Aluno : Rafael Florentino.
*/ 
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
main()
{
    int intrevistados=0, j=0, filhos=0, somaf=0;
    float rendimento=0, mediaf=0, mediar=0, somar=0;

    printf("Digite o numero de pessoas entrevistadas: ");
    scanf("%d", &intrevistados);

    for (j = 0; j < intrevistados; j = j + 1)
    {
        printf("Digite o rendimento familiar: ");
        scanf("%f", &rendimento);
        printf("Digite o numero de filhos: ");
        scanf("%d", &filhos);

        somar = somar + rendimento;
        somaf = somaf + filhos;
    }
    mediaf = somaf/intrevistados;
    mediar = somar/intrevistados;

    printf("\nMedia dos rendimentos da populacao e: %2.2f \nA media do numero de filhos e: %2.2f", mediar, mediaf);
}
