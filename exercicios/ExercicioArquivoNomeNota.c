/*
 Objetivo : Escreva um programa em C que crie um arquivo, leia o arquivo, insira mais dados, mostre os dados inseridos.
 Entrada : Nome do arquivo, nome, nota.
 Saida : Arquivo criado com Dados.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <conio.h>
int grava_arquivo(char nome_arq[])
/* cria e grava arquivo contendo um nome e uma nota */
{
    FILE *fpin;
    char nome[30];
    double nota, controle = 0;
    /* abre o arquivo */
    fpin = fopen(nome_arq, "w");
    /* le nomes e notas e grava no arquivo */
    printf("\nNome da pessoa: ");
    gets(nome);
    fflush(stdin);
    printf("\nNota desta pessoa: ");
    scanf("%lf", &nota);
    fflush(stdin);
    fprintf(fpin, "%s %4.1lf", nome, nota);
    while (controle >= 0)
    {       
        char nome2[30]; 
        printf("\nDigite um numero Positivo para continuar ou -1 para terminar: ");
        scanf("%lf", &controle);
        fflush(stdin);

        if(controle >=0){
            printf("\nNome da pessoa: ");
            gets(nome2);
            fflush(stdin);
            printf("\nNota desta pessoa: ");
            scanf("%lf", &nota);
            fflush(stdin);
            fprintf(fpin, "%s %4.1lf", nome2, nota);
        }
    }
    fclose(fpin);
    printf("\n");       
    system("pause");
    system("cls");
    return 0;
}
int le_mostra_arquivo(char nome_arq[])
/* le arquivo e mostra no vídeo */
{
    FILE *fp;
    char nomealuno[30];
    double notaaluno;
    /* abre arquivo para leitura */
    fp = fopen(nome_arq, "r");
    /* le e mostra no vídeo todas as linhas do arquivo */
    printf("\n\n****** conteudo do arquivo *********");
    while (fscanf(fp, "%s %lf", nomealuno, &notaaluno) != EOF)
        printf("\nnome: %s - nota: %5.3lf", nomealuno, notaaluno);
    fclose(fp);
    return 0;
}
int insere_mais(char nome_arquivo[])
{
    FILE *fp;
    char nome[30];
    double nota, controle = 0;
    /* abre o arquivo para inserir mais dados ao final do mesmo */
    fp = fopen(nome_arquivo, "a");
    /* le e insere mais elementos no arquivo */
    printf("\n\n****** insere mais elementos *********");
    printf("\nNome da pessoa: ");
    gets(nome);
    fflush(stdin);
    printf("\nNota desta pessoa: ");
    scanf("%lf", &nota);
    fflush(stdin);
    while (controle >= 0)
    {
        printf("\nDigite um numero Positivo para continuar ou -1 para terminar: ");
        scanf("%lf", &controle);
        fflush(stdin);
         if(controle >=0){            
            printf("\nNome da pessoa: ");
            gets(nome);
            fflush(stdin);
            printf("\nNota desta pessoa: ");
            scanf("%lf", &nota);
            fflush(stdin);
            fprintf(fp, "%s %4.1lf", nome, nota);
        }
    }
    fclose(fp);
    printf("\n");       
    system("pause");
    system("cls");
    return 0;
}
int main()
{
    char nome_arquivo[32];

    printf("\nEntre com o nome do arquivo: ");
    gets(nome_arquivo);
    grava_arquivo(nome_arquivo);
    le_mostra_arquivo(nome_arquivo);
    insere_mais(nome_arquivo);
    le_mostra_arquivo(nome_arquivo);
    getch();
    return 0;
}
