/* 
 Objetivo : Salário com desconto Inss, salario <600 desonto = 0; salario > 600 e < 1200 desconto= 2%; salario > 1200 e <2000 desconto = 2.5%; salario > 2000 desconto = 3%
 Entrada : Salário.
 Saida : Salário com desconto Inss.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    float salario, desconto1 = 0.0, desconto2 = 0.0, desconto3 = 0.0;
    printf("Digite o seu salario bruto: ");
    scanf("%f", &salario);
    fflush(stdin);

    if ((salario <= 600))
    {
        printf("Seu Salario reajustado e: %2.2f", salario);
    }
    if ((salario > 600) && (salario <= 1200))
    {
        desconto1 = (salario - (salario * 0.02));
        printf("Seu Salario reajustado e: %2.2f", desconto1);
    }
    if ((salario > 1200) && (salario <= 2000))
    {
        desconto2 = (salario - (salario * 0.025));
        printf("Seu Salario reajustado e: %2.2f", desconto2);
    }
    if ((salario > 2000))
    {
        desconto3 = (salario - (salario * 0.03)); 
        printf("Seu Salario reajustado e: %2.2f", desconto3);
    }
    
    return 0;
}
