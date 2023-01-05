/*
 Objetivo : leia os dados de uma planilha, depois salve os dados lidos em um novo arquivo binário.
 Entrada : Nome do arquivo binário que será criado.
 Saida : arquibv binário.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h> /* atoi   */
#include <locale.h>
// Rotina para tratar o Nome do Municipio
void TrataNomeEstabelecimento(char *NomeMun)
{
    int i = 0;
    while (NomeMun[i] != '\0')
        i++;
    i -= 4; /*escapa do "lixo" de 2/3 bytes antes do final da string*/
    while (NomeMun[i] == ' ')
        i--;
    NomeMun[++i] = '\0'; /*string fica do tamanho ideal*/
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    typedef struct
    {

        int cnpj, codufmun;
        char RazaoSocial[60], Logradouro[60];

    } DadosEstabelecimento;
    DadosEstabelecimento Estabelecimento;
    FILE *arquivo, *binario;

    /*   salvando o nome do arquivo num vetor: nomeTex[40] */
    char nomeBin[40], nomeTex[40] = "tabelaestabelecimentosParcial.csv", buf[1000];
    /*  unsigned char */ int c, i = -1;

    /*  Caso queira criar o nome do arquivo ou acessar outro arquivo */
    /*printf("Digite o nome/caminho do arquivo TEXTO a ser convertido: ");
    gets(nomeTex); */

    /*   Abrindo o Arquivo e validando            */
    arquivo = fopen(nomeTex, "r");

    /*   Validando o arquivo */
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s !", nomeTex);
        printf("\n\nPressione uma TECLA para TERMINAR ... ");
        getche();
        return 0;
    }

    /*   imprimindo o Arquivo usando fgetc          */
    printf("Usando fgetc - Conteudo do arquivo %s :\n\n", nomeTex);
    while ((c = fgetc(arquivo)) != EOF)
        printf("%c", c);

    /*   voltando ao começo do arquivo */
    rewind(arquivo);

    /*   imprimindo denovo o Arquivo usando agora o comando fgets          */
    printf("\nUsando fgets - Conteudo do arquivo %s :\n\n", nomeTex);
    while (fgets(buf, 1000, arquivo) != NULL)
        printf("%s", buf);

    /*   Fechando o Arquivo           */
    fclose(arquivo);

    /*   Abrindo o Arquivo texto          */
    arquivo = fopen(nomeTex, "r");
    printf("\nNovamente usando fgets - Conteudo do arquivo %s :\n\n", nomeTex);
    fgets(buf, 1000, arquivo);
    while (!feof(arquivo))
    {
        printf("%s", buf);
        fgets(buf, 1000, arquivo);
    }
    rewind(arquivo);

    printf("\n\nDigite o nome a ser dado para o arquivo Binario: ");
    gets(nomeBin);
    /*   Abrindo o Arquivo bianario          */
    binario = fopen(nomeBin, "w+b");

    /*LENDO O ARQUIVO TEXTO, ARMAZENANDO NAS RESPECTIVAS VARIÁVEIS e gravando o Arquivo Binário*/
    fgets(buf, 1000, arquivo); /* leitura da 1 linha do arquivo Texto - cabeçalho */
    printf("\n\tConteudo do arquivo TEXTO csv: \n\n");
    printf("%10d %10d %13s %10s ", "CNPJ", "codufmun", "RazaoSocial", "Logradouro\n"); /*cabeçalho da listagem*/
    printf("__________________________________________________________________________\n\n");
    fgets(buf, 1000, arquivo);
    while (!feof(arquivo))
    {
        Estabelecimento.cnpj = atoi(strtok(NULL, ";"));
        Estabelecimento.codufmun = atoi(strtok(NULL, ";"));
        strcpy(Estabelecimento.RazaoSocial, strtok(NULL, ";"));
        strcpy(Estabelecimento.Logradouro, strtok(NULL, ";"));
        TrataNomeEstabelecimento(Estabelecimento.RazaoSocial);
        TrataNomeEstabelecimento(Estabelecimento.Logradouro);

        printf("%10d %10d %13s %10sd\n\n", Estabelecimento.cnpj, Estabelecimento.codufmun, Estabelecimento.RazaoSocial, Estabelecimento.Logradouro);
        fwrite(&Estabelecimento, sizeof(Estabelecimento), 1, binario);
        fgets(buf, 1000, arquivo);
    }
    printf("__________________________________________________________________________\n\n");
    printf("\n\tConteudo do arquivo BINARIO gerado : \n\n");
    rewind(binario);
    fread(&Estabelecimento, sizeof(Estabelecimento), 1, binario);
    while (!feof(binario))
    {
        printf("%10d %10d %13s %10sd\n\n", Estabelecimento.cnpj, Estabelecimento.codufmun, Estabelecimento.RazaoSocial, Estabelecimento.Logradouro);
        fread(&Estabelecimento, sizeof(Estabelecimento), 1, binario);
    }

    fclose(binario);
    fclose(arquivo);
    printf("\n\n\nDigite algo para encerrar: ");

    getche();
    return 0;
}
