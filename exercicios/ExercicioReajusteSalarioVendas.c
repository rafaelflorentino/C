/* 
 Objetivo : Reajuste salarial de acordo com a quantidade de peças vendidas.
 Entrada : Número de peças.
 Saida : Salário reajustado.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <math.h>

float reajuste1(int peca);
float reajuste2(int peca);

int main()
{
    float calculo1, calculo2;
    int i, j, peca;
    printf("\nDigite a quantidade de funcionarios: ");
    scanf("%d", &j);
    for (i = 0, j; i < j; i++)
    {
        printf("\nFuncionario %d", i+1);
        printf("\nDigite a quantidade de pecas vendidas: ");
        scanf("%i", &peca);
        fflush(stdin);

        if (peca <= 50)
        {
            printf("\nsem reajuste seu salario e R$2500.");
            printf("\n");
        }
        if ((peca > 50) && (peca <= 80))
        {
            calculo1 = reajuste1(peca);
            printf("\nSeu salario reajustado e: %f", calculo1);
            printf("\n");
        }
        if (peca > 80)
        {
            calculo2 = reajuste2(peca);
            printf("\nSeu salario reajustado e: %f", calculo2);
            printf("\n");
        }
        printf("\n");    
        system("pause");
        system("cls");
    }
    printf("\n");
    return 0;
}
float reajuste1(int peca)
{
    return (((peca - 50) * 0.50) + 2500);
}
float reajuste2(int peca)
{
    return (((peca - 80) * 0.75) + 2500);
}
