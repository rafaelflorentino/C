/*
 Objetivo : Escreva um programa em C que crie um arquivo, leia o arquivo, insira mais dados, mostre os dados inseridos.
 Entrada : Nome do arquivo, nome, nota.
 Saida : Arquivo criado com Dados.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <conio.h>
int grava_arquivo(char nome_arq[])
{
    FILE *fpin;
    char nome[30];
    double nota, controle = 0;
    fpin = fopen(nome_arq, "w"); /* abre o arquivo */

    printf("\n          *** Novo Cadastro *** \n\n");
    printf("\nNome da pessoa: ");
    gets(nome);
    fflush(stdin);
    printf("\nNota desta pessoa: ");
    scanf("%lf", &nota);
    fflush(stdin);
    fprintf(fpin, "%s %4.1lf \n", nome, nota); /* le nomes e notas e grava no arquivo */
    printf("\n");
    system("cls");

    while (controle >= 0)
    {
        printf("\nDigite um numero Positivo para continuar ou -1 para terminar: ");
        scanf("%lf", &controle);
        fflush(stdin);

        if (controle >= 0)
        {
            printf("\n          *** Novo Cadastro *** \n");
            printf("\nNome da pessoa: ");
            gets(nome);
            fflush(stdin);
            printf("\nNota desta pessoa: ");
            scanf("%lf", &nota);
            fflush(stdin);
            fprintf(fpin, "%s %4.1lf \n", nome, nota);
            printf("\n");
            system("cls");
        }
    }
    fclose(fpin);
    printf("\n");
    system("pause");
    system("cls");
    return 0;
}
int le_mostra_arquivo(char nome_arq[])
{
    FILE *fpin;
    char nomealuno[30];
    double notaaluno;

    fpin = fopen(nome_arq, "r"); /* abre arquivo para leitura */
    
    printf("\n\n****** Conteudo do Arquivo *********\n");
    while (fscanf(fpin, "%s %lf", nomealuno, &notaaluno) != EOF) /* le todas as linhas do arquivo */
    {
        printf("\nnome: %s - nota: %5.3lf", nomealuno, notaaluno); /* Mostra todas as linhas do arquivo */
    }
    fflush(stdin);
    fclose(fpin);
    return 0;
}

int insere_mais(char nome_arquivo[])
{
    FILE *fp;
    char nome[30];
    double nota, controle = 0;
    fp = fopen(nome_arquivo, "a"); /* abre o arquivo para inserir mais dados ao final do mesmo */

    printf("\n\n     ****** Insere mais Elementos *********\n");
    printf("\n          *** Novo Cadastro *** ");
    printf("\nNome da pessoa: ");
    gets(nome);
    fflush(stdin);
    printf("\nNota desta pessoa: ");
    scanf("%lf", &nota);
    fflush(stdin);
    fprintf(fp, "%s %4.1lf \n", nome, nota); /* le e insere mais elementos no arquivo */
    printf("\n");
    system("cls");
    while (controle >= 0)
    {
        printf("\nDigite um numero Positivo para continuar ou -1 para terminar: ");
        scanf("%lf", &controle);
        fflush(stdin);
        if (controle >= 0)
        {
            printf("\n          *** Novo Cadastro *** \n\n");
            printf("\nNome da pessoa: ");
            gets(nome);
            fflush(stdin);
            printf("\nNota desta pessoa: ");
            scanf("%lf", &nota);
            fflush(stdin);
            fprintf(fp, "%s %4.1lf \n", nome, nota);
            printf("\n");
            system("cls");
        }
    }
    fclose(fp);
    system("cls");
    return 0;
}
int main()
{
    char nome_arquivo[32];

    printf("\n          *** Criando Arquivo *** \n");
    printf("\nEntre com o nome do arquivo: ");
    gets(nome_arquivo);
    printf("\n");
    system("cls");

    grava_arquivo(nome_arquivo);
    le_mostra_arquivo(nome_arquivo);
    insere_mais(nome_arquivo);
    le_mostra_arquivo(nome_arquivo);
    printf("\n");
    printf("\nFinal do Programa.\n\n");
    return 0;
}
