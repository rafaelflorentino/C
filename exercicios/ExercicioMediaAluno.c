/* 
 Objetivo : Calcular a média final de um aluno (de 0 a 5 R; 6 D; 7 C; 8 B; 9 A; 10 A ).
 Entrada : Três notas do aluno.
 Saida : Nome , média e classificação.
 Aluno : Rafael Florentino.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int nota1, nota2, nota3, media;
    char nome[20], clas;

    printf("Digite o seu nome: ");
    scanf("%s", &nome);
    fflush(stdin);

    printf("Digite a sua primeira nota: ");
    scanf("%i", &nota1);
    fflush(stdin);

    printf("Digite a sua segunda nota: ");
    scanf("%i", &nota2);
    fflush(stdin);

    printf("Digite a sua terceira nota: ");
    scanf("%i", &nota3);
    fflush(stdin);

    media = (nota1 + nota2 + nota3) / 3;
    switch (media)
    {
    case 0:
        printf("%s a sua media final e: %i sua classificacao e R ", nome, media);
        break;
    case 1:
        printf("%s a sua media final e: %i sua classificacao e R ", nome, media);
        break;
    case 2:
        printf("%s a sua media final e: %i sua classificacao e R ", nome, media);
        break;
    case 3:
        printf("%s a sua media final e: %i sua classificacao e R ", nome, media);
        break;
    case 4:
        printf("%s a sua media final e: %i sua classificacao e R ", nome, media);
        break;
    case 5:
        printf("%s a sua media final e: %i sua classificacao e R ", nome, media);
        break;
    case 6:
        printf("%s a sua media final e: %i sua classificacao e D ", nome, media);
        break;
    case 7:
        printf("%s a sua media final e: %i sua classificacao e C ", nome, media);
        break;
    case 8:
        printf("%s a sua media final e: %i sua classificacao e B ", nome, media);
        break;
    case 9:
        printf("%s a sua media final e: %i sua classificacao e A ", nome, media);
        break;
    case 10:
        printf("%s a sua media final e: %i sua classificacao e A ", nome, media);
        break;
    }
    getch();

    return 0;
}
