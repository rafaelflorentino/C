/*
 Objetivo : Escreva um programa em C que receba do usuario o raio da esfera e calcule o volume da esfera em cm cúbicos,
 Entrada : Raio da esfera.
 Saida : Volume da esfera.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void pocedimento(float raio, float *aux);
float funcao(float raio);
float CalcVolume(float raio);

int main()
{
    float raio = 0, volume, aux;
    printf("\nDigite o Raio da Esfera: ");
    scanf("%f", &raio);
    fflush(stdin);

    printf("\nVolume da Esfera e: %2.2f cm Cubicos\n", CalcVolume(raio));

    printf("\nFuncao = O Raio da Esfera e: %2.2f cm3", funcao(raio));

    pocedimento(raio, &aux);
    printf("\n\nProcedimento = O Raio da Esfera e: %2.2fcm3\n\n", aux);

    return 0;
}

float CalcVolume(float raio)
{
    float volume = 0;
    float pi = 3.14;
    volume = (4*pi*pow(raio, 3))/3;
    return volume;
}

float funcao(float raio)
{
    float volume = 0;
    volume = (4.0/3.0)*(3.14)*(pow(raio, 3));
    return volume;
}

void pocedimento(float raio, float *aux)
{
    *aux = (4.0/3.0)*(3.14)*(pow(raio, 3));
}




