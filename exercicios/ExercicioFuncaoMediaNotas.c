/* 
 Objetivo : Desenvolva um programa que leia as duas notas de 20 alunos e calcule as 3 médias, e a media final para cada um deles.
 Entrada : 2 notas.
 Saida : 3 medias e a média final.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <math.h>

float media1(float nota1, float nota2);
float media2(float nota1, float nota2);
float media3(float nota1, float nota2);

int main()
{
    float nota1, nota2, resultado1, resultado2, resultado3, soma, resultadoFinal;
    int i;

    for (i = 0; i < 20; i++)
    {
        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);
        fflush(stdin);
        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);
        fflush(stdin);

        resultado1 = media1(nota1, nota2);
        resultado2 = media2(nota1, nota2);
        resultado3 = media3(nota1, nota2);
        soma = resultado1 + resultado2 + resultado3;
        resultadoFinal = soma/3;

        printf("\n");
        printf("Primeira media: %0.2f", resultado1);
        printf("\n");
        printf("Segunda media: %0.2f", resultado2);
        printf("\n");
        printf("Terceira media: %0.2f", resultado3);
        printf("\n");
        printf("Resultado Final: %0.2f", resultadoFinal);
        printf("\n\n");
        system("pause");
        system("cls");
    }
    return 0;
}

float media1(float nota1, float nota2)
{
    return (nota1 + nota2) / 2;
}

float media2(float nota1, float nota2)
{
    return ((nota1 * 4) + (nota2 * 6)) / (4 + 6);
}

float media3(float nota1, float nota2)
{
    return ((nota1 * 3) + (nota2 * 7)) / (3 + 7);
}
