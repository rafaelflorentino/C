/*
 Objetivo: Faça um programa que converta o arquivo "LTPII.txt" em binário.
 Ler via teclado o nome do arquivo a ser criado. Depois de gerado, o arquivo binário
 deve ser lido e seu conteúdo mostrado na tela, com 10 valores em cada linha da tela.
 Entrada : Nome do arquivo.
 Saida : os 10 valores de cada linha na tela.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
int main()
{
    FILE *arqTexto, *arqBin;
    int i = 0, nr;
    char nomeArqBin[30];

    printf("Entre com o nome do arquivo Binario a ser gerado: ");
    gets(nomeArqBin);
    arqBin = fopen(nomeArqBin, "w+b");
    arqTexto = fopen("LTPII.txt", "r");

    if ((arqTexto == NULL) || (arqBin == NULL))
    {
        printf("\n\n\tErro ao abrir arquivo!!!");
        getche();
        return 0;
    }

    // lendo do arquivo Texto e gerando o arquivo Binário
    fscanf(arqTexto, "%d", &nr);
    while (!feof(arqTexto))
    {
        fwrite(&nr, sizeof(int), 1, arqBin);
        fscanf(arqTexto, "%d", &nr);
    }
    fclose(arqTexto);

    // lendo o arquivo Binário e escrevendo na tela
    rewind(arqBin);
    printf("\n\nConteudo gravado no arquivo Binario %s :\n\n", nomeArqBin);
    fread(&nr, sizeof(int), 1, arqBin);
    while (!feof(arqBin))
    {
        printf("%5d", nr);
        i++;
        if (i % 10 == 0)
        {
            printf("\n");
        }
        fread(&nr, sizeof(int), 1, arqBin);
    }
    fclose(arqBin);

    printf("\n\nPressione uma TECLA para TERMINAR o programa ... ");
    getche();
    return 0;
}
