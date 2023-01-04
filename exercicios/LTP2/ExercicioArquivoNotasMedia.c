/*
 Objetivo : Fazer um programa que receba o nome de 2 arquivos para as 3 notas e outro para as médias, salvar dados no arquivo.
 Entrada: Nome dos arquivos.
 Saida : Arquivo preenchido com os dados.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    char nome_arquivo_notas[32], nome_arquivo_medias[32], matricula[12], linha[100];
    int i, quantidade;
    float media, nota1, nota2, nota3;
    /* Lê o nome dos arquivos */
    printf("\nEntre com o nome do arquivo para notas: ");
    gets(nome_arquivo_notas);

    printf("\nEntre com o nome do arquivo para medias: ");
    gets(nome_arquivo_medias);

    /* Abre os arquivos para gravação */
    FILE *notas, *medias;
    notas = fopen(nome_arquivo_notas, "wb");
    medias = fopen(nome_arquivo_medias, "wb");

    /* Captura de dados e escrita no arquivo */
    printf("\nDigite a quantidade de alunos: ");
    scanf("%d", &quantidade);
    fflush(stdin);

    for (i = 0; i < quantidade; i++)
    {
        printf("\nDigite o numero da matricula: ");
        gets(matricula);
        fflush(stdin);
        printf("\nDigite a primeira nota: ");
        scanf("%f", &nota1);
        fflush(stdin);
        printf("\nDigite a segunda nota: ");
        scanf("%f", &nota2);
        fflush(stdin);
        printf("\nDigite a terceira nota: ");
        scanf("%f", &nota3);
        fflush(stdin);

        fprintf(notas, "%12s  %f  %f  %f\n", matricula, nota1, nota2, nota3);
        media = (nota1 + nota2 + nota3) / 3;
        fprintf(medias, "%s  %f\n", matricula, media);
    }
    /* Fechando os primeiros arquivos (escrita) */
    fclose(notas);
    fclose(medias);

    /* Abrindo o arquivo em modo de leitura  */
    notas = fopen(nome_arquivo_notas, "rb");
    medias = fopen(nome_arquivo_medias, "rb");

    printf("\n\n***** Conteudo do arquivo de NOTAS criado ******\n\n");
    while (fscanf(notas, "%s %f %f %f", matricula, &nota1, &nota2, &nota3) != EOF)
        printf("Matricula:%12s\nNotas: %4.1f  %4.1f  %4.1f\n\n", matricula, nota1, nota2, nota3);
    fclose(notas);

    printf("\n\n***** Conteudo do arquivo de MEDIAS criado ******\n\n");
    while (fscanf(medias, "%s %f", matricula, &media) != EOF)
        printf("Matricula:%12s\nMedia: %4.3f\n\n", matricula, media);
    fclose(medias);

    getch();
    return 0;
}
