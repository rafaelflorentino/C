/* 
 Objetivo : Enviar vários números, quando o zero for digitado o algoritmo será finalizado. Mostre ao final a soma dos números positivos, a soma dos negativos e a soma total dos positivos e negativos.
 Entrada : Números.
 Saida : A soma dos números positivos ,a soma dos números negativos e a soma dos positivos com os negativos.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
main()
{
    int numero=0, contp=0, somap=0, contn=0, soman=0, soma=0;

    printf("Digite um numero ou zero para parar: ");
    scanf("%d", &numero);

    while (numero != 0)
    {
        if (numero > 0)
        {
            contp = contp + 1;
            somap = somap + numero;
        }
        if (numero < 0)
        {
            contn = contn + 1;
            soman = soman + numero;
        }
        printf("Digite um numero ou zero para parar: ");
        scanf("%d", &numero);
    }
    soma = somap + soman;
    printf("\nA soma dos numeros positivos e: %d \nA soma dos numeros negativos e: %d \nA soma dos dois e: %d ", somap, soman, soma);
}
