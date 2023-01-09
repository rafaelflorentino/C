/*
 Objetivo: Faça um programa que cria uma lista encadeada  de números inteiros.
 Entrada : Valores inteiros.
 Saida   : Todos os valores contidos na lista.
 Aluno : Rafael Florentino.
*/

#include <stdio.h>
// Estrutura e Typedef
typedef struct s_cel
{
    int val;
    struct s_cel *prox;
} cel;
typedef cel *lista;

void inicializarLista(lista *L)
{
    *L = NULL;
}

int vazia(lista L)
{
    return (L == NULL);
}

void addElemTopo(lista *L, int x)
{
    cel *tmp;
    tmp = (cel *)malloc(sizeof(cel)); /*1-criar uma nova cel */
    tmp->val = x;                     /*2-armazenar o valor do elemento*/
    tmp->prox = *L;                   /*3- apontando p/ lista*/
    (*L) = tmp;                       /*4-elemento é o novo primeiro*/
}

void addElemCauda(lista *L, int x)
{
    cel *tmp;
    lista aux;
    tmp = (cel *)malloc(sizeof(cel)); /*1-criar uma nova cel */
    tmp->val = x;                     /*2-armazenar o valor do elemento*/
    tmp->prox = NULL;                 /*3- aponta para NULL (último da nova lista)*/
    if (vazia(*L))                    /*caso de lista vazia */
        *L = tmp;
    else
    {
        aux = *L;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = tmp;
    }
}

void delElemTopo(lista *L)
{
    cel *tmp;
    if (!vazia(*L))
    {
        tmp = *L;         /*1-salvar endereço do 1o     */
        (*L) = tmp->prox; /*2-L aponta p/ resto da lista*/
        free(tmp);        /*3-liberar a memória         */
    }
}

void delElemCauda(lista *L)
{
    cel *tmp;
    if (!vazia(*L))
    {
        tmp = *L;              /*1-salvar endereço do 1o     */
        if (tmp->prox == NULL) // Lista tem só um elemento
        {
            *L == NULL;
            free(tmp);
            return;
        }
        while (tmp->prox->prox != NULL) // Lista com 2 ou mais elementos
            tmp = tmp->prox;
        free(tmp->prox);
        tmp->prox = NULL;
    }
}

void ListarElementos(lista L)
{
    printf("\n\nListagem dos componentes da Lista Encadeada :\n");
    if (!vazia(L))
    {
        while (L != NULL)
        {
            printf("Valor: %d\n", L->val);
            L = L->prox;
        }
    }
}

void Finalizacao()
{
    printf("\n\nPressione uma TECLA para TERMINAR o programa ... ");
    getch();
}

// Principal
int main()
{
    int N, opcao;
    lista L;
    inicializarLista(&L);
    do
    {
        printf("\nMenu de opcoes");
        printf("\n------------------");
        printf("\n1 - Inserir numero Inteiro no Topo da Lista Encadeada");
        printf("\n2 - Inserir numero Inteiro na Cauda da Lista Encadeada");
        printf("\n3 - Retirar numero do Topo da Lista Encadeada");
        printf("\n4 - Retirar numero da Cauda da Lista Encadeada");
        printf("\n5 - Listar numeros da Lista Encadeada");
        printf("\n6 - Sair");
        printf("\n------------------");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\n\nInforme o valor a ser ADICIONADO no Topo da Lista: ");
            scanf("%d", &N);
            addElemTopo(&L, N);
            break;
        case 2:
            printf("\n\nInforme o valor a ser ADICIONADO na Cauda da Lista: ");
            scanf("%d", &N);
            addElemCauda(&L, N);
            break;
        case 3:
            delElemTopo(&L);
            break;
        case 4:
            delElemCauda(&L);
            break;
        case 5:
            ListarElementos(L);
        }
    } while (opcao != 6);
    Finalizacao();
    return 0;
}
