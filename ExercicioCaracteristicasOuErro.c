/* 
 Objetivo : Exibir uma listagem das carcteristicas do produto ou uma mensagem de erro.
 Entrada : Código, nome, quantidade, valor de compra valor de venda.
 Saida :  Listagem das carcteristicas do produto ou uma mensagem de erro.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int i, quantidade, numero[100], codigo[100], codigo2[100];
    char nome[100][50];
    float salario[100], valorcompra[100], valorvenda[100];

    printf("Informe a quantidade de produtos: \n");
    scanf("%d", &quantidade);
    for (i = 1; i <= quantidade; i++)
    {
        printf("\nInforme o nome do produto: \n");
        scanf(" %[^\n]", &nome[i]);
        printf("Informe o codigo do produto: \n");
        scanf("%d", &codigo[i]);
        printf("Informe a quantidade de produtos: \n");
        scanf("%d", &numero[i]);
        printf("Informe o preco de compra do produto: \n");
        scanf("%f", &valorcompra[i]);
        printf("Informe o preco de venda do produto: \n");
        scanf("%f", &valorvenda[i]);
        fflush(stdin);
        printf("\n");
        system("cls");
    }
    printf("\t\tArea de Busca\t\t \n");
    for (i = 1; i <= quantidade; i++)
    {
        printf("Informe o codigo do produto a ser pesquisado: \n");
        scanf("%d", &codigo2[i]);
        if ((codigo[i] == codigo2[i]))
        {
            printf("\nNome: %s \nQuantidade: %d \nValor de compra: %0.2f \nValor de venda: %0.2f \n", nome[i], numero[i], valorcompra[i], valorvenda[i]);
        }
        else
        {
            printf("\nErro, codigo invalido, produto nao cadastrado.\n");
        }
        printf("\n");       
        system("pause");
        system("cls");
    }    
    return (0);
}
