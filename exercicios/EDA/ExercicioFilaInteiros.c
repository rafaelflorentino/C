/*
 Objetivo: Implemente uma rotina que receba uma fila de inteiros e, ao final, nessa mesma fila os ímpares venham antes dos pares
 além da sua ordem estar invertida com relação á ordem na entrada. Faca um programa que utilize e valide  tal rotina.
 implementar os subprogramas (operações) necessários para o utilizar filas.
 Utilizar pilhas de inteiros. implementar os subprogramas (operações) necessários para o utilizar pilhas.
 Entrada : inteiros.
 Saida   : Lista dos dados.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_FILA 4 /* tamanho da fila */
#define SEMVALOR 0 /* erro p/ dequeue */

typedef struct cell
{
    int dados[MAX_FILA];
    int inicio, final;
} estruturaFila;

void inicializa(estruturaFila *F);
bool cheia(estruturaFila F);
bool vazia(estruturaFila F);
void enqueue(estruturaFila *F, int x);
int dequeue(estruturaFila *F);

int main()
{
    estruturaFila *fila;
    int numero;
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("Insira um numero: ");
        scanf("%d", &numero);
        fflush(stdin);
        enqueue(fila, numero);
    }
    // for (i=0; i<3; i++){
    printf("elemento da lista: %d\n", dequeue(fila));
    //}
    system("pause");
}
// Operação inicializa:
void inicializa(estruturaFila *F)
{
    F->inicio = 0;
    F->final = 0;
}
// Operação cheia:
bool cheia(estruturaFila F)
{
    return (F.final > MAX_FILA);
}
// Operação enqueue:
void enqueue(estruturaFila *F, int x)
{
    if (!cheia(*F))
    {
        F->dados[F->final] = x;
        F->final++;
    }
}
// Operação vazia:
bool vazia(estruturaFila F)
{
    return (F.inicio == F.final);
}
// Operação dequeue:
int dequeue(estruturaFila *F)
{
    if (!vazia(*F))
    {
        F->inicio++;
        return (F->dados[F->inicio - 1]);
    }
    else
        return (SEMVALOR);
}
