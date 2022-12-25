/* 
 Objetivo : Escreva um programa em C que crie um arquivo vazio.
 Entrada : Nome do arquivo.
 Saida : Arquivo criado ou mensagem de erro.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char nome[100];
    
    printf("Digite um nome para o arquivo(exemplo: teste.txt): \n");
    scanf("%s", &nome);

    FILE *p_arquivo;
    if ((p_arquivo = fopen(nome,"wt")) == NULL)
    {
        printf("Arquivo nao pode ser aberto.");
    }
    else
    {
        printf("Arquivo criado com sucesso.");
        fclose(p_arquivo);
    }   
}
