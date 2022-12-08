/* 
 Objetivo : Calcular o fatorial.
 Entrada : Número qualquer.
 Saida : Fatorial
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int numero;
    printf("Entre com o valor a fatorar: ");
    scanf("%d", &numero);
    fflush(stdin);

    fat(numero);    
    return 0;
}

void fat(int n)
{
    int i;
    int f = 1;
    for (i = 1; i <= n; i++)
    {
        f = f * i;
        printf("\n %d\n", f);
    }
    printf("\nO fatorial de %d corresponde a %d\n", n, f);
}
