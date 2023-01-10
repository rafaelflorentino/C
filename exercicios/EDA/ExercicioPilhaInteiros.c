/*
 Objetivo: Escrever um programa que gere um pilha de inteiros, valores fornecidos pelo usuário. Em seguida, o programa deve ler
 os numeros inteiros da pilha e os escrever em ordem inversa. A pilha gerada nao deve ser destruida ao final do programa.
 Entrada : nome da lista, valore da lista.
 Saida   : Lista dos dados.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#define SEMVALOR 0

typedef struct s_cel
{
    int elem;
    struct s_cel *prox;
} cel;

void inicializa(cel *p);
void ppush(cel *p, int numero);
bool vazia(cel *p);
int pop(cel *p);

int main()
{
    int numero, i;
    cel *pilha;
    // pilha = (cel *) malloc(sizeof(cel));

    cel *novo;

    // inicializa(pilha);
    pilha = NULL;

    // carrega a pilha com os valores
    for (i = 0; i < 3; i++)
    {
        printf("Informe o valor a ser colocado: ");
        scanf("%d", &numero);
        fflush(stdin);
        // ppush(pilha, numero);
        novo = (cel *)malloc(sizeof(cel));
        novo->elem = numero;
        novo->prox = pilha;
        pilha = novo;
    }
    // exibe os dados da pilha
    for (i = 0; i < 5; i++)
    {
        if (!vazia(pilha))
        {
            // printf("elemento %d = %d\n",i, pop(pilha));
            printf("elemento %d = %d\n", i, pilha->elem);
            pilha = pilha->prox;
        }
    }
    system("pause");
}
// Operacao inicializao:
void inicializa(cel *p)
{
    p = NULL;
}
// empilha a lista
void ppush(cel *p, int numero)
{
    cel *novo;
    novo = (cel *)malloc(sizeof(cel));
    novo->elem = numero;
    novo->prox = p;
    p = novo;
}

bool vazia(cel *p)
{
    return (p == NULL);
}

int pop(cel *p)
{
    cel *tmp;
    int ret = 0;
    // tmp = (cel *) malloc(sizeof(cel));
    if (!vazia(p))
    {
        ret = p->elem;
        tmp = p;
        p = p->prox;
        free(tmp);
        return ret;
    }
    else
        return (SEMVALOR);
}
