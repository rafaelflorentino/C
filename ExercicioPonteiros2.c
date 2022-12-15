/*
 Objetivo: Implemente um programa em C que mostre os endereços, valores, das variaveis e ponteiros.
 Entrada : Sem entrada.
 Saida : Valores das variaveis, dos Ponteiros e endereços das variaveis.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, *px = NULL, *py = NULL;
    x = 2;
    y = 3;

    //Valor de X e Y
    printf("\nValor de X: %d; Valor de Y: %d ", x, y);
    printf("\n");

    printf("\nEndereco de X: %d; Endereco de Y: %d ", &x, &y);
    printf("\n");

    //Atribuir para os ponteiros px e py os endereços de x e y respectivamente.
    //Mostrar na tela os endereços apontados por x e y.
    py = &y;
    px = &x;
    printf("\nValor de PX: %d; Valor de PY: %d ", px, py);
    printf("\n");


    //Mostrar na tela os valores apontados por PX e PY.
    printf("\nValor apontado pelo endereco dentro PX: %d; Valor apontado pelo endereco dentro PY: %d ",*px,*py);
    printf("\n");

   //Mostrar na tela os endereços de PX e PY.
    printf("\nEndereco de PX: %d; E endereco de PY: %d ",&px,&py);
    printf("\n\n");

    return 0;
}
