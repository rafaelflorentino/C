/*
 Objetivo : Fazer um programa em "C" que gere um arquivo BINÁRIO contendo dados de atletas de um clube. Os dados de cada atleta,
 a serem lidos via teclado, são: Nr_Sócio (inteiro), Bolsa_Atleta (real), Idade (inteiro) e Esporte (cadeia de
 caracteres). O Esporte pode ser: futebol, vôlei, basquete ou natação. Perguntar, inicialmente, a quantidade de atletas do
 clube. Após a gravação do arquivo binário, o mesmo programa deverá abri-lo e mostrar na tela seu conteúdo. O nome para o
 arquivo deve ser lido via teclado.
 Entrada : Quantidade de atletas.
 Saida : Arquivo binário, conteudo do arquivo na tela.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    typedef struct
    {
        int Nr_Socio;
        float Bolsa;
        int Idade;
        char Esporte[15];
    } DadosAtleta;

    DadosAtleta Atleta;
    int I, Quant, NrEsporte;
    FILE *p;
    char NomeArq[15];

    printf("Entre com a quantidade de atletas do Clube: ");
    scanf("%d", &Quant);
    fflush(stdin);
    printf("Entre com o Nome do Arquivo Texto a ser gravado: ");
    fflush(stdin);
    gets(NomeArq);
    p = fopen(NomeArq, "w");

    for (I = 1; I <= Quant; I++)
    {
        printf("\nLeitura dos dados do %do Atleta: \n", I);
        printf("Entre com um inteiro - Nr de Socio: ");
        scanf("%d", &Atleta.Nr_Socio);
        printf("Entre com o Valor da Bolsa Atleta (digitar ',' para os centavos) : R$ ");
        scanf("%f", &Atleta.Bolsa);
        printf("Entre com a idade do Atleta: ");
        fflush(stdin);
        scanf("%d", &Atleta.Idade);
        do
        {
            printf("\nEntre com o Esporte, podendo ser : \n");
            printf("      1. futebol,\n");
            printf("      2. volei,\n");
            printf("      3. basquete ,\n");
            printf("      4. natacao.\n");
            printf("      ");
            scanf("%d", &NrEsporte);
        } while ((NrEsporte) < 1 || (NrEsporte) > 4);
        switch (NrEsporte)
        {
        case 1:
            strcpy(Atleta.Esporte, "futebol");
            break;
        case 2:
            strcpy(Atleta.Esporte, "volei");
            break;
        case 3:
            strcpy(Atleta.Esporte, "basquete");
            break;
        case 4:
            strcpy(Atleta.Esporte, "natacao");
        }
        printf("\n");
        fprintf(p, "%6d  %7.2f  %2d  %-9s\n", Atleta.Nr_Socio,
                Atleta.Bolsa, Atleta.Idade, Atleta.Esporte);
    }
    fclose(p);

    p = fopen(NomeArq, "r");
    printf("\nConteudo do arquivo Texto %s :\n", NomeArq);
    I = 1;
    while (fscanf(p, "%d %f %d %s", &Atleta.Nr_Socio,
                  &Atleta.Bolsa, &Atleta.Idade, Atleta.Esporte) != EOF)
    {
        printf("\nDados Gravados do %do Atleta: \n", I);
        printf("Nr de Socio: %d\n", Atleta.Nr_Socio);
        printf("Valor da Bolsa Atleta: R$ %.2f\n", Atleta.Bolsa);
        printf("Idade do Atleta: %d\n", Atleta.Idade);
        printf("Esporte praticado: %s\n\n", Atleta.Esporte);
        I++;
    }
    fclose(p);
    printf("\nPressione uma TECLA para encerrar ... ");
    getche();
    return 0;
}
