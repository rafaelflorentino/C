/*
 Objetivo : Escreva um programa em C que crie um arquivo vazio.
 Entrada : Nome do arquivo.
 Saida : Arquivo criado ou mensagem de erro.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    char nome_arquivo[24];
    char extensao[5] = ".txt";

    printf("Nome do arquivo: ");
    gets(nome_arquivo);
    strcat(nome_arquivo, extensao);

    fp = fopen(nome_arquivo, "a+");

    if (fp == NULL)
    {
        printf("\nNao foi possivel localizar o arquivo: %s", nome_arquivo);
        exit(1);
    }
    fclose(fp);
    return 0;
}
