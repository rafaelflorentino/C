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

int CadastrarFilme(int *codigoFilme[100],  char *nomeFilme[100][100], char *generoFilme[100][100],int  *quantidadeFilmeDisponivel[100]);
//int listarFilmes(int *codigoFilme[100],  char *nomeFilme[100][100], char *generoFilme[100][100],int  *quantidadeFilmeDisponivel[100]);
void listarFilmes();

int main()
{
    int codigoFilme[100], quantidadeFilmeDisponivel[100];
    char nomeFilme[100][100], generoFilme[100][100];

    printf("\n                 ************ Locadora Favorita ****************\n");
    printf("\n                     ********** Seja Bem Vindo ***********\n");

    CadastrarFilme(&codigoFilme[100], &nomeFilme[100][100], &generoFilme[100][100], &quantidadeFilmeDisponivel[100]);
    listarFilmes();
    
    printf("\n                    ******** Fim do Programa **********\n");
    getch();
    return 0;
}

int CadastrarFilme(int *codigoFilme[100],  char *nomeFilme[100][100], char *generoFilme[100][100],int  *quantidadeFilmeDisponivel[100]){
  int i = 0, j = 0;
  printf("\n                        ****** Cadastro de Filmes ********\n\n");
  printf("Digite a quantidade de filmes que voce deseja cadastrar: ");
  scanf("%d", &j);

  //Cadastrando Filmes
  for (i = 0; i < j; i++) 
  {
    printf("\n                        ***** Filme %d *****\n\n",i+1);
    printf("Digite o codigo do Filme %d: ", i+1);
    scanf("%d", &codigoFilme[i]);
    fflush(stdin);
    printf("Digite o nome do Filme %d: ", i+1);
    gets(nomeFilme[i]); 
    fflush(stdin);
    printf("Digite o genero do Filme %d (Suspense, Terror, Romance, Comedia): ", i+1);
    gets(generoFilme[i]);
    fflush(stdin);
    printf("Digite a quantidade do Filme %d: ", i+1);
    scanf("%d", &quantidadeFilmeDisponivel[i]);
    fflush(stdin);
    printf("\n ");
    system("pause");
    system("cls");
  }

  // Imprimindo Todos os Filmes Dentro da função cadastrar
  printf("\n                        ** Lista de Filmes **\n\n");
  for (i = 0; i < j; i++)
  {    
    printf("Filme %d. Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", i+1, codigoFilme[i], nomeFilme[i], generoFilme[i], quantidadeFilmeDisponivel[i]);
  }
  printf("\n                     **Fim da Lista de Filmes**\n\n");

  //Criando um arquivo e salvando os dados nele
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
            fprintf(arquivoEntrada,"%d %s %s %d \n", codigoFilme[i], nomeFilme[i], generoFilme[i], quantidadeFilmeDisponivel[i]);
        }
        fclose(arquivoEntrada);
        fclose(arquivo);
    } 
    return;
}

void listarFilmes(){

  FILE *arquivo;
  int codigoFilme, quantidadeFilmeDisponivel;
  char nomeFilme[100], generoFilme[100];
  arquivo = fopen("teste.txt", "r");

  printf("\n\n                  ****** Listando Todos os Filmes *******\n");
  printf("                    ****** Conteudo do Arquivo *******\n\n");
  while (fscanf(arquivo, "%d %s %s %d", &codigoFilme, &nomeFilme, &generoFilme, &quantidadeFilmeDisponivel) != EOF){
    printf("Codigo: %d; Nome: %s; Genero: %s; Quantidade: %d; \n", codigoFilme, nomeFilme, generoFilme, quantidadeFilmeDisponivel);       
  }

  fclose(arquivo);
  printf("\n");
  system("PAUSE");
  return;
}
