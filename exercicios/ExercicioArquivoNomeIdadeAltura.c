/*
 Objetivo : Criar um arquivo, abrir e salvar: nome idade e altura; Listar arquivo; Cadastrar mais; Salvar novamente; arquivo e listar novamente.
 Entrada : Nome, idade, altura.
 Saida : Nome, idade, altura.
 Aluno : Rafael Florentino.
        fscanf:
        w -> Escrita
        r -> leitura
        a -> anexar

        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/
#include <stdio.h>
#include <conio.h>

void escrever(char f[])
{
    FILE *file = fopen(f, "w");
    char nome[100];
    int opcao, idade;
    float altura;

    printf("\n        *** Area de Cadastros *** ");
    if (file)
    {
        do
        {
            /*printf("Digite nome, idade e altura: ");
            scanf("%100[^\n]%d%f", nome, &idade, &altura);*/

            printf("\n          *** Novo Cadastro *** \n\n");
            printf("Digite o nome: ");
            scanf("%100[^\n]f", nome);
            fflush(stdin);

            printf("Digite a idade: ");
            scanf("%d", &idade);
            fflush(stdin);

            printf("Digite a altura: ");
            scanf("%f", &altura);
            fflush(stdin);

            fprintf(file, "%s %d %.2f\n", nome, idade, altura);

            printf("\nDigite 1 para INSERIRIR outro registro ou outro numero para SAIR: ");
            scanf("%d", &opcao);
            fflush(stdin);

        } while (opcao == 1);
        fclose(file);
    }
    else
    {
        printf("\nERRO ao abrir arquivo!\n");
    }
    printf("\n");
    system("pause");
    system("cls");
}

void ler(char f[])
{
    FILE *file = fopen(f, "r");
    char nome[100];
    int idade;
    float altura;

    printf("\n        *** Area de Listagem *** ");
    if (file)
    {
        printf("\n\tDados lidos do arquivo:\n");
        while (fscanf(file, "%s%d%f", nome, &idade, &altura) != -1)
            printf("\n\tNome: %s\n\tIdade: %d\n\tAltura: %.2f\n", nome, idade, altura);
        fflush(stdin);
        fclose(file);
    }
    else
    {
        printf("\nERRO ao abrir arquivo!\n");
    }
    printf("\n");
    system("pause");
    system("cls");
}

void escreverMais(char f[])
{
    FILE *file = fopen(f, "a");
    char nome[100];
    int opcao, idade;
    float altura;

    printf("\n        *** Area Escrever Mais *** ");
    if (file)
    {
        do
        {
            printf("\n          *** Novo Cadastro *** \n\n");
            printf("Digite o nome: ");
            scanf("%100[^\n]f", nome);
            fflush(stdin);

            printf("Digite a idade: ");
            scanf("%d", &idade);
            fflush(stdin);

            printf("Digite a altura: ");
            scanf("%f", &altura);
            fflush(stdin);

            fprintf(file, "%s %d %.2f\n", nome, idade, altura);

            printf("\nDigite 1 para INSERIRIR outro registro ou outro numero para SAIR: ");
            scanf("%d", &opcao);
            fflush(stdin);
        } while (opcao == 1);
        fclose(file);
    }
    else
    {
        printf("\nERRO ao abrir arquivo!\n");
    }
}

int main()
{
    char nome[] = {"arquivo.txt"};

    escrever(nome);
    ler(nome);
    escreverMais(nome);
    ler(nome);
    printf("\n        *** Final do Programa *** \n\n");

    return 0;
}