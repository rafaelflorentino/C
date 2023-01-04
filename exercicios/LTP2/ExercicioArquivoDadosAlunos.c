/*
 Objetivo : Fazer um programa que receba o nome do arquivo, e salve nele matricula idade, mensalidade, depois leia e imprima na tela o arquivo.
 Entrada : Nome arquivo, matricula e idade, mesalidade.
 Saida : Arquivo, e os dados do arquivo na tela.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
int main()
{
    FILE *UCB;
    char nome_arquivo[32], Matricula[12];
    float Mensalidade;
    int Idade, Cont;

    printf("\nEntre com o nome do arquivo texto a ser criado: ");
    gets(nome_arquivo);

    UCB = fopen(nome_arquivo, "wb");

    for (Cont = 1; Cont <= 4; Cont++)
    {
        fflush(stdin);
        printf("\n\nDados do %do Aluno da UCB ...\n", Cont);
        printf("\nEntre com a Matricula: ");
        gets(Matricula);
        printf("Entre com a Idade: ");
        scanf("%d", &Idade);
        printf("Entre com a Mensalidade: ");
        scanf("%f", &Mensalidade);
        fprintf(UCB, "%12s  %2d  %7.2f\n", Matricula, Idade, Mensalidade);
    }
    fclose(UCB);

    UCB = fopen(nome_arquivo, "rb");

    printf("\n\n***** Conteudo do arquivo de 4 Alunos da UCB ******\n\n");
    while (fscanf(UCB, "%s %d %f", Matricula, &Idade, &Mensalidade) != EOF)
        printf("Matricula: %-12s    Idade: %2d anos     Mensalidade: R$ %7.2f\n\n", Matricula, Idade, Mensalidade);
    fclose(UCB);

    getch();
    return 0;
}
