/*
 Objetivo : 
 Entrada : Valor1 e valor2.
 Saida : Valores trocados.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void duplicar_Inteiros(int *n1, int *n2);
void triplica_Float(float *v1, float *v2);
void trocar_Caracteres(char *x, char *y);

int main(void)
{
    int numero1, numero2;
    printf("\nDigite o Primeiro Numero: ");
    scanf("%d", &numero1);
    printf("\nDigite o Segundo Numero: ");
    scanf("%d", &numero2);
    printf("\n ");
    system("pause");
    system("cls");
    printf("\n----- Inteiros Recebidos ------");
    printf("\nPrimeiro Numero: %d\nSegundo Numero: %d\n", numero1, numero2);
    duplicar_Inteiros(&numero1, &numero2);
    printf("\n----- Inteiros Duplicados ------\nPrimeiro Numero: %d \nSegundo Numero: %d\n", numero1, numero2);
    printf("\n ");
    system("pause");
    system("cls");
   
    float valor1=5.5, valor2=1.2;
    printf("\n----- Floats Recebidos ------\nPrimeiro Numero: %2.2f \nSegundo Numero: %2.2f\n", valor1, valor2);
    triplica_Float(&valor1, &valor2);
    printf("\n----- Floats Triplicados ------\nPrimeiro Numero: %2.2f \nSegundo Numero: %2.2f\n", valor1, valor2);
    printf("\n ");
    system("pause");
    system("cls");

    char letra1='a',letra2='b';
    printf("\n----- Letras Recebidas ------\nPrimeira Letra: %c \nSegunda Letra: %c\n", letra1, letra2);
    trocar_Caracteres(&letra1,&letra2);
    printf("\n----- Letras Trocadas ------\nPrimeira Letra: %c \nSegunda Letra: %c\n", letra1, letra2);
    printf("\n ");
    system("pause");
    system("cls");

    // C não tem variáveis tipo Boolean b1=True;

    char palavra1[]="casa";
    char palavra2[]="bala";
    printf("\n----- Palavras Recebidas ------\nPrimeira Palavras: %s \nSegunda Palavras: %s\n", palavra1, palavra2);
    trocar_Strings(palavra1,palavra2);// só funciona em palavras do mesmo tamanho
    printf("\n----- Palavras Trocadas ------\nPrimeira Palavras: %s \nSegunda Palavras: %s\n", palavra1, palavra2);

    printf("\n ");
    system("pause");
    system("cls");
    return 0;
}
void trocar_Strings(char *p1[], char *p2[]){
    char *aux;
    aux=*p1;
    *p1=*p2;
    *p2=aux;
}

void trocar_Caracteres(char *x, char *y){
    char aux;
    aux=*x;
    *x=*y;
    *y=aux;
}

void duplicar_Inteiros(int *n1, int *n2)
{
    *n1 = *n1 * 2;
    *n2 = *n2 * 2;
    return;
}

void triplica_Float(float *v1, float *v2)
{
    *v1 = *v1 * 3;
    *v2 = *v2 * 3;
    return;
}
