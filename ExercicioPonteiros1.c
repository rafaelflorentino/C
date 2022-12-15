/*
 Objetivo: Implemente um programa em C para colocar px apontando para x e py apontando para y, : int x=2, *px, *py, y=3; 
 Entrada : Sem entrada.
 Saida : Valores das variáveis, Ponteiros e endereços das variaveis.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x, y, *px = NULL, *py = NULL;
    x = 2;
    y = 3;
    px = &x;
    py = &y;

    printf("\nValor de X e Y\n");
    printf("X:%d Y:%d\n", x, y);
    printf("\nEndereco de X e Y Salvo dentro de PX e de PY\n");
    printf("PX:%d PY:%d\n", px, py);
    printf("\nValores apontados pelos enderecos de X e Y salvos dentro de PX e PY\n");
    printf("*PX:%d *PY:%d\n", *px, *py);
    printf("\nEndereco de PX e endereco de PY\n");
    printf("&PX:%d  &PY%d\n", &px, &py);
    printf("\nEdereco de X e endereco de Y\n");
    printf("&X:%d  &Y%d\n", &x, &y);
    printf("\n");

    // Caso seja feito px = py, quais são as saídas
    px = py;
    printf("\npx = py\n");
    printf("px = %d\n", px);
    printf("\n");
    printf("X:%d &X:%d PX:%d *PX:%d Y:%d &Y:%d PY:%d *PY:%d", x, &x, px, *px, y, &y, py, *py);

    return 0;
}
