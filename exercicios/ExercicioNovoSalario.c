/* 
 Objetivo : Calcular o novo salário dos funcionários, Diretoria (D) 5%, Gerência (G) 7%, Analista (A) 8%, Técnico (T) 9%, Outros(O) 4%.
 Entrada : Nome do funcionário, enquadramento funcional e salário atual.
 Saida : Salário reajustado.
 Aluno : Rafael Florentino.
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    float salario = 0, desconto1 = 0, desconto2 = 0, desconto3 = 0, desconto4 = 0, desconto5;
    char enquadramento, nome[20];
    printf("Digite o seu nome: ");
    scanf("%c", &nome);
    fflush(stdin);

    printf("Digite o seu salario atual: ");
    scanf("%f", &salario);
    fflush(stdin);

    printf("Digite o seu enquadramento funcional Diretoria (D), Gerencia (G), Analista (A), Tecnico (T), Outros(O): ");
    scanf("%c", &enquadramento);
    fflush(stdin);

    switch (enquadramento)
    {
    case 'D':
        desconto1 = salario + (salario * 0.05);
        printf("%s a seu salario reajustado e: %2.2f : ", nome, desconto1);
        break;
    case 'd':
        desconto1 = salario + (salario * 0.05);
        printf("%s a seu salario reajustado e: %2.2f : ", nome, desconto1);
        break;
    case 'G':
        desconto2 = salario + (salario * 0.07);
        printf("%s a seu salario reajustado e: %2.2f : ", nome, desconto2);
        break;
    case 'g':
        desconto2 = salario + (salario * 0.07);
        printf("%s a seu salario reajustado e: %2.2f : ", nome, desconto2);
        break;
    case 'A':
        desconto3 = salario + (salario * 0.08);
        printf("%s a seu salario reajustado e: %2.2f : ", nome, desconto3);
        break;
    case 'a':
        desconto3 = salario + (salario * 0.08);
        printf("%s a seu salario reajustado e: %2.2f : ", nome, desconto3);
        break;
    case 'T':
        desconto4 = salario + (salario * 0.09);
        printf("%s a seu salario reajustado e: %2.2f : ", nome, desconto4);
        break;
    case 't':
        desconto4 = salario + (salario * 0.09);
        printf("%s a seu salario reajustado e: %2.2f : ", nome, desconto4);
        break;
    case 'O':
        desconto5 = salario + (salario * 0.04);
        printf("%s a seu salario reajustado e: %2.2f : ", nome, desconto5);
        break;
    case 'o':
        desconto5 = salario + (salario * 0.04);
        printf("%s a seu salario reajustado e: %2.2f : ", nome, desconto5);
        break;
    }
    
    return 0;
}
