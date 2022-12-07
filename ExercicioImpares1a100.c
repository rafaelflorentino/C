/* 
 Objetivo : Imprimir todos os números ímpares no intervalo de 1 a 100 e a soma deles.
 Entrada : Sem entrada.
 Saida : Imprimir todos os números impare de 1 ate 100 e a soma deles.
 Aluno : Rafael Florentino.
 */

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
main()
{
    int i, soma;
    for (i = 1, soma = 0; i < 100; i = i + 2, soma = soma + i)
    {
        printf(" %d", i);
    }
    printf("\nSoma:  %d", soma);
    getch();
}
