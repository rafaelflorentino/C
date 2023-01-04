/*
 Objetivo : Fazer um programa que receba o nome do arquivo, e salve nele matricula idade, mensalidade, depois leia e imprima na tela o arquivo.
 Entrada : Nome arquivo, matricula e idade, mesalidade.
 Saida : Arquivo, e os dados do arquivo na tela.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
int main()
{
    FILE *fp;
    char nome_arquivo[32], matricula[10], buf[1000];
    double a, mensalidade;
    int idade, i;

    printf("\nEntre com o nome do arquivo: ");
    gets(nome_arquivo);
    fp = fopen(nome_arquivo, "w");

    for (i = 0; i < 3; i++)
    {
        printf("\n\nAluno %d", i+1);
        printf("\nMatricula: ");
        scanf("%s", &matricula);
        printf("Idade: ");
        scanf("%d", &idade);
        printf("Mensalidade: ");
        scanf("%lf", &mensalidade);
        fprintf(fp, "%4s     %4d     %3.2f\n", matricula, idade, mensalidade);
    }
    fclose(fp);

    fp = fopen(nome_arquivo, "r");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.  ");
        printf("\n\nPressione uma TECLA para TERMINAR ... ");
        getche();
        return 0;
    }

    printf("\n\nLendo Dados do Arquivo\n");
    printf("\n\nMatricula Idade Mensalidade \n");
    fgets(buf, 100, fp);
    while (!feof(fp))
    {
        printf("%s", buf);
        fflush(stdin);
        fgets(buf, 1000, fp);
    }
    fclose(fp);
    getch(stdin);
    return 0;
}
