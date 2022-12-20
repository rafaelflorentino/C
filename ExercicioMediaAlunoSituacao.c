/* 
 Objetivo  : Ler e calcular a média dos estudantes, pelas notas da prova teorica e da prova pratica e mostrar se o aluno esta aprovado(>=7) ou reprovado.
 Entrada : Notas.
 Saida : Média situação do aluno.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void apresentaSituacao(float resultado);
float calculaMedia(float notaT, float notaP);
int main()
{
    float notaT, notaP, resultado;

    printf("\nDigite a sua nota teorica: ");
    scanf("%f", &notaT);
    fflush(stdin);

    printf("\nDigite a sua nota pratica: ");
    scanf("%f", &notaP);
    fflush(stdin);

    resultado = calculaMedia(notaT, notaP);

    apresentaSituacao(resultado);
    printf("\n");
    return 0;
}
float calculaMedia(float notaT, float notaP)
{
    return (notaT + notaP) / 2;
}
void apresentaSituacao(float resultado)
{
    if (resultado >= 7)
    {
        printf("\nVoce foi Aprovado com media: %0.2f \n", resultado);
    }
    if (resultado < 7)
    {
        printf("\nVoce foi Reprovado com media: %0.2f \n", resultado);
    }
}
