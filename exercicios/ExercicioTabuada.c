/* 
 Objetivo : Imprimir a tabuada que deve ser escolhida pelo usuário.
 Entrada : Número da Tabuada.
 Saida : A tabuada escolhida.
 Aluno : Rafael Florentino.
*/

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
main()
{
    int i = 0, j = 0;

    printf("Digite o numero de qual tabuada voce quer: ");
    scanf("%d", &i);
    fflush(stdin);

    for (i; i;)
    {
        for (j = 0; j <= 10; j = j + 1)
            printf("%2d * %2d = %2d\n", i, j, i * j);
       getchar();
    }
}
