/* 
 Objetivo : Avaliar se um empréstimo pode ou não ser concedito, valor maximo de empréstimo 30% do salário da pessoa.
 Entrada : Salário bruto e o valor do empréstimo.
 Saida : Conceder ou não o empréstimo.
 Aluno : Rafael Florentino.
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    float salario, emprestimo, calculo;

    printf("Digite o salario: ");
    scanf("%f", &salario);
    fflush(stdin);

    calculo = salario * 0.3;
    printf("Digite o valor do emprestimo: ");
    scanf("%f", &emprestimo);
    fflush(stdin);

    if( emprestimo <= calculo ){
        printf("Emprestimo concedido.");

    }else{
        printf("Emprestimo nao pode ser concedido.");    
    }
    getch(); 

    return 0;
}
