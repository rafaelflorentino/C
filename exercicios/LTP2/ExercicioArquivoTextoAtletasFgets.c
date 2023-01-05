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
    int Nr_Socio;
    float Bolsa;
    int Idade;
    char Esporte[15];
    int I, Quant, NrEsporte;
    FILE *p;
    char NomeArq[15], buf[100];

    printf("Entre com a quantidade de atletas do Clube : ");
    scanf("%d", &Quant);
    fflush(stdin);
    printf("Entre com o Nome do Arquivo Texto a ser gravado : ");
    fflush(stdin);
    gets(NomeArq);

    p = fopen(NomeArq, "w");
    fprintf(p, "%10s  %15s  %8s  %9s\n", "Nr_Socio",
            "Bolsa Atleta", "Idade", "Esporte"); // cabeçalho
    for (I = 1; I <= Quant; I++)
    {
        printf("\nLeitura dos dados do %do Atleta : \n", I);
        printf("Entre com um inteiro - Nr de Socio : ");
        scanf("%d", &Nr_Socio);
        printf("Entre com o Valor da Bolsa Atleta (digitar ',' para os centavos) : R$ ");
        scanf("%f", &Bolsa);
        printf("Entre com a idade do Atleta : ");
        fflush(stdin);
        scanf("%d", &Idade);
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
            strcpy(Esporte, "futebol");
            break;
        case 2:
            strcpy(Esporte, "volei");
            break;
        case 3:
            strcpy(Esporte, "basquete");
            break;
        case 4:
            strcpy(Esporte, "natacao");
        }
        printf("\n\n");
        fprintf(p, "%10d  %15.2f  %8d  %9s\n", Nr_Socio,
                Bolsa, Idade, Esporte);
    }
    fclose(p);

    p = fopen(NomeArq, "r");
    printf("\n\nConteudo do arquivo Texto %s :\n\n", NomeArq);
    fgets(buf, 100, p); // cabeçalho
    while (!feof(p))
    {
        printf("%s", buf);
        fgets(buf, 100, p);
    }
    fclose(p);
    printf("\n\nPressione uma TECLA para encerrar ... ");
    getche();
    return 0;
}
