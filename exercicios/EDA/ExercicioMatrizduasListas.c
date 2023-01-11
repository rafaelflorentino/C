/*
 Objetivo: Duas Listas e uma Matriz Gerada com os PARES de aleatorios entre 0 e 9.
 Entrada : Sem entrada.
 Saida   : Lista 1, Lista 2 e matriz.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>

typedef struct
{
     int x;
     int y;
} Par;

typedef struct No
{
     int dado;
     struct No *prox;
} cel;

typedef cel *lista;

void InsereLista(lista *L, int valor)
{
     cel *temp;
     temp = (cel *)malloc(sizeof(cel));
     temp->dado = valor;
     temp->prox = *L;
     *L = temp;
}

void ImprimeLista(lista L)
{
     cel *temp = L;
     int Quant = 0;
     while (temp != NULL)
     {
          printf("%5d", temp->dado);
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

Par **criaMatriz(lista l1, lista l2)
{

     Par **resp;
     int i, j, Q_Lin = 0, Q_Col = 0;
     cel *temp1, *temp2;
     // Quantidade de elementos da lista 1 (quantidade de linhas da matriz)
     temp1 = l1;
     while (temp1 != NULL)
     {
          Q_Lin++;
          temp1 = temp1->prox;
     }
     // Quantidade de elementos da lista 2 (quantidade de colunas da matriz)
     temp2 = l2;
     while (temp2 != NULL)
     {
          Q_Col++;
          temp2 = temp2->prox;
     }
     // alocações para a matriz
     resp = (Par **)malloc(sizeof(Par *) * Q_Lin);
     for (i = 0; i < Q_Lin; i++)
          resp[i] = (Par *)malloc(sizeof(Par) * Q_Col);
     // construção da matriz
     temp1 = l1;
     for (i = 0; i < Q_Lin; i++)
     {
          temp2 = l2;
          for (j = 0; j < Q_Col; j++)
          {
               (resp[i][j]).x = temp1->dado;
               (resp[i][j]).y = temp2->dado;
               temp2 = temp2->prox;
          }
          temp1 = temp1->prox;
     }
     return resp;
}

int main(int argc, char *argv[])
{
     Par **mat;
     lista L1, L2;
     int i, j, Lin, Col, TamanhoL1, TamanhoL2;
     srand(time(NULL));
     L1 = NULL; // Cria Lista L1
     printf("Os inteiros a serem inseridos nas listas serao aleatorios entre 0 e 9 ...");
     printf("\n\nTamanho da 1a Lista ---> tamanho aleatorio entre 1 e 9");
     TamanhoL1 = rand() % 9 + 1; // Tamanho da 1 Lista entre 1 e 9
     for (i = 1; i <= TamanhoL1; i++)
          InsereLista(&L1, rand() % 10);
     L2 = NULL; // Cria Lista L2
     printf("\n\nTamanho da 2a Lista ---> tamanho aleatorio entre 1 e 6");
     TamanhoL2 = rand() % 6 + 1; // Tamanho da 2 Lista entre 1 e 6
     for (i = 1; i <= TamanhoL2; i++)
          InsereLista(&L2, rand() % 10);
     printf("\n\n\n\nListagem da 1a Lista : \n");
     ImprimeLista(L1);
     printf("\n\nListagem da 2a Lista : \n");
     ImprimeLista(L2);
     mat = criaMatriz(L1, L2);
     Lin = TamanhoLista(L1);
     Col = TamanhoLista(L2);
     printf("\n\nMatriz Gerada com os PARES de aleatorios entre 0 e 9 : \n");
     for (i = 0; i < Lin; i++)
     {
          printf("\n\n");
          for (j = 0; j < Col; j++)
               printf("(%d , %d)      ", (mat[i][j]).x, (mat[i][j]).y);
     }

     printf("\n\n\nPressione um tecla para TERMINAR o programa ...");
     getch();
     return 0;
}
