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
  int codigo[100], quantidadeDisponivel[100], totalCadastrado, quantidadeSuspense, reservados[100];
  char nome[100][100], genero[100][100];

} Filme;

void cadastrarFilmes();
void listarFilmes();
void verificaSuspence(char generoFilme[100]);
void MenuConsultaFilme();
void consultarNome();
void consultarCodigo();
void efetuarReserva();
void cadastrarMais();
void converte(char r1[], char r2[], char r3[]);

int main()
{
  int i = 0, j = 0;
  printf("\n                 ************ Locadora Favorita ****************\n");
  printf("\n                     ********** Seja Bem Vindo ***********\n");
  cadastrarFilmes();

  return 0;
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
    printf("Digite a quantidade do Filme %d: ", i + 1);
    scanf("%d", &Filme.quantidadeDisponivel[i]);
    fflush(stdin);
    Filme.totalCadastrado++;
    printf("\n ");
    system("pause");
    system("cls");
  }
  MenuPrincipal();
}

void listarFilmes()
{
  int i;
  printf("\n                        ** Lista de Filmes **\n\n");
  for (i = 0; i < Filme.totalCadastrado; i++)
  {
    printf("Filme %d. Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; Reservados: %d \n", i + 1, Filme.codigo[i], Filme.nome[i], Filme.genero[i], Filme.quantidadeDisponivel[i], Filme.reservados[i]);
  }
  printf("\n                     **Fim da Lista de Filmes**\n\n");
  system("pause");
  MenuConsultaFilme();
}

void MenuPrincipal()
{
  int opcaoMenu;
  printf("\n                               **** Menu Principal ***");
  printf("\n*** Digite 1 Para Consultar um filme. ***");
  printf("\n*** Digite 2 Para Reservar/Alugar um filme. ***");
  printf("\n*** Digite 3 para ver a Quantidade de filmes de Suspense. ***");
  printf("\n*** Digite 4 Para Cadastrar mais Filmes. ***");
  printf("\n*** Digite 5 Para sair. ***\n");
  printf("\nDigite o numero da opcao: ");
  scanf("%d", &opcaoMenu);
  fflush(stdin);

  switch (opcaoMenu)
  {
  case 1:
    MenuConsultaFilme();
    break;
  case 2:
    efetuarReserva();
    system("pause");
    MenuPrincipal();
    break;
  case 3:
    printf("\nQuantidade de filmes de Suspense: %d", Filme.quantidadeSuspense);
    printf("\n ");
    system("pause");
    MenuPrincipal();
    break;
  case 4:
    cadastrarMais();
    break;
  case 5:
    printf("\nPrograma Encerrado.\n");
    break;      
  }
  printf("\n");
  return 0;
}

void verificaSuspence(char generoFilme[100])
{  
  int ret = strcmp("suspense", generoFilme);
  int ret2 = strcmp("Suspense", generoFilme);
  int ret3 = strcmp("SUSPENSE", generoFilme);

  if (ret == 0 || ret2 == 0 || ret3 == 0)
  {
    Filme.quantidadeSuspense++;
  }
}

void MenuConsultaFilme()
{
  int opcaoMenu;
  printf("\n                        *********Menu Consulta***********\n ");
  printf("\n*** Digite 1 para Consultar filme pelo nome ***  ");
  printf("\n*** Digite 2 para Consultar filme pelo codigo ***  ");
  printf("\n*** Digite 3 para Listar todos os filmes cadastrados **** ");
  printf("\n*** Digite 4 para encerrar a Consulta e voltar ao Menu Principal **** ");
  printf("\n\nDigite o numero da opcao: ");
  scanf("%d", &opcaoMenu);
  fflush(stdin);
  switch (opcaoMenu)
  {
  case 1:
    consultarNome();
    system("pause");
    MenuConsultaFilme();
    break;
  case 2:
    consultarCodigo();
    system("pause");
    MenuConsultaFilme();
    break;
  case 3:
    listarFilmes();
    break;
  case 4:
    MenuPrincipal();
    break;
  }
}

void consultarNome()
{
  char nomeBuscar[100];
  int i = 0, temp = 0;

  printf("\nDigite o nome do filme que sera consultado: ");
  gets(nomeBuscar);
  fflush(stdin);

  for (int i = 0; i < Filme.totalCadastrado; i++)
  {
    int ret = strcmp(nomeBuscar, Filme.nome[i]);
    if (ret == 0)
    {
      printf("\nFilme cadastrado. Codigo: %d Nome: %s\n", Filme.codigo[i], Filme.nome[i]);
      temp++;
    }
  }
  if (temp == 0)
  {
    printf("\nFilme Nao cadastrado. Nome Digitado: %s\n", nomeBuscar);
  }
  temp = 0;
  printf("\n");
}

void consultarCodigo()
{
  int codigoBuscar, temp = 0;
  printf("\nDigite o codigo do filme que sera consultado: \n ");
  scanf("%d", &codigoBuscar);
  for (int i = 0; i < Filme.totalCadastrado; i++)
  {
    if (codigoBuscar == Filme.codigo[i])
    {
      printf("Filme cadastrado, Codigo: %d Nome: %s\n", Filme.codigo[i], Filme.nome[i]);
      temp++;
    }
  }
  if (temp == 0)
  {
    printf("Filme nao cadastrado, Codigo Digitado: %d\n", codigoBuscar);
  }
  temp = 0;
  printf("\n");
}

void efetuarReserva()
{ 
  int codigoFilme, temp = 0;
  printf("\n                        ********* Area De Reserva ***********\n ");
  printf("\nDigite o Codigo do Filme: ");
  scanf("%d", &codigoFilme);
  fflush(stdin);
  for (int i = 0; i < Filme.totalCadastrado; i++)
  {
    if (codigoFilme == Filme.codigo[i])
    {
      temp++;
      if (Filme.quantidadeDisponivel[i] > Filme.reservados[i])
      {
        Filme.reservados[i]++;
        printf("\nFilme Reservado com Sucesso, Codigo: %d; Nome: %s; Quantidade: %d; Reservados: %d;\n", Filme.codigo[i], Filme.nome[i], Filme.quantidadeDisponivel[i], Filme.reservados[i]);        
      }
      else
      {
        printf("\nTodas as unidades desse Filme ja foram Alugadas ou Reservadas. Codigo: %d; Nome: %s; Quantidade: %d; Reservados: %d;\n", Filme.codigo[i], Filme.nome[i], Filme.quantidadeDisponivel[i], Filme.reservados[i]);
      }
    }
  }
  if (temp == 0)
  {
    printf("\nFilme Inexistente, nao foi cadastrado, Codigo Digitado: %d\n", codigoFilme);
  }
  temp = 0;
  printf("\n");
}

void cadastrarMais()
{
  int i, j, codigo = 1;
  int ultimoFilme;
  ultimoFilme = Filme.totalCadastrado ;

  for (i = ultimoFilme; codigo != 0; i++)
  {
    printf("\n                        ****** Cadastrar Novo Filme ********\n\n");
    printf("Digite 0 para SAIR ou qualquer tecla para Cadastrar novo Filme: ");
    scanf("%d", &codigo);
    fflush(stdin);

    if (codigo != 0)
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
      printf("Digite a quantidade do Filme %d: ", i + 1);
      scanf("%d", &Filme.quantidadeDisponivel[i]);
      fflush(stdin);
      Filme.totalCadastrado++;
      printf("\n ");
      system("pause");
      system("cls");
    }
  }
  MenuPrincipal();
}
// coverte em 2 strings uma maisucula e a outra minuscula
void converte(char r1[], char r2[], char r3[]){  
    printf("String original: %s\n", r1);
    minusculo(r1, r2);
    printf("String Minuscula: %s\n", r2);
    maiusculo(r1, r3);
    printf("String Maiuscula: %s\n", r3);
    printf("Final da conversao. \n");
}
// Procedimento que converte uma string para maiúsculo.
void maiusculo(char s1[], char s2[]){
    int i = 0;
    while(s1[i] != '\0'){
        s2[i] = toupper(s1[i]);
        i++;
    }
    s2[i] = '\0'; // caracter que indica o fim da string.
}
// Procedimento que converte uma string para minúsculo.
void minusculo(char s1[], char s2[]){
    int i = 0;
    while(s1[i] != '\0'){
        s2[i] = tolower(s1[i]);
        i++;
    }
    s2[i] = '\0'; // Caracter que indica o fim da string.
}

