/*
 Objetivo : Escreva um programa em C que receba o nome do livro e prencha os outros dados do livro de forma automatica(codigo, tipo, preço), valores aleatórios.
 Entrada : Nome.
 Saida : Lista Ordenada pelo codigo, e dados do livro.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h> 

struct Livro
{
    char titulo[50];
    int codigo;  
    int tipo;    
    float preco; 

} livro[5];

int main()
{
    int i;
    srand(time(NULL));
    printf("\n------------ INFORME OS DADOS DO LIVRO -----------------\n");
    for (i = 0; i < 5; i++)
    {
        printf("\n     Livro %d \n ", i + 1);
        printf("\nTitulo: ");
        gets(livro[i].titulo);
        fflush(stdin);
        livro[i].codigo = (rand() % 100);
        livro[i].tipo = (rand() % (14 - 10 + 1) + 10);
        livro[i].preco = 10 + (rand() %  100 );
        printf("Codigo: %d ", livro[i].codigo);
        printf("\nPreco: %2.2f ", livro[i].preco);
        printf("\nTipo: %d \n", livro[i].tipo);
    }

    // Ordenar pelo codigo
    int auxCodigo, auxTipo;
    float auxPreco;
    char auxTitulo[50];

    for(int varreduras = 0; varreduras < 4; varreduras++){
        for(i = 0; i < 4; i++){
            if(livro[i].codigo > livro[i+1].codigo){
                //Codigo
                auxCodigo = livro[i].codigo;
                livro[i].codigo = livro[i+1].codigo;
                livro[i+1].codigo = auxCodigo;
                //Tipo
                auxTipo = livro[i].tipo;
                livro[i].tipo = livro[i+1].tipo;
                livro[i+1].tipo = auxTipo;
                //Preco
                auxPreco = livro[i].preco;
                livro[i].preco = livro[i+1].preco;
                livro[i+1].preco = auxPreco;
                //Titulo(Nome)
                strcpy (auxTitulo, livro[i].titulo);
                strcpy (livro[i].titulo, livro[i+1].titulo);
                strcpy (livro[i+1].titulo, auxTitulo);
            }        
        }
    }

    // Imprimir Lista Ordenada Pelo Codigo
    printf("\n------------ Lista de Livros Ordenada ------------\n");
    for(i = 0; i < 5; i++){
        printf("\nLivro %d", i+1);
        printf("\nCodigo: %d \nNome: %s \nTipo: %d \nPreco: %2.2f \n", livro[i].codigo, livro[i].titulo, livro[i].tipo, livro[i].preco);
    }
    printf("\n");
    system("pause");
    return 0;
}
