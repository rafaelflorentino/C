/*
 Objetivo: Criar um vetor e insira valores, percorra ele, delete valores e imprima os dados.
 Entrada : Sem Entrada.
 Saida   : Elementos do vetor.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
int main()
{
    int LA[] = {1, 3, 5, 7, 8}; // Vetores são containers homogêneos(elementos do mesmo tipo) contém número fixo de itens
    int item = 10, k = 3, n = 5; // Elementos do vetor possuem indice e valor: [0]=1
    int i = 0, j = n;
    printf("Os elementos do vetor são:\n");
    for (i = 0; i < n; i++)
    {
        printf("LA[%d] = %d \n", i, LA[i]);
    }

    // inserção
    n = n + 1;
    while (j >= k)
    {
        LA[j + 1] = LA[j];
        j = j - 1;
    }
    LA[k] = item;
    printf("Os elementos após a inserção:\n");
    for (i = 0; i < n; i++)
    {
        printf("LA[%d] = %d \n", i, LA[i]);
    }

    // Exclusão
    k = 3;
    j = k;
    while (j < n)
    {
        LA[j - 1] = LA[j];
        j = j + 1;
    }
    n = n - 1;
    printf("Os elementos após a exclusão são:\n");
    for (i = 0; i < n; i++)
    {
        printf("LA[%d] = %d \n", i, LA[i]);
    }
    // Pesquisa
    while (j < n)
    {
        if (LA[j] == item)
        {
            break;
        }
        j = j + 1;
    }
    printf("Encontrado o elemento %d na posião %d\n", item, j + 1);

    // Atualização
    k = 3;
    LA[k - 1] = item;
    printf("Os elementos após a atualização são:\n");
    for (i = 0; i < n; i++)
    {
        printf("LA[%d] = %d \n", i, LA[i]);
    }
}