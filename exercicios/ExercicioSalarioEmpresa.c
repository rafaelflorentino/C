/* 
 Objetivo : Reajuste salarial de uma empresa que possui 1.000 funcionários.
 Entrada : Salário dos funcionários.
 Saida : Salário reajustado.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
main()
{
    int i;
    float media = 0, salario = 0, reajuste = 0;

    for (reajuste = 0, i = 1; i <= 1000; i = i + 1)
    {
        printf("\nDigite o seu salario: ");
        scanf("%f", &salario);
        fflush(stdin);

        if (salario <= 2000)
        {
            reajuste = salario + (salario * 0.1);
            printf("Seu salario reajustado e: %2.2f", reajuste);
        }
        if (salario > 2000 && salario <= 5000)
        {
            reajuste = salario + (salario * 0.07);
            printf("Seu salario reajustado e: %2.2f", reajuste);
        }
        if (salario > 5000)
        {
            reajuste = salario + (salario * 0.03);
            printf("Seu salario reajustado e: %2.2f", reajuste);
        }
         printf("\n");
    }
   
}
