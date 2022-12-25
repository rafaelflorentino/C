/*
 Objetivo : Escreva um programa em C que crie um arquivo, abra e prencha com números.
 Entrada : Nome do arquivo, números.
 Saida : Arquivo criado com números dentro.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
main(void)
{
    FILE *arquivo;
    FILE *arquivoEntrada;
    arquivo = fopen("teste.txt", "r");
    arquivoEntrada = fopen("teste.txt", "r+");

    int conteudo = 0;
    int i, j, num[5], num2 = 3000;

    if (arquivo == NULL)
    {
        printf("Nao foi possivel acessar o arquivo.");
    }
    else
    {
        printf("\nO arquivo foi acessado com sucesso!!! \n");
        printf("Digite quantos numeros deseja vai inserir: \n");
        scanf("%d", &j);
        for (i = 0; i < j; i++)
        {
            printf("\nDigite o %d numero:  \n",i+1);
            scanf("%d", &num[i]);
            fflush(stdin);
            fprintf(arquivoEntrada, "%d \n", num[i]);
        }
        fprintf(arquivoEntrada, "%d \n", num2);
        fclose(arquivoEntrada);

        printf("\n\n****** conteudo do arquivo *********");
        while (fscanf(arquivo, "%d", &conteudo) != EOF)
        {           
            printf("\n %d", conteudo);
        }
        fclose(arquivo);
        printf("\n");
        system("PAUSE");
    }    
}
