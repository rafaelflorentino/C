/* 
 Objetivo : Calcular e imprimir o tempo necessário para que a população do país A ultrapasse a população B.
 Entrada: População da cidade A e a Taxa de natalidade da cidade A, População da cidade B e a Taxa de natalidade da cidade B
 Saida : O tempo necessário em anos para que a população do país A ultrapasse a população B.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
main()
{
    int anos=0;
    float popA=0, popB=0, taxaA=0, taxaB=0;

    printf("Digite a populacao da Cidade A: ");
    scanf("%f", &popA);
    fflush(stdin);

    printf("Digite a taxa de Natalidade(ex 0.1) da Cidade A: ");
    scanf("%f", &taxaA);
    fflush(stdin);

    printf("Digite a populacao da Cidade B: ");
    scanf("%f", &popB);
    fflush(stdin);

    printf("Digite a taxa de Natalidade(ex 0.01) da Cidade B: ");
    scanf("%f", &taxaB);
    fflush(stdin);

    //popA = 5000000;
    //popB = 7000000;
    //taxaA = 3/100 = 0.03;
    //taxaB = 2/100 = 0.02;
    // A>B em 35 anos

    printf("\nAno: %d ", anos);
    printf("\nA populacao A: %2.2f ", popA);
    printf("\nA populacao B: %2.2f ", popB);
    printf("\n ");

    while (popA < popB)
    {
        popA = popA * (1 + taxaA);
        popB = popB * (1 + taxaB);
        anos = anos + 1;

        printf("\nAno: %d ", anos);
        printf("\nA populacao A: %2.2f ", popA);
        printf("\nA populacao B: %2.2f ", popB);
        printf("\n ");
    }
    printf("\nA populacao A vai ultrapassar a populacao B em: %d anos", anos);
}
