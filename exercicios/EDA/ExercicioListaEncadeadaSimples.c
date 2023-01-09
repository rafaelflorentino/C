/*
 Objetivo: Faça um programa que cria uma lista encadeada simples de números reais, ordenada de modo crescente.
 Usar rotina para a criação da lista. Insira elementos na lista.
 Crie também uma rotina para retirar um número (real passado como parâmetro), caso exista na lista. Crie outra
 rotina para listar todos os elementos da lista. Crie um menu com as opções para Criar, Inserir Elemento,
 Retirar Elemento e Listar todos os Elementos da Lista.
 Entrada : Valores reais, opção do menu.
 Saida   : Menu, adicionar valor, remover valor, exibir todos os valores contidos na lista.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
/* Typedefs e Estruturas */
typedef struct s_cel
{
    float valor;
    struct s_cel *next;
} Celula;

typedef Celula *Lista;

/* Protótipos das funções */
void inicializaLista(Lista *pLista);
void addElem(Lista *pLista, float valor);
int removeItemLista(Lista *lista, float x);
void apresentaLista(Lista lista);
void Finalizacao();

// Principal
int main()
{ 
    Lista lista;
    int opcao;
    float valor;
    
    inicializaLista(&lista);
    do
    {
        printf("\nMenu de opcoes");
        printf("\n------------------");
        printf("\n1 - Inserir numero Real na Lista Encadeada");
        printf("\n2 - Retirar numero da Lista Encadeada");
        printf("\n3 - Listar numeros da Lista Encadeada ORDENADA");
        printf("\n4 - Sair");
        printf("\n------------------");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
        {
            printf("\n\nInforme o valor a ser ADICIONADO na Lista: ");
            scanf("%f", &valor);
            addElem(&lista, valor);
            break;
        }
        case 2:
        {
            printf("\n\nInforme o valor a ser RETIRADO da Lista: ");
            scanf("%f", &valor);
            removeItemLista(&lista, valor);
            break;
        }
        case 3:
        {
            apresentaLista(lista);
            break;
        }
        }
    } while (opcao != 4);
    Finalizacao();
    return 0;
}

/*
* Sub Programa - Remover Item Lista
*   Objetivo : Remover um item da lista.
*   Parâmetro: Endereço inicial da lista,
               Valor do item a ser removido.
*   Retorno  : Quantidade de itens removidos.
*/
int removeItemLista(Lista *lista, float x)
{
    Lista auxLista = (*lista);
    Celula *auxCelula;

    if (*lista != NULL)
    { // caso de retirar 1º elemento da lista ...
        if (auxLista->valor == x)
        {
            if (auxLista->next != NULL)
                (*lista) = auxLista->next;
            else
                (*lista) = NULL;
            free(auxLista);
            return 1;
        }
        // pesquisar elemento - caso  exista ficará apontado por auxLista
        while (1)
        {
            auxCelula = auxLista;
            auxLista = auxLista->next;
            if (auxLista == NULL)
            { // não encontrado o valor
                printf("\n%.2f NAO encontrado na Lista ...\n", x);
                return 0;
            }
            if (auxLista->valor == x)
                break;
        }
        // valor encontrado - retirar da lista
        auxCelula->next = auxLista->next;
        free(auxLista);
        return 1;
    }
    printf("\nLista VAZIA - %.2f NAO encontrado na Lista ...\n", x);
    return 0; // caso de lista vazia
}
/*
 * Sub Programa - Apresenta Lista
 *   Objetivo : Apresenta Lista
 *   Parâmetro: Endereço da cabeça da lista.
 *   Retorno  : Nenhum.
 */
void apresentaLista(Lista lista)
{
    printf("\n\nListagem dos componentes da Lista encadeada:\n");
    if (lista == NULL)
        printf("\n\nLista Vazia:\n");

    while (lista != NULL)
    {
        printf("\nValor: %10.2f", lista->valor);
        lista = lista->next;
    }
}

/*
 * Sub Programa - Inicializa uma lista.
 *   Objetivo : Inicializar uma lista.
 *   Parâmetro: Endereço da lista.
 *   Retorno  : Nenhum.
 */
void inicializaLista(Lista *pLista)
{
    *pLista = NULL;
}

/*
 * Sub Programa - Adiciona Elemento
 *   Objetivo : Adiciona elementos de forma ordenada na lista.
 *   Parâmetro: Endereço inicial da lista, valor.
 *   Retorno  : Nenhum.
 */
void addElem(Lista *pLista, float x)
{
    Celula *temp = (Celula *)malloc(sizeof(Celula));
    Lista auxLista = (*pLista);

    temp->valor = x;
    // casos de inserir no início da lista
    if (((*pLista) == NULL) || ((*pLista)->valor > x))
    {
        temp->next = *pLista;
        *pLista = temp;
        return;
    }
    // inserir no meio ou no final da lista
    while ((auxLista->next != NULL) && (auxLista->next->valor < x))
    {
        auxLista = auxLista->next;
    }
    temp->next = auxLista->next;
    auxLista->next = temp;
}

/*
 * Sub Programa - Finalizacao
 *   Objetivo : Finalizar o programa ao pressionar uma tecla
 *   Parâmetro: nenhum
 *   Retorno  : nenhum
 */
void Finalizacao()
{
    printf("\n\nPressione uma TECLA para TERMINAR o programa ... ");
    getch();
}
