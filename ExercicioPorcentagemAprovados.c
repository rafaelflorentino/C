/* 
 Objetivo : Média.
 Entrada : 3 Notas.
 Saida : Média de cada aluno, porcentagem de aprovados e reprovados.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <math.h>

float media1(float nota1, float nota2, float nota3);
float porcentagemAprovados(float resultado, int cont1);
float porcentagemReprovados(float resultado, int cont2);

int main()
{
    float nota1 = 0, nota2 = 0, nota3 = 0, resultado = 0, aprovado = 0, reprovado = 0, resultadoAP = 0, resultadoRP= 0;
    int i = 0, j = 0, cont1 = 0, cont2 = 0;
    printf("\nDigite a quantidade de alunos: ");
    scanf("%d", &j);

    for (i = 0, j; i < j; i++)
    {
        printf("\n\nAluno %d", i+1);
        printf("\nDigite a primeira nota: ");
        scanf("%f", &nota1);
        fflush(stdin);
        printf("\nDigite a segunda nota: ");
        scanf("%f", &nota2);
        fflush(stdin);
        printf("\nDigite a terceira nota: ");
        scanf("%f", &nota3);
        fflush(stdin);
        resultado = media1(nota1, nota2, nota3);
        if (resultado >= 7)
        {
            resultadoAP = resultadoAP + resultado;
            cont1 = cont1 + 1;
        }
        if (resultado < 7)
        {
            resultadoRP = resultadoRP + resultado;
            cont2 = cont2 + 1;
        }
        aprovado = porcentagemAprovados(resultadoAP, cont1);
        reprovado = porcentagemReprovados(resultadoRP, cont2);

        printf("\nMedia do aluno: %f", resultado);
        printf("\n");
    }
    printf("\n");    
    system("pause");
    system("cls");
    printf("\nA media dos alunos aprovados e : %f", aprovado);
    printf("\n");
    printf("\nA media dos alunos reprovados e : %f", reprovado);
    printf("\n\n");
    return 0;
}
float media1(float nota1, float nota2, float nota3)
{
    return (nota1 + nota2 + nota3) / 3;
}
float porcentagemAprovados(float resultadoAP, int cont1)
{
    return resultadoAP / cont1;
}
float porcentagemReprovados(float resultadoRP, int cont2)
{
    return resultadoRP / cont2;
}
