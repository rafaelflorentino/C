/*
 Objetivo : Escreva um programa em C que crie um arquivo, abra e prencha com números.
 Entrada : Nome do arquivo, números.
 Saida : Arquivo criado com números dentro.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <conio.h>
int main()
{
    FILE *fp;
    char nome_arquivo[32];
    double a;
    /* le o nome do arquivo */
    printf("\nEntre com o nome do arquivo: ");
    gets(nome_arquivo);

    /* abre o arquivo para gravação */
    fp = fopen(nome_arquivo, "w");

    /* lê o primeiro número para começar */
    printf("\nEntre com um numero real: ");
    scanf("%lf", &a);
    while (a != -999)
    {
        fprintf(fp, "%10.4lf", a);
        /* lê o próximo número */
        printf("\nEntre com um numero real ou com -999 para terminar: ");
        scanf("%lf", &a);
    }
    fclose(fp);

    /* abre o mesmo arquivo para leitura */
    fp = fopen(nome_arquivo, "r");
    printf("\n***** Conteudo do arquivo criado ******\n");

    /* lê e mostra todos o conteúdo do arquivo */
    while (fscanf(fp, "%lf", &a) != EOF) printf("%10.4lf * ", a);
   
    fclose(fp); /* este fclose não é necessário */
    return 0;
}
