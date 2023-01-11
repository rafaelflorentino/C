/*
 Objetivo: Rotina de receba uma fila de livros e que altere a sua ordem de forma que os
 tipos pares venham antes dos ímpares, sendo que entre pares e ímpares a ordem deve ficar
 inalterada. Implemente a rotina utilizando somente as chamadas típicas de fila (enqueue
 e dequeue) sem implementá-las. Se necessário use filas ou pilhas temporárias.
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
typedef struct
{
        cel *inicio, *final;
} fila;

livro SEMVALOR = {0, 0, "************** FILA VAZIA ***************"};

void inicializa(fila *F)
{
        F->inicio = NULL;
        F->final = NULL;
}

int vazia(fila F)
{
        return (F.inicio == NULL);
}

void enqueue(fila *F, livro novo)
{
        cel *temp;
        temp = (cel *)malloc(sizeof(cel));
        temp->prox = NULL;
        temp->esse = novo;
        if (vazia(*F))
        { /* inicio==final==NULL */
                F->inicio = temp;
                F->final = temp;
        }
        else
        {
                F->final->prox = temp;
                F->final = temp;
        }
}

livro dequeue(fila *F)
{
        cel *temp;
        livro retorno;
        if (vazia(*F))
                retorno = SEMVALOR;
        else
        {
                temp = F->inicio->prox;
                retorno = F->inicio->esse;
                free(F->inicio);
                F->inicio = temp;
                if (F->inicio == NULL)
                        F->final = NULL;
        }
        return (retorno);
}

void ImprimeFila(fila *F)
{
        fila Aux;
        livro Book;
        int Quantidade = 0;
        inicializa(&Aux);
        printf("\nINICIO da FILA");
        while (!(vazia(*F))) // uso de Fila Aux
        {
                Book = dequeue(F);
                enqueue(&Aux, Book);
                printf("\nCod=%5d\tTipo=%5d\tTitulo: %s\n", Book.cod, Book.tipo, Book.titulo);
                Quantidade++;
        }
        printf("FINAL da FILA\n");
        printf("\nTotal de elementos da Fila = %d\n\n", Quantidade);
        // restaurar fila original
        while (!(vazia(Aux)))
                enqueue(F, dequeue(&Aux));
}

void RotQ6P1V1(fila *F)
{
        fila FPar, FImpar; // uso de duas Filas Auxiliares, para Pares e para ímpares
        livro Book;
        inicializa(&FPar);
        inicializa(&FImpar);
        while (!(vazia(*F)))
        {
                Book = dequeue(F);
                if (Book.tipo % 2 == 0)
                        enqueue(&FPar, Book);
                else
                        enqueue(&FImpar, Book);
        }
        while (!(vazia(FPar))) // retorna os pares para a fila F
                enqueue(F, dequeue(&FPar));
        while (!(vazia(FImpar))) // retorna os ímpares para a fila F
                enqueue(F, dequeue(&FImpar));
}

int main(int argc, char *argv[])
{
        fila F1;
        int i, TamanhoF1, tipoLIVRO;
        livro Book;
        srand(time(NULL));
        inicializa(&F1); // Cria Fila F1 vazia
        printf("Tamanho da Fila de Livros - aleatorio entre 3 e 6 ...");
        printf("\n\nEntre com o Codigo(inteiro), o Tipo(inteiro) e o Titulo(string) para cada livro.");
        TamanhoF1 = rand() % 4 + 3; // Tamanho da Fila F1 entre 3 e 6
        for (i = 1; i <= TamanhoF1; i++)
        {
                printf("\n\n\nDados do %do livro a ser inserido na Fila:\n", i);
                printf("Codigo : ");
                scanf("%d", &Book.cod);
                printf("Tipo   : ");
                scanf("%d", &Book.tipo);
                fflush(stdin);
                printf("Titulo : ");
                gets(Book.titulo);
                enqueue(&F1, Book);
        }
        printf("\n\nImpressao da Fila de Livros : \n");
        ImprimeFila(&F1);
        printf("\n\n\nNova Impressao da mesma Fila de Livros : \n");
        ImprimeFila(&F1);
        RotQ6P1V1(&F1); // uso da rotina solicitada na Questão 6
        printf("\n\n\nImpressao da Fila alterada, com tipos pares antes dos impares : \n");
        ImprimeFila(&F1);

        printf("\n\n\nPressione um tecla para TERMINAR o programa ...");
        getch();
        return 0;
}
