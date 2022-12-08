/* 
 Objetivo : Armazenar 15 números e imprimir uma listagem numerada contendo uma das mensagens: par ou ímpar.
 Entrada : Números.
 Saida : Lista numerada, impar par.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
main()
{
    int numero[15];
    int i;
    // Entrada de dados
    for (i = 0; i < 15; i++){
        printf("Digite um numero: ");
        scanf("%d", &numero[i]);
        fflush(stdin);
    }
    // Saida
    for (i = 0; i < 15; i++){
        if ((numero[i] % 2 == 0)){
            printf("%d) Numero: %d (par) \n", i+1, numero[i]);
        }
        else{
            printf("%d) Numero: %d (impar) \n", i+1, numero[i]);
        }
    }
}
