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

struct estrutura
{
  int codigo[100], quantidadeDisponivel[100], totalCadastrado, quantidadeSuspense, reservados[100];
  char nome[100][100], genero[100][100];

} Filme;

struct estrutura2
{
  int codigo[100], quantidadeDisponivel[100], totalCadastrado, quantidadeSuspense, reservados[100];
  char nome[100][100], genero[100][100];

} FilmeArquivo;

void cadastrarFilme();
void cadastrarMaisFilmes();
void listarFilmes();
void menuPrincipal();


int main()
{
  printf("\n                 ************ Locadora Favorita ****************\n");
  printf("\n                     ********** Seja Bem Vindo ***********\n");
  Filme.totalCadastrado = 0;
  menuPrincipal();
  printf("\n\n                    ******** Fim do Programa **********\n");
  getch();
  return 0;
}

void menuPrincipal()
{
  int opcaoMenu, auxiliar = 0;
  printf("\n                               **** Menu Principal ***");
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
    if(Filme.totalCadastrado == 0){
      cadastrarFilme();
    }else{
      cadastrarMaisFilmes();
    }    
    break;
  case 2:
    listarFilmes();
    break;
  case 3:
    system("pause");
    MenuConsultarFilme();
    break;
  case 4:
    system("pause");
    ReservarFilme();
    break;
  case 5:
    printf("\n Quantidade de filmes de Suspense: %d\n", Filme.quantidadeSuspense);
    printf("\n");
    system("pause");
    menuPrincipal();
    break;
  case 6:    
    printf("\nPrograma Encerrado.\n");
    system("pause");
    break;
  }
}

void cadastrarFilme()
{
  // Cadastrando Primeiros Filmes
  int i = 0, j = 0;
  printf("\nNenhum filme cadastrado: %d\n", Filme.totalCadastrado);
  printf("\n                        ****** Primeiro Cadastro de Filmes ********\n\n");
  printf("Digite a quantidade de filmes que voce deseja cadastrar: ");
  scanf("%d", &j);

  for (i = 0; i < j; i++)
  {
    printf("\n                       ***** Filme %d *****\n\n", i + 1);
    printf("Digite o codigo do Filme %d: ", i + 1);
    scanf("%d", &Filme.codigo[i]);
    fflush(stdin);
    printf("Digite o nome do Filme %d: ", i + 1);
    gets(Filme.nome[i]);
    fflush(stdin);
    printf("Digite o genero do Filme %d (Suspense, Terror, Romance, Comedia): ", i + 1);
    gets(Filme.genero[i]);
    fflush(stdin);
    int ret = strcmp("suspense", Filme.genero[i]);
    int ret2 = strcmp("Suspense", Filme.genero[i]);
    int ret3 = strcmp("SUSPENSE", Filme.genero[i]);
    if (ret == 0 || ret2 == 0 || ret3 == 0)
    {
      Filme.quantidadeSuspense++;
    }
    printf("Digite a quantidade do Filme %d: ", i + 1);
    scanf("%d", &Filme.quantidadeDisponivel[i]);
    fflush(stdin);
    Filme.totalCadastrado++;
  }
    printf("\n");       
    system("pause");
    system("cls");

  // Criando um arquivo .txt e Salvando os Primeiros Filmes cadastrados nesse arquivo txt.
  FILE *arquivo;
  FILE *arquivoEntrada;
  arquivo = fopen("teste.txt", "wt");
  arquivoEntrada = fopen("teste.txt", "wt");

  printf("\n                        ** Lista de Filmes Cadastrado Agora**\n\n");

  if (arquivo == NULL)
  {
    printf("Nao foi possivel acessar o arquivo.");
  }
  else
  {
    for (i = 0; i < j; i++)
    {
      fprintf(arquivoEntrada, "%d %s %s %d; \n", Filme.codigo[i], Filme.nome[i], Filme.genero[i], Filme.quantidadeDisponivel[i]);
      printf("Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", Filme.codigo[i], Filme.nome[i], Filme.genero[i], Filme.quantidadeDisponivel[i]);
    }
    printf("\nO arquivo foi salvo com sucesso!!! \n");
    fclose(arquivoEntrada);
    fclose(arquivo);
  }

  printf("\n");       
  system("pause");
  system("cls");
  menuPrincipal();
}

void cadastrarMaisFilmes()
{
  // Cadastrando Mais Filmes
  printf("\n ");
  system("cls");
  printf("\nFilmes ja cadastrados: %d\n", Filme.totalCadastrado);

  int i = 0, j = 0, k = 0;
  FILE *arquivo;
  FILE *arquivoEntrada;
  arquivo = fopen("teste.txt", "a");
  arquivoEntrada = fopen("teste.txt", "a");

  printf("\n                        ****** Cadastrar Mais Filmes ********\n\n");
  printf("Digite a quantidade de filmes que voce deseja cadastrar: ");
  scanf("%d", &j);

  for (i = Filme.totalCadastrado, k = 0; k < j; k++)
  {
    printf("\n                       ***** Filme %d *****\n\n", Filme.totalCadastrado + 1 );
    printf("Digite o codigo do Filme %d: ", Filme.totalCadastrado + 1);
    scanf("%d", &Filme.codigo[i]);
    fflush(stdin);
    printf("Digite o nome do Filme %d: ", Filme.totalCadastrado + 1);
    gets(Filme.nome[i]);
    fflush(stdin);
    printf("Digite o genero do Filme %d (Suspense, Terror, Romance, Comedia): ", Filme.totalCadastrado + 1 );
    gets(Filme.genero[i]);
    fflush(stdin);
    int ret = strcmp("suspense", Filme.genero[i]);
    int ret2 = strcmp("Suspense", Filme.genero[i]);
    int ret3 = strcmp("SUSPENSE", Filme.genero[i]);
    if (ret == 0 || ret2 == 0 || ret3 == 0)
    {
      Filme.quantidadeSuspense++;
    }
    printf("Digite a quantidade do Filme %d: ", Filme.totalCadastrado + 1);
    scanf("%d", &Filme.quantidadeDisponivel[i]);
    fflush(stdin);
    Filme.totalCadastrado++;

    if (arquivo == NULL)
    {
      printf("Nao foi possivel acessar o arquivo.");
    }
    else
    { 
        fprintf(arquivoEntrada, "%d %s %s %d \n", Filme.codigo[i], Filme.nome[i], Filme.genero[i], Filme.quantidadeDisponivel[i]);    
    }
  }
    fclose(arquivoEntrada);
    fclose(arquivo);

    printf("\n ");
    system("pause");
    system("cls");

/*
    // ver cadastrados agora
    printf("\n                        ** Lista de Filmes Cadastrado Agora**\n\n");
    
    for (i = Filme.totalCadastrado, k=0; k < j; i--, k++)
    {
      printf("Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", Filme.codigo[i], Filme.nome[i], Filme.genero[i], Filme.quantidadeDisponivel[i]);
    }
  

  printf("\n ");
  system("pause");
  system("cls"); 
*/ 
  menuPrincipal();
}

void listarFilmes()
{
  FILE *arquivo;
  int codigoFilme, quantidadeFilmeDisponivel, i;
  char nomeFilme[100], generoFilme[100];
  arquivo = fopen("teste.txt", "r");

  printf("\n\n                  ****** Listando Todos os Filmes *******\n");
  printf("                    ****** Conteudo do Arquivo *******\n\n");

 for (i = 0; i < Filme.totalCadastrado; i++)
  {
    //fscanf(arquivo, "%d %s %s %d", FilmeArquivo.codigo[i], FilmeArquivo.nome[i], FilmeArquivo.genero[i], FilmeArquivo.quantidadeDisponivel[i]);
    printf("Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", Filme.codigo[i], Filme.nome[i], Filme.genero[i], Filme.quantidadeDisponivel[i]);
  }

 for (i = 0; i < Filme.totalCadastrado; i++)
  {
    //(fscanf(arquivo, "%d %s %s %d", FilmeArquivo.codigo[i], FilmeArquivo.nome[i], FilmeArquivo.genero[i], FilmeArquivo.quantidadeDisponivel[i]) != EOF);
   // printf("Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", FilmeArquivo.codigo[i], FilmeArquivo.nome[i], FilmeArquivo.genero[i], FilmeArquivo.quantidadeDisponivel[i]);
  }

/*for (i = 0; i < Filme.totalCadastrado; i++)
  {
    fscanf(arquivo, "%d %s %s %d", &FilmeArquivo.codigo[i], FilmeArquivo.nome[i], FilmeArquivo.genero[i], &FilmeArquivo.quantidadeDisponivel[i]);
    printf("Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", FilmeArquivo.codigo[i], FilmeArquivo.nome[i], FilmeArquivo.genero[i], FilmeArquivo.quantidadeDisponivel[i]);
    //FilmeArquivo.totalCadastrado++;
  }*/

  /*while(fscanf(arquivo, "%d %s %s %d", &FilmeArquivo.codigo, FilmeArquivo.nome, FilmeArquivo.genero, &FilmeArquivo.quantidadeDisponivel)!= EOF)
    printf("Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", FilmeArquivo.codigo, FilmeArquivo.nome, FilmeArquivo.genero, FilmeArquivo.quantidadeDisponivel);
  fclose(arquivo);*/
  
  /*while(fscanf(arquivo, "%d %s %s %d", &codigoFilme, &nomeFilme, &generoFilme, &quantidadeFilmeDisponivel) != EOF)
    printf("Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", codigoFilme, nomeFilme, generoFilme, quantidadeFilmeDisponivel);       
  fclose(arquivo);*/

  /*while (fscanf(arquivo, "%d %s %s %d", Filme.codigo, Filme.nome, Filme.genero, Filme.quantidadeDisponivel) != EOF){
     printf("Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", codigoFilme, nomeFilme, generoFilme, quantidadeFilmeDisponivel);
   }*/

  
  printf("\n");
  system("PAUSE");
  menuPrincipal();
}

void MenuConsultarFilme()
{
  menuPrincipal();
  return;
}

void ReservarFilme()
{
  menuPrincipal();
  return;
}