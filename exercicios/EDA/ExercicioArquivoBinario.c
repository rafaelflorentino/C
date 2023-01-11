/*
 Objetivo: Aquivo Binário.
 Entrada : Nome do arquivo.
 Saida   : Arquivo Binário, imprimir na tela elementos do arquivo.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h> 
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    typedef struct
    {
        char uf[3];
        int codufmun;
        char NomeMunicipio[60];
        int populacao;
    } DadosMunicipio;
    DadosMunicipio Municipio;

    FILE *arqTexto;
    FILE *arqBinario;
    char nomeBin[40], nomeTex[40] = "tabelamunicipiosParcial.csv", buf[1000];
    /*unsigned char */ int c, i = -1;
    /*printf("Digite o nome/caminho do arquivo TEXTO a ser convertido: ");
     gets(nomeTex); */
    arqTexto = fopen(nomeTex, "r");
    if (arqTexto == NULL)
    {
        printf("Erro ao abrir o arquivo %s !", nomeTex);
        printf("\n\nPressione uma TECLA para TERMINAR ... ");
        getche();
        return 0;
    }
    printf("Usando fgetc - Conteudo do arquivo %s :\n\n", nomeTex);
    while ((c = fgetc(arqTexto)) != EOF)
        printf("%c", c);
    rewind(arqTexto);
    printf("\nUsando fgets - Conteudo do arquivo %s :\n", nomeTex);
    while (fgets(buf, 1000, arqTexto) != NULL)
        printf("%s", buf);
    fclose(arqTexto);
    arqTexto = fopen(nomeTex, "r");
    printf("\nNovamente usando fgets - Conteudo do arquivo %s :\n", nomeTex);
    fgets(buf, 1000, arqTexto);
    while (!feof(arqTexto))
    {
        printf("%s", buf);
        fgets(buf, 1000, arqTexto);
    }
    rewind(arqTexto);

    printf("\n\nDigite o nome a ser dado para o arquivo Binario: ");
    gets(nomeBin);
    arqBinario = fopen(nomeBin, "w+b");

    /*LENDO O ARQUIVO TEXTO, ARMAZENANDO NAS RESPECTIVAS VARIÀVEIS e gravando o Arquivo Binário*/
    fgets(buf, 1000, arqTexto); /* leitura da 1 linha do arquivo Texto - cabeÁalho */
    printf("\n\tConteudo do arquivo TEXTO csv: \n\n");
    printf("%4s %13s %10s %35s", "UF", "COD.MUNIC.", "MUNICIPIO", "POPULACAO\n"); /*cabeçalho da listagem*/
    printf("__________________________________________________________________________\n\n");
    
    fgets(buf, 1000, arqTexto); /* leitura da 2 linha do arquivo Texto */
    strcpy(Municipio.uf, strtok(buf, ";"));
    Municipio.codufmun = atoi(strtok(NULL, ";"));
    strcpy(Municipio.NomeMunicipio, strtok(NULL, ";"));
    Municipio.populacao = atoi(strtok(NULL, ";"));
    /*do
    {
        i++;
        printf("%c   %d\n", Municipio.uf[i], Municipio.uf[i]);
    } while (Municipio.uf[i] != '\0');
    i = -1;
    do
    {
        i++;
        printf("%c   %d\n", Municipio.NomeMunicipio[i], Municipio.NomeMunicipio[i]);
    } while (Municipio.NomeMunicipio[i] != '\0');*/
    printf("\n\n%4s %10d %29s %15d\n\n", Municipio.uf, Municipio.codufmun, Municipio.NomeMunicipio, Municipio.populacao);
    fwrite(&Municipio, sizeof(Municipio), 1, arqBinario);
    fgets(buf, 1000, arqTexto);
    while (!feof(arqTexto))
    {
        strcpy(Municipio.uf, strtok(buf, ";"));
        Municipio.codufmun = atoi(strtok(NULL, ";"));
        strcpy(Municipio.NomeMunicipio, strtok(NULL, ";"));
        Municipio.populacao = atoi(strtok(NULL, ";"));
        printf("%4s %10d %29s %15d\n\n", Municipio.uf, Municipio.codufmun, Municipio.NomeMunicipio, Municipio.populacao);
        fwrite(&Municipio, sizeof(Municipio), 1, arqBinario);
        fgets(buf, 1000, arqTexto);
    }
    printf("__________________________________________________________________________\n\n");
    printf("\n\tConteudo do arquivo BINARIO gerado : \n\n");
    rewind(arqBinario);
    while (!feof(arqBinario))
    {
        fread(&Municipio, sizeof(Municipio), 1, arqBinario);
        printf("%4s %10d %29s %15d\n\n", Municipio.uf, Municipio.codufmun, Municipio.NomeMunicipio, Municipio.populacao);
    }
    fclose(arqBinario);
    fclose(arqTexto);

    printf("\n\n\nDigite algo para encerrar: ");
    getche();
    return 0;
}
