/*
 Objetivo : Projeto Locadora de filmes, cadastrar filmes, listar
 Entrada : Codigo, nome, quantidade, genero.
 Saida : Filmes cadastrados.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

struct estrutura
{
    int codigo[100], quantidadeDisponivel[100], totalCadastrado, quantidadeSuspense;
    char nome[100][100], genero[100][100];

} Filme;

void cadastrarFilmes();
void listarFilmes();
void verificaSuspence(char generoFilme[100]);

int main()
{
    int i = 0, j = 0;
    printf("\n                 ************ Locadora Favorita ****************\n");
    printf("\n                     ********** Seja Bem Vindo ***********\n");
    cadastrarFilmes();
    listarFilmes();
    MenuPrincipal();
    
    return;
}

void cadastrarFilmes()
{
    int i, j;
    printf("\n                        ****** Cadastro de Filmes ********\n\n");
    printf("Digite a quantidade de filmes que voce deseja cadastrar: ");
    scanf("%d", &j);
    for (i = 0; i < j; i++)
    {
        printf("\n                        ***** Filme %d *****\n\n", i + 1);
        printf("Digite o codigo do Filme %d: ", i + 1);
        scanf("%d", &Filme.codigo[i]);
        fflush(stdin);
        printf("Digite o nome do Filme %d: ", i + 1);
        gets(Filme.nome[i]);
        fflush(stdin);
        printf("Digite o genero do Filme %d (Suspense, Terror, Romance, Comedia): ", i + 1);
        gets(Filme.genero[i]);
        verificaSuspence(Filme.genero[i]);
        fflush(stdin);
        printf("Digite a quantidade do Filme %d: ", i+1);
        scanf("%d", &Filme.quantidadeDisponivel[i]);
        fflush(stdin);
        Filme.totalCadastrado++;
        printf("\n ");
        system("pause");
        system("cls");
    }
    return;
}

void listarFilmes(){    
    int i;
    printf("\n                        ** Lista de Filmes **\n\n");
    for (i = 0; i < Filme.totalCadastrado; i++)
    {    
        printf("Filme %d. Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", i+1, Filme.codigo[i], Filme.nome[i], Filme.genero[i], Filme.quantidadeDisponivel[i]);
    }
    printf("\n                     **Fim da Lista de Filmes**\n\n");
    system("pause");
    return;
}

void MenuPrincipal(){
  int opcaoMenu;
  printf("\n                               ****Menu Principal***"); 
  printf("\n*** Digite 1 Para Consultar um filme. ***");
  printf("\n*** Digite 2 Para reservar um filme. ***");
  printf("\n*** Digite 3 para ver a Quantidade de filmes de Suspense. ***");
  printf("\n*** Digite 4 Para sair. ***\n");
  printf("\nDigite o numero da opcao: ");
  scanf("%d", &opcaoMenu);
  fflush(stdin);
  switch (opcaoMenu)
  {   
  case 1:
    printf("\nMenuConsultarFilme() fazer");
    
    break;
  case 2:
    printf("\nReservarFilme() fazer");
    
    break;
  case 3:
    printf("\nQuantidade de filmes de Suspense: %d",Filme.quantidadeSuspense);
    break;
  case 4:
    printf("\nPrograma Encerrado.\n");
    system("pause");
  }
    return;
}

void verificaSuspence(char generoFilme[100]){
    int ret = strcmp("suspense", generoFilme);
    int ret2 = strcmp("Suspense", generoFilme);     
    int ret3 = strcmp("SUSPENSE", generoFilme);     
    if(ret == 0 || ret2 == 0 || ret3 == 0  ){
        Filme.quantidadeSuspense++;
    }
    return;
}