/*
Objetivo : Calcular e imprimir salario reajustado com comissao as vendas de um funcionario.
Entrada : Nome, salario, total de vendas.
Saida : Reajuste.
Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float salario, vendas, reajuste;
    char nome[20];

    printf("Digite o nome do funcionario: ");
    scanf("%s", &nome);
    fflush(stdin);

    printf("Digite o salario: ");
    scanf("%f", &salario);
    fflush(stdin);

    printf("Digite o valor das vendas: ");
    scanf("%f", &vendas);
    fflush(stdin);

    reajuste =  salario + (vendas * 0.15);

    printf("%s, o seu salario reajustado e: R$ %2.2f", nome, reajuste);

    return 0;
}
