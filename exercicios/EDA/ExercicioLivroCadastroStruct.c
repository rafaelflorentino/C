/*
 Objetivo : Escreva um programa em C que receba o nome e o codigo de 5 livros e imprima na tela.
 Entrada : Nome, codigo.
 Saida : Livros Cadastrados.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    char titulo[100];
    int codigo;
} livro;

int main(void)
{ 
    livro *VetLivros;
    int aux;
    // VetLivros = calloc(5,sizeof(livro));
    VetLivros = (livro *)malloc(sizeof(livro) * 5);
    for (aux = 0; aux < 5; aux++)
    {
        printf("\nInforme o nome do %do livro: ", aux + 1);
        fflush(stdin);
        gets(VetLivros[aux].titulo);
        printf("Informe o codigo do %do livro : ", aux + 1);
        scanf("%d", &VetLivros[aux].codigo);
        fflush(stdin);
        printf("\n\n");
    }
    printf("\n\nDados dos livros cadastrados :\n\n");
    for (aux = 0; aux < 5; aux++)
    {
        printf("%do Livro\n", aux + 1);
        printf("Nome: %s \n", VetLivros[aux].titulo);
        printf("Codigo : %d \n\n", VetLivros[aux].codigo);
    }
    // Finalização
    printf("\n\nDigite qualquer TECLA para TERMINAR o PROGRAMA .... ");
    getch();
    return 0;
}
