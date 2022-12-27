/*
 Objetivo : Projeto Locadora, cadastrar filmes, cadastrar e salvar em arquivo .txt, ler arquio .txt e imprimir na tela.
 Entrada : Codigo, nome, quantidade, genero.
 Saida : Filmes cadastrados.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

int cadastro();
void cadastrarMaisFilmes();
void cadastrarFilmes();
void listarFilmes();
void menuPrincipal();

int main()
{
  printf("\n                 ************ Locadora Favorita ****************");
  printf("\n                     ********** Seja Bem Vindo ***********\n");

  menuPrincipal();

  printf("\n\n                    ******** Fim do Programa **********\n");

  return 0;
}
void menuPrincipal()
{
  int opcaoMenu, auxiliar = 0;
  printf("\n                            **** Menu Principal ***\n");
  printf("\n *** Digite 1 Para Cadastrar filmes. ***");
  printf("\n *** Digite 2 Para Listar Todos os filmes. ***");
  printf("\n *** Digite 3 Para Consultar um filme. ***");
  printf("\n *** Digite 4 Para reservar um filme. ***");
  printf("\n *** Digite 5 para ver a Quantidade de filmes de Suspense. ***");
  printf("\n *** Digite 6 Para sair. ***");
  printf("\n\nDigite o numero da opcao: ");
  scanf("%d", &opcaoMenu);
  fflush(stdin);
  switch (opcaoMenu)
  {
  case 1:
    if (cadastro())
    {
      cadastrarMaisFilmes(); // arquivo já esxite
    }
    else
    {
      cadastrarFilmes(); // primeiro cadastro
    }
    break;
    menuPrincipal();
  case 2:
    listarFilmes();
    menuPrincipal();
    break;
  case 3:
    system("pause");

    break;
  case 4:
    system("pause");

    break;
  case 5:
    printf("\n Quantidade de filmes de Suspense: \n");
    printf("\n");
    system("pause");

    break;
  case 6:
    printf("\nPrograma Encerrado.\n");
    system("pause");
    break;
  }
}
int cadastro()
{
  FILE *file;
  if (file = fopen("teste.txt", "r"))
  {
    fclose(file);
    return 1;
  }
  return 0;
}

void cadastrarFilmes()
{
  printf("\n                 ************ Area de Primeiro Cadastro ****************");

  FILE *file = fopen("teste.txt", "w");
  char nome[100], genero[100];
  int opcao, codigo, quantidadeDisponivel;

  if (file)
  {
    do
    {
      printf("\n                    ********** Novo Cadastro ***********\n");

      printf("Digite o Codigo do filme: ");
      scanf("%d", &codigo);
      fflush(stdin);

      printf("Digite o nome do filme: ");
      scanf("%100[^\n]f", nome);
      fflush(stdin);

      printf("Digite o genero do filme: ");
      scanf("%100[^\n]f", genero);
      fflush(stdin);

      printf("Digite a quantidade do filme: ");
      scanf("%d", &quantidadeDisponivel);
      fflush(stdin);

      fprintf(file, "%d %s %s %d\n", codigo, nome, genero, quantidadeDisponivel);

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
  menuPrincipal();
}

void listarFilmes()
{
  FILE *file = fopen("teste.txt", "r");
  char nome[100], genero[100];
  int opcao, codigo, quantidadeDisponivel;

  printf("\n                 ************ Area de Listagem ****************");
  if (file)
  {
    printf("\n                ********** Dados Lidos do Arquivo **************");
    while (fscanf(file, "%d %s %s %d", &codigo, nome, genero, &quantidadeDisponivel) != -1)
    {
      printf("\nCodigo: %d\nNome: %s\nGenero: %s\nQuantidade: %d\n", codigo, nome, genero, quantidadeDisponivel);
    }
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

void cadastrarMaisFilmes()
{
  FILE *file = fopen("teste.txt", "a");
  char nome[100], genero[100];
  int opcao, codigo, quantidadeDisponivel;

  printf("\n                 ************ Area de Mais Cadastros ****************");

  if (file)
  {
    do
    {
      printf("\n                    ********** Novo Cadastro ***********\n");
      printf("Digite o Codigo do filme: ");
      scanf("%d", &codigo);
      fflush(stdin);

      printf("Digite o nome do filme: ");
      scanf("%100[^\n]f", nome);
      fflush(stdin);

      printf("Digite o genero do filme: ");
      scanf("%100[^\n]f", genero);
      fflush(stdin);

      printf("Digite a quantidade do filme: ");
      scanf("%d", &quantidadeDisponivel);
      fflush(stdin);

      fprintf(file, "%d %s %s %d\n", codigo, nome, genero, quantidadeDisponivel);

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
  menuPrincipal();
}