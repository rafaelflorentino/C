/* 
 Objetivo : Receber as notas de um aluno, e sair a média.
 Entrada : Nome, notas.
 Saida : Nome do aluno e média.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

float calculaMedia(float sum);

struct estrutura
{
    float nota[4];
    char nome[10][100];
} Aluno;

int main()
{
    int i, j, k;
    float media, soma, media2, media3, temp=0;

    printf("Digite o numero de alunos: ");
    scanf("%d", &j);
    fflush(stdin);
    printf("\n");

    for (i = 0, j; i < j; i++)
    {
        printf("Digite o seu nome: ");
        scanf("%c", &Aluno.nome[i]);
        fflush(stdin);
        printf("\n");
        soma = 0;

        for (k = 1; k < 5; k++)
        {
            printf("Digite a sua %d nota: ", k);
            scanf("%f", &Aluno.nota[k]);
            fflush(stdin);
            printf("\n");

            soma = soma + Aluno.nota[k];          
        }
        media = soma / 4;
        media2 = calculaMedia(soma);
        
        printf("%s A sua media e: %0.2f ", Aluno.nome[i], media2);
        printf("\n\n");    
        system("pause");
        system("cls");       
    }
    return 0;
}

float calculaMedia(float sum){
    return sum/4;
}
