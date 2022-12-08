/* 
 Objetivo : Armazenar 8 números e imprimir numeros multiplos de 5.
 Entrada : Números quaiquer.
 Saida : Lista numerada, multiplos de 5.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
main()
{
    int numero[8];
    int i;
    for (i = 0; i < 8; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &numero[i]);
        fflush(stdin);
    }
    printf("\nMultiplos de 5 \n");
    
    for (i = 0; i < 8; i++){
        if ((numero[i] % 5 == 0)){
            printf("\n%d) Numero: %d ", i, numero[i]);
        }
    }
}
