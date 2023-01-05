/*
 Objetivo : leia os dados de uma planilha, depois salve os dados lidos em um novo arquivo binário.
 Entrada : Nome do arquivo binário que será criado.
 Saida : arquivo binário.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

/* Tratar nome dos municipios   */
void TrataNomeMunicipio(char *NomeMun)
{
    int i = 0;
    while (NomeMun[i] != '\0')
        i++;
    i -= 4; /* Escapa do "lixo" de 2/3 bytes antes do final da string */
    while (NomeMun[i] == ' ')
    i--;
    NomeMun[++i] = '\0'; /* String fica do tamanho ideal */
}

/* Principal   */
int main()
{
    setlocale(LC_ALL, "Portuguese"); // idioma português, acentos etc.

    typedef struct
    {
        int uf, codufmun, Populacao;
        char NomeMunicipio[60];

    } DadosMunicipio;

    DadosMunicipio Municipio;
    FILE *arquivo, *binario;

    char nomeBin[40], nomeTex[40] = "a.csv", buf[1000];
    int c, i = -1;

    /* Abrindo o Arquivo */
    arquivo = fopen(nomeTex, "r");

    /* Validando o arquivo */
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s !", nomeTex);
        printf("\n\nPressione uma TECLA para TERMINAR ... ");
        getche();
        return 0;
    }

    /* Imprimindo  o Arquivo usando  o comando fgets  */
    printf("\nUsando fgets - Conteudo do arquivo %s :\n\n", nomeTex);
    while (fgets(buf, 1000, arquivo) != NULL)
        printf("%s", buf);

    /* Fechando o Arquivo */
    fclose(arquivo);

    /* Abrindo o Arquivo texto   */
    arquivo = fopen(nomeTex, "r");
    printf("\n\nNovamente usando fgets - Conteudo do arquivo %s :\n\n", nomeTex);
    fgets(buf, 1000, arquivo);
    while (!feof(arquivo))
    {
        printf("%s", buf);
        fgets(buf, 1000, arquivo);
    }
    rewind(arquivo);

    printf("\n\nDigite o nome a ser dado para o arquivo Binario: ");
    gets(nomeBin);
    /* Abrindo o Arquivo bianario   */
    binario = fopen(nomeBin, "w+b");

    /* LENDO O ARQUIVO TEXTO, ARMAZENANDO NAS RESPECTIVAS VARIÁVEIS e gravando o Arquivo Binário */
    fgets(buf, 1000, arquivo); /* leitura da 1 linha do arquivo Texto - cabeçalho */
    printf("\n\tConteudo do arquivo TEXTO csv: \n\n");
    printf("%13s %10d %13s %10d ", "UF", "CodigoUf", "NomeMunicipio", "Populacao\n"); /* Cabeçalho da listagem*/
    printf("__________________________________________________________________________\n\n");
    fgets(buf, 1000, arquivo);
    while (!feof(arquivo))
    {
        Municipio.uf = atoi(strtok(NULL, ";"));
        Municipio.codufmun = atoi(strtok(NULL, ";"));
        strcpy(Municipio.NomeMunicipio, strtok(NULL, ";"));
        TrataNomeMunicipio(Municipio.NomeMunicipio);
        Municipio.Populacao = atoi(strtok(NULL, ";"));

        printf("%13s %10d %13s %10d\n\n", Municipio.uf, Municipio.codufmun, Municipio.NomeMunicipio, Municipio.Populacao);
        fwrite(&Municipio, sizeof(Municipio), 1, binario);
        fgets(buf, 1000, arquivo);
    }
    printf("__________________________________________________________________________\n\n");
    printf("\n\tConteudo do arquivo BINARIO gerado : \n\n");
    rewind(binario);
    fread(&Municipio, sizeof(Municipio), 1, binario);
    while (!feof(binario))
    {
        printf("%13s %10d %13s %10sd\n\n", Municipio.uf, Municipio.codufmun, Municipio.NomeMunicipio, Municipio.Populacao);
        fread(&Municipio, sizeof(Municipio), 1, binario);
    }
    fclose(binario);
    fclose(arquivo);
    printf("\n\n\nDigite algo para encerrar: ");

    getche();
    return 0;
}

/*
        Arquivo a.csv
    df 111 ceilandia 2000000;
    am 222 manaus 40000;
    sp 333 santos 9000000;
    go 444 goiania 150000;
*/
