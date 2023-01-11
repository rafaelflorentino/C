/*
 Objetivo: Implemente uma rotina que receba um apontador contendo o endere�o da
 primeira célula de uma lista encadeada com células do tipo "cel" e
 um inteiro x. A rotina deve mostrar na tela os títulos dos livros
 cujo tipo seja igual a x e retornar quantos livros mostrou.
 Entrada : Codigo, titulo, tipo.
 Saida   : Lista de dados na tela.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
typedef struct
{
     int cod;
     int tipo;
     char titulo[50];
} livro;

typedef struct s_cel
{
     livro esse;
     struct s_cel *prox;
} cel;

typedef cel *lista;

void InsereLista(lista *L, livro novo)
{
     cel *temp;
     temp = (cel *)malloc(sizeof(cel));
     temp->esse = novo;
     temp->prox = *L;
     *L = temp;
}

void ImprimeLista(lista L)
{
     cel *temp = L;
     int Quant = 0;
     while (temp != NULL)
     {
          printf("\nCod=%5d\tTipo=%5d\tTitulo: %s\n", (temp->esse).cod, (temp->esse).tipo, (temp->esse).titulo);
          Quant++;
          temp = temp->prox;
     }
     printf("\nTotal de elementos da Lista = %d\n\n", Quant);
}

int TamanhoLista(lista L)
{
     cel *temp = L;
     int Tam = 0;
     while (temp != NULL)
     {
          Tam++;
          temp = temp->prox;
     }
     return Tam;
}

/*  rotina que receba um apontador contendo o endereço da
    primeira célula de uma lista encadeada com células do tipo "cel" e
    um inteiro x. A rotina deve mostrar na tela os títulos dos livros
    cujo tipo seja igual a x e retornar quantos livros mostrou.     */
int RotQ3P1V1(lista L, int x)
{
     cel *temp = L;
     int Quant = 0;
     printf("\nTitulos dos livros que sao do Tipo %d :\n\n", x);
     while (temp != NULL)
     {
          if ((temp->esse).tipo == x)
          {
               printf("Titulo: %s\n", (temp->esse).titulo);
               Quant++;
          }
          temp = temp->prox;
     }
     return (Quant);
}

int main(int argc, char *argv[])
{
     lista L1;
     livro Book;
     int i, Quantidade, TamanhoL1, tipoLIVRO;
     srand(time(NULL));
     L1 = NULL; // Cria Lista L1
     printf("Tamanho da Lista de Livros - aleatorio entre 3 e 6 ...");
     printf("\n\nEntre com o Codigo(inteiro), o Tipo(inteiro) e o Titulo(string) para cada livro.");
     TamanhoL1 = rand() % 4 + 3; // Tamanho da Lista L1 entre 3 e 6
     for (i = 1; i <= TamanhoL1; i++)
     {
          printf("\n\n\nDados do %do livro a ser inserido na Lista:\n", i);
          printf("Codigo : ");
          scanf("%d", &Book.cod);
          printf("Tipo   : ");
          scanf("%d", &Book.tipo);
          fflush(stdin);
          printf("Titulo : ");
          gets(Book.titulo);
          InsereLista(&L1, Book);
     }
     printf("\n\nImpressao da Lista de Livros : \n");
     ImprimeLista(L1);
     printf("\n\nEntre com o tipo de livro a ser pesquisado : ");
     scanf("%d", &tipoLIVRO);
     Quantidade = RotQ3P1V1(L1, tipoLIVRO);
     printf("\nTotal de livros do Tipo %d = %d\n\n", tipoLIVRO, Quantidade);

     printf("\n\n\nPressione um tecla para TERMINAR o programa ...");
     getch();
     return 0;
}
