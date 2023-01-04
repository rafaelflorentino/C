/*
 Objetivo : Fazer um programa que receba o nome do arquivo, matricula e as 3 notas do aluno, e salve em um arquivo, mostrar tambem a média.
 Entrada : Nome arquivo, matricula e notas.
 Saida : Arquivo preenchido e as médias.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void grava_arquivo(char nome_arq[]);
int main()
{
    FILE *arquivo, *arquivo2;
    char nome[30], matricula[10], nomeArq[30], buf[1000];
    float nota1 = 0, nota2 = 0, nota3 = 0, media = 0, mediaTotal = 0;
    int quantidade, i;

    printf("\nDigite o nome do arquivo: ");
    gets(nomeArq);
    fflush(stdin);
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &quantidade);
    fflush(stdin);

    /* Abre o arquivo  */
    arquivo = fopen(nomeArq, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo  ");
        printf("\n\nPressione uma TECLA para TERMINAR ... ");
        getche();
        return 0;
    }
    /* Abre o arquivo2  */
    arquivo2 = fopen("a2", "w");
    if (arquivo2 == NULL)
    {
        printf("Erro ao abrir o arquivo  ");
        printf("\n\nPressione uma TECLA para TERMINAR ... ");
        getche();
        return 0;
    }
    /* Lê nomes e notas e grava no arquivo */
    for (i = 0; i < quantidade; i++)
    {
        printf("\nMatricula: ");
        scanf("%s", &matricula);
        fflush(stdin);
        printf("\nNota 1: ");
        scanf("%f", &nota1);
        fflush(stdin);
        printf("Nota 2: ");
        scanf("%f", &nota2);
        fflush(stdin);
        printf("Nota 3: ");
        scanf("%f", &nota3);
        fflush(stdin);
        media = media + ((nota1 + nota2 + nota3) / 3);
        mediaTotal+= media;
        printf("\nA media das notas do Aluno e: %2.2f \n", media);
        // Gravando os dados no arquivo 1.
        fprintf(arquivo, "%s %2.2f %2.2f %2.2f\n", matricula, nota1, nota2, nota3);
        // Gravando as médias no arquivo 2.
        fprintf(arquivo2, "%s %2.2f\n", matricula, media);
        // Limpando a média do proximo aluno.        
        media = 0;
    }
    fclose(arquivo);
    fclose(arquivo2);

    // Abrindo o  primeiro arquivo para leitura
    arquivo = fopen(nomeArq, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo  ");
        printf("\n\nPressione uma TECLA para TERMINAR ... ");
        getche();
        return 0;
    }

    printf("\nLendo o Arquivo 1\n");
    printf("\n\nMatricula Nota1 Nota2 Nota3\n\n");
    fgets(buf, 100, arquivo);
    while (!feof(arquivo))
    {
        printf("%s", buf);
        fflush(stdin);
        fgets(buf, 1000, arquivo);
    }

    // Abrindo o segundo arquivo para leitura
    arquivo2 = fopen("a2", "r");
    if (arquivo2 == NULL)
    {
        printf("Erro ao abrir o arquivo  ");
        printf("\n\nPressione uma TECLA para TERMINAR ... ");
        getche();
        return 0;
    }

    printf("\nLendo o Arquivo 2\n");
    printf("\nMatricula Media\n\n");
    fgets(buf, 100, arquivo2);
    while (!feof(arquivo2))
    {
        printf("%s", buf);
        fflush(stdin);
        fgets(buf, 1000, arquivo2);
    }
    printf("\nQuantidade alunos: %d", quantidade);
    printf("\nMedia Total: %2.2f\n\n", mediaTotal/quantidade);
    
    fclose(arquivo);
    fclose(arquivo2);
    return 0;
}
