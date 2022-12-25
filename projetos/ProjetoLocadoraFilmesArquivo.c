/*
 Objetivo : Locadora, cadastrar filmes
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
void cadastrarFilme();
void listarFilmes();
void menuPrincipal();

int main()
{
    printf("\n                 ************ Locadora Favorita ****************\n");
    printf("\n                     ********** Seja Bem Vindo ***********\n");
    menuPrincipal();    
    printf("\n\n                    ******** Fim do Programa **********\n");
    getch();
    return 0;
}

void menuPrincipal(){
  int opcaoMenu, auxiliar = 0;
  auxiliar = Filme.quantidadeSuspense;
  printf("\n                                **** Menu Principal ***"); 
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
    cadastrarFilme(); 
    break;
  case 2:
    listarFilmes();   
    break;
  case 3:
    MenuConsultarFilme();
    break;
  case 4:
    ReservarFilme();
    break;
  case 5:
    printf("\n Quantidade de filmes de Suspense: %d", auxiliar);
    menuPrincipal();
    break;
  case 6:
    printf("\nPrograma Encerrado.\n");
    system("pause");
    break;    
  }
}

void cadastrarFilme(){
  int i = 0, j = 0;
  printf("\n                        ****** Cadastro de Filmes ********\n\n");
  printf("Digite a quantidade de filmes que voce deseja cadastrar: ");
  scanf("%d", &j);

  for (i = 0; i < j; i++) 
  {
    printf("\n                       ***** Filme %d *****\n\n",i+1);
    printf("Digite o codigo do Filme %d: ", i+1);
    scanf("%d", &Filme.codigo[i]);
    fflush(stdin);
    printf("Digite o nome do Filme %d: ", i+1);
    gets(Filme.nome[i]); 
    fflush(stdin);
    printf("Digite o genero do Filme %d (Suspense, Terror, Romance, Comedia): ", i+1);
    gets(Filme.genero[i]);
    fflush(stdin);   
    int ret = strcmp("suspense", Filme.genero[i]);
    int ret2 = strcmp("Suspense", Filme.genero[i]);
    int ret3 = strcmp("SUSPENSE", Filme.genero[i]);
    if (ret == 0 || ret2 == 0 || ret3 == 0){
      Filme.quantidadeSuspense++;
    }
    printf("Digite a quantidade do Filme %d: ", i+1);
    scanf("%d", &Filme.quantidadeDisponivel[i]);
    fflush(stdin);
    Filme.totalCadastrado++;
    printf("\n ");
    system("pause");
    system("cls");
    menuPrincipal();
  }
  printf("\n                        ** Lista de Filmes **\n\n");
  for (i = 0; i < j; i++)
  {    
    printf("Filme %d. Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", i+1, Filme.codigo[i], Filme.nome[i], Filme.genero[i], Filme.quantidadeDisponivel[i]);
  }
  printf("\n                     **Fim da Lista de Filmes**\n\n");

   printf("\nQuantidade suspense: ",Filme.quantidadeSuspense);
   printf("\n");

    FILE *arquivo;
    FILE *arquivoEntrada;
    arquivo = fopen("teste.txt", "wt");
    arquivoEntrada = fopen("teste.txt", "wt");
   
    if (arquivo == NULL)
    {
        printf("Nao foi possivel acessar o arquivo.");
    }
    else
    {
        printf("\nO arquivo foi acessado com sucesso!!! \n");

        for (i = 0; i < j; i++)
        {
          fprintf(arquivoEntrada,"%d %s %s %d \n", Filme.codigo[i], Filme.nome[i], Filme.genero[i], Filme.quantidadeDisponivel[i]);
        }
        printf("\nO arquivo foi acessado com sucesso!!! \n");

        fclose(arquivoEntrada);
        fclose(arquivo);
    } 
    menuPrincipal();  
}

void listarFilmes(){
  FILE *arquivo;
  int codigoFilme, quantidadeFilmeDisponivel, i;
  char nomeFilme[100], generoFilme[100];
  arquivo = fopen("teste.txt", "r");

  printf("\n\n                  ****** Listando Todos os Filmes *******\n");
  printf("                    ****** Conteudo do Arquivo *******\n\n");
  for(i=0; i < Filme.totalCadastrado; i++){
   // (fscanf(arquivo, "%d %s %s %d", Filme.codigo[i], Filme.nome[i], Filme.genero[i], Filme.quantidadeDisponivel[i]) != EOF);
     printf("Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", Filme.codigo[i], Filme.nome[i], Filme.genero[i], Filme.quantidadeDisponivel[i]);
  }
 /* while (fscanf(arquivo, "%d %s %s %d", Filme.codigo, Filme.nome, Filme.genero, Filme.quantidadeDisponivel) != EOF){
    printf("Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", codigoFilme, nomeFilme, generoFilme, quantidadeFilmeDisponivel);       
  }*/
  fclose(arquivo);
  printf("\n");
  system("PAUSE");
  menuPrincipal();
}
void MenuConsultarFilme(){
  menuPrincipal();
  return;
}

void  ReservarFilme(){
  menuPrincipal();
  return;
}