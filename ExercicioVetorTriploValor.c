/* 
 Objetivo : Ler um vetor de 10 elementos e obter outro vetor, cujos componentes são o triplo dos respectivos componentes do primeiro vetor.
 Entrada : Números.
 Saida : O triplo dos valores.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int i, quantidade;
    float numero[100], cont[100];

    for (i = 1; i <= 10; i++)
    {
        printf("Informe o %d numero: \n", i);
        scanf("%f", &numero[i]);
        fflush(stdin);
        cont[i] = numero[i] * 3;
    }
    
    for (i = 1; i <= 10; i++)
    {
         printf("%d) %0.2f  triplo: %0.2f \n", i, numero[i], cont[i]);
    }
    
    system("pause");
    return (0);
}
