/*
 Objetivo : Escreva um programa em C que gere 20 inteiros entre 100 e 999 e calcule o MMC e o MDC.
 Entrada : Sem Entrada.
 Saida : Valores do MMC e do MDC.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int MMC(int A, int B)
{
    int Resul = A;
    while (Resul % B != 0)
        Resul = Resul + A;
    return (Resul);
}

void ProcMMC(int A, int B, int *Resultado)
{
    *Resultado = A;
    while (*Resultado % B != 0)
        *Resultado = *Resultado + A;
}

int MDC(int A, int B)
{
    int Resul;
    Resul = A * B / MMC(A, B);
    return (Resul);
}

void ProcMDC(int A, int B, int *Resultado)
{
    int Aux;
    ProcMMC(A, B, &Aux);
    *Resultado = A * B / Aux;
}

void Finalizacao()
{
    printf("\nDigite qualquer TECLA para TERMINAR o PROGRAMA .... ");
    getch();
}

int main()
{
    int Cont, A, B, Resul;
    system("color 6");
    srand(time(NULL));
    printf("\nLista dos 20 pares de inteiros entre 100 e 999 para MMC e MDC:\n\n");
    for (Cont = 1; Cont <= 20; Cont++)
    {
        A = rand() % 900 + 100;
        B = rand() % 900 + 100;
        printf("\n%2d) Par (%d,%d)", Cont, A, B);
        printf("    MMC(%d,%d) = %d \t ", A, B, MMC(A, B));
        printf("MDC(%d,%d) = %d\n", A, B, MDC(A, B));
        ProcMMC(A, B, &Resul);
        printf("\t             MMC(%d,%d) = %d \t ", A, B, Resul);
        ProcMDC(A, B, &Resul);
        printf("MDC(%d,%d) = %d\n\n", A, B, Resul);
    }
    Finalizacao();
}
