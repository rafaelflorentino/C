/* Gerar o arquivo binário Municípios.Bin, com os dados do arquivo Texto TabelaMunicípios.CSV ( ver TEA 25 ).

Criar índice para o arquivo Binário Municípios.BIN, usando Árvore AVL (chave primária é codufmun ).*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h> /* atoi   */
#include <locale.h>
// Rotina para tratar o Nome do Município
void TrataNomeMunicipio(char *NomeMun)
{
    int i = 0;
    while (NomeMun[i] != '\0')
        i++;
    i -= 4; /*escapa do "lixo" de 2/3 bytes antes do final da string*/
    while (NomeMun[i] == ' ')
        i--;
    NomeMun[++i] = '\0'; /*string fica do tamanho ideal*/
}
// Principal
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
    printf("\n\nDigite uma TECLA para prosseguir ... ");
    getch();
    printf("\n\nUsando fgets - Conteudo do arquivo %s :\n", nomeTex);
    while (fgets(buf, 1000, arqTexto) != NULL)
        printf("%s", buf);
    fclose(arqTexto);
    arqTexto = fopen(nomeTex, "r");
    printf("\n\nDigite uma TECLA para prosseguir ... ");
    getch();
    printf("\n\nNovamente usando fgets - Conteudo do arquivo %s :\n", nomeTex);
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
    /*LENDO O ARQUIVO TEXTO, ARMAZENANDO NAS RESPECTIVAS VARIÁVEIS e gravando o Arquivo Binário*/
    fgets(buf, 1000, arqTexto); /* leitura da 1ª linha do arquivo Texto - cabeçalho */
    printf("\n\tConteudo do arquivo TEXTO csv: \n\n");
    printf("%4s %13s %10s %35s", "UF", "COD.MUNIC.", "MUNICIPIO", "POPULACAO\n"); /*cabeçalho da listagem*/
    printf("__________________________________________________________________________\n\n");
    fgets(buf, 1000, arqTexto);
    while (!feof(arqTexto))
    {
        strcpy(Municipio.uf, strtok(buf, ";"));
        Municipio.codufmun = atoi(strtok(NULL, ";"));
        strcpy(Municipio.NomeMunicipio, strtok(NULL, ";"));
        TrataNomeMunicipio(Municipio.NomeMunicipio);
        Municipio.populacao = atoi(strtok(NULL, ";"));
        printf("%4s %10d %29s %15d\n\n", Municipio.uf, Municipio.codufmun, Municipio.NomeMunicipio, Municipio.populacao);
        fwrite(&Municipio, sizeof(Municipio), 1, arqBinario);
        fgets(buf, 1000, arqTexto);
    }
    printf("\n\nDigite uma TECLA para prosseguir ... ");
    getch();
    printf("\n\n__________________________________________________________________________\n\n");
    printf("\n\tConteudo do arquivo BINARIO gerado : \n\n");
    rewind(arqBinario);
    fread(&Municipio, sizeof(Municipio), 1, arqBinario);
    while (!feof(arqBinario))
    {
        printf("%4s %10d %29s %15d\n\n", Municipio.uf, Municipio.codufmun, Municipio.NomeMunicipio, Municipio.populacao);
        fread(&Municipio, sizeof(Municipio), 1, arqBinario);
    }
    fclose(arqBinario);
    fclose(arqTexto);

    printf("\n\n\nDigite algo para encerrar: ");
    getche();
    return 0;
}