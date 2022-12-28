/*
 Objetivo: Gerar uma lista encadeada ordenada de numeros reais.
 Entrada : Valores reais.
 Saida   : Todos os valores contidos na lista.
 Aluno : Rafael Florentino.
*/
/* Implemente em C uma rotina que insira um n˙mero (real, passado como
 parametro) numa lista encadeada simples garantindo que a lista continue
 sempre ordenada em ordem crescente. Faca um programa que cria uma lista,
 insira elementos na lista (usando a rotina acima pedida) e
 liste todos os elementos da lista.      */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
/* Typedefs ~ Estruturas */
typedef struct s_cel {
	float valor;
	struct s_cel *next;
}Celula;

typedef Celula* Lista;

/* Prototipos das funcoes */
void inicializaLista(Lista *pLista);
void addElem(Lista *pLista, float valor);
void apresentaLista(Lista lista);
void Finalizacao();

//Principal
int main()
{   /* Declaracoes */
    Lista lista;
    char resp;
    float valor;
    /* Instrucoes */
	inicializaLista(&lista);
	
	do
    {   printf("\n\nInforme o valor a ser adicionado: ");
		scanf("%f",&valor);
		addElem(&lista,valor);
		do
        {   printf("\nDeseja adicionar outro numero 'S' - 'N': ");
            scanf("%c",&resp);
			//resp = toupper(getche());
		} while (resp != 'S' &&  resp != 'N');
	} while (resp != 'N');
	
	apresentaLista(lista);
	
    Finalizacao();
    return 0;
}

/*
 * Sub Programa - Inicializa uma lista.
 *   Objetivo : Inicializar uma lista.
 *   Par‚metro: EndereÁo da lista.
 *   Retorno  : Nenhum.
 */
void inicializaLista(Lista *pLista)
{
	*pLista = NULL;
}

/*
 * Sub Programa - Adiciona Elemento
 *   Objetivo : Adiciona elementos de forma ordenada na lista.
 *   Par‚metro: EndereÁo inicial da lista, valor.
 *   Retorno  : Nenhum.
 */
void addElem(Lista *pLista, float x)
{
	Celula *temp = (Celula *) malloc(sizeof(Celula));
	Lista auxLista = (*pLista);
	
	temp->valor = x;
	//casos de inserir no inÌcio da lista
	if(((*pLista)==NULL)||((*pLista)->valor > x)) {
        temp->next = *pLista;
        *pLista = temp;
        return;
    }
	//inserir no meio ou no final da lista
	while ((auxLista->next != NULL) && (auxLista->next->valor < x)) {
        auxLista = auxLista->next;
	}
	temp->next = auxLista->next;
	auxLista->next = temp;
}

/*
 * Sub Programa - Apresenta Lista
 *   Objetivo : Apresenta Lista
 *   Parametro: Endereco da cabeca da lista.
 *   Retorno  : Nenhum.
 */
void apresentaLista(Lista lista)
{	printf("\n\nListagem dos componentes da Lista encadeada ORDENADA CRESCENTE:\n");
	if (lista != NULL) {
		while (lista != NULL)
		{
			printf("\nValor: %10.2f",lista->valor);
			lista = lista->next;
		}
    }
}

/*
 * Sub Programa - Finalizacao
 *   Objetivo : Finalizar o programa ao pressionar uma tecla
 *   Parametro: nenhum
 *   Retorno  : nenhum
 */
void Finalizacao()
{     printf("\n\nPressione uma TECLA para TERMINAR o programa ... ");
   // getch();
}
