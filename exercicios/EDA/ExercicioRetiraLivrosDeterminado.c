/*
 Objetivo: Escreva uma rotina em C que receba uma pilha de livros e um inteiro x e que retire
 da pilha todos os livros do tipo x. Para cada livro retirado da pilha mostre seu
 título na tela. Implemente a rotina utilizando somente as chamadas tópicas de
 pilha (push, pop e top), utilizando pilhas temporárias se necessário. Note que os
 livros restantes na pilha devem estar na mesma ordem de entrada.
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
typedef cel *pilha;

void push(pilha *P, livro novo)
{
     cel *temp;
     temp = (cel *)malloc(sizeof(cel));
     temp->esse = novo;
     temp->prox = *P;
     *P = temp;
}

livro pop(pilha *P)
{
     cel *temp = *P;
     livro topo = temp->esse;
     *P = temp->prox;
     free(temp);
     return topo;
}

livro top(pilha P)
{
     livro topo = P->esse;
     return topo;
}

void ImprimePilha(pilha *P)
{
     pilha Aux = NULL;
     livro Book;
     int Quantidade = 0;
     while (*P != NULL) // uso de pilha Aux
     {
          Book = pop(P);
          push(&Aux, Book);
          printf("\nCod=%5d\tTipo=%5d\tTitulo: %s\n", Book.cod, Book.tipo, Book.titulo);
          Quantidade++;
     }
     printf("\nTotal de elementos da Pilha = %d\n\n", Quantidade);
     // restaurar pilha original
     while (Aux != NULL)
          push(P, pop(&Aux));
}
/**** Rotina solicitada na Questão 5 *****************/
void RotQ5P1V1(pilha *P, int x)
{
     pilha Aux = NULL;
     livro Book;
     printf("\n\nTitulos dos livros que sao do Tipo %d :\n\n", x);
     while (*P != NULL) // uso de pilha Aux
     {
          Book = pop(P);
          if (Book.tipo == x)
               printf("\nTitulo: %s\n", Book.titulo);
          else
               push(&Aux, Book);
     }
     // restaurar pilha original
     while (Aux != NULL)
          push(P, pop(&Aux));
}

int main(int argc, char *argv[])
{
     pilha P1;
     int i, TamanhoP1, tipoLIVRO;
     livro Book;
     srand(time(NULL));
     P1 = NULL; // Cria Pilha P1 vazia
     printf("Tamanho da Pilha de Livros - aleatorio entre 3 e 6 ...");
     printf("\n\nEntre com o Codigo(inteiro), o Tipo(inteiro) e o Titulo(string) para cada livro.");
     TamanhoP1 = rand() % 4 + 3; // Tamanho da Pilha P1 entre 3 e 6
     for (i = 1; i <= TamanhoP1; i++)
     {
          printf("\n\n\nDados do %do livro a ser inserido na Pilha:\n", i);
          printf("Codigo : ");
          scanf("%d", &Book.cod);
          printf("Tipo   : ");
          scanf("%d", &Book.tipo);
          fflush(stdin);
          printf("Titulo : ");
          gets(Book.titulo);
          push(&P1, Book);
     }
     printf("\n\nImpressao da Pilha de Livros : \n");
     ImprimePilha(&P1);
     printf("\n\nEntre com o TIPO de livro a ser pesquisado e retirado da Pilha : ");
     scanf("%d", &tipoLIVRO);
     RotQ5P1V1(&P1, tipoLIVRO); // Rotina que lista livros do tipo escolhido e os retira da pilha
     printf("\n\n\nPilha com os livos TIPO %d retirados : \n", tipoLIVRO);
     ImprimePilha(&P1);

     printf("\n\n\nPressione um tecla para TERMINAR o programa ...");
     getch();
     return 0;
}
