/*
 Objetivo: Considerando que precisamos de uma pilha de dados do tipo "livro" (ver typedef abaixo),
 implemente as rotinas de push e pop, cujas interfaces são definidas abaixo. Push insere
 um dado de tipo livro no topo da pilha e pop retira um livro do topo da pilha. A pilha
 deve ser construída usando uma lista encadeada simples cujas células são do tipo "cel".
 typedef cel* pilha;
 void push(pilha *P, livro novo);
 livro pop(pilha *P);

 Entrada : Código, titulo, tipo.
 Saida   : lista encadeada simples.
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

/*** Rotina   push   solicitada na Questãoo 4  *******/
void push(pilha *P, livro novo)
{
     cel *temp;
     temp = (cel *)malloc(sizeof(cel));
     temp->esse = novo;
     temp->prox = *P;
     *P = temp;
}

/*** Rotina   pop   solicitada na Questão 4  *******/
livro pop(pilha *P)
{
     cel *temp = *P;
     livro topo = temp->esse;
     *P = temp->prox;
     free(temp);
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

int main(int argc, char *argv[])
{
     pilha P1;
     int i, TamanhoP1;
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
     printf("\n\nNova Impressao da Pilha de Livros : \n");
     ImprimePilha(&P1);

     printf("\n\n\nPressione um tecla para TERMINAR o programa ...");
     getch();
     return 0;
}
