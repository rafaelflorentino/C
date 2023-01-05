/*
 Objetivo : Fazer um programa que informe quantos divisores o número possui, gerar do número 1 ao 200.
 Entrada : Sem entrada.
 Saida : Números de 1 a 200, e sua quantidade de divisores.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>

int QuantDivisores(int N);
void ProcQuantDiv(int N, int *Qtd);

int main()
{
    int N, i, Qtd;

    printf("              Com QuantDivisores              Com ProcQuanDiv\n\n");
    for (i = 0; i < 200; i++)
    {
        ProcQuantDiv(i + 1, &Qtd);
        printf("Nr %3d ---> Quantidade divisores: %2d  --- Quantidade divisores: %2d\n", i + 1, QuantDivisores(i + 1), Qtd);
    }
    printf("\n\nAperte qualquer tecla para sair...");
    getch();
}

int QuantDivisores(int N)
{
    int i, aux = 0;

    for (i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            aux++;
        }
    }
    return aux;
}

void ProcQuantDiv(int N, int *Qtd)
{
    int i, aux = 0;

    for (i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            aux++;
        }
    }
    *Qtd = aux;
}
