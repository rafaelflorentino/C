/*
 Objetivo: Criar Funções para a Arvore Binária.
 Entrada : Sem Entrada.
 Saida   : Arvore Binária.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
typedef struct s_cel
{
    float elem;
    struct s_cel *esq, *dir;
} cel;
typedef cel *no;

int le_conteudo()
{
    float Nr;
    printf("\nEntre com um numero real : ");
    scanf("%f", &Nr);
    return Nr;
}

int vai_ter_filho_a_esquerda(float Elemento)
{
    char Resp;
    fflush(stdin);
    printf("\nDeseja filho a ESQUERDA de %d ? 'S' para Sim ou 'N' para Nao : ", Elemento);
    Resp = toupper(getchar());
    if (Resp == 'S'){
        return 1;
    }else{
        return 0;
    }
}

int vai_ter_filho_a_direita(float Elemento)
{
    char Resp;
    fflush(stdin);
    printf("\nDeseja filho a DIREITA de %d ? 'S' para Sim ou 'N' para Nao : ", Elemento);
    Resp = toupper(getchar());
    if (Resp == 'S'){
        return 1;
    }else{
        return 0;
    }
}

// Rotina le_arvore - Constrói árvore Binária NAO ORDENADA, via teclado
void le_arvore(no *raiz)
{
    *raiz = (no)malloc(sizeof(cel));
    (*raiz)->elem = le_conteudo();
    if (vai_ter_filho_a_esquerda((*raiz)->elem)){
        le_arvore(&((*raiz)->esq));
    }else{
        (*raiz)->esq = NULL;
    }if (vai_ter_filho_a_direita((*raiz)->elem)){
        le_arvore(&(*raiz)->dir);
    }else{
        (*raiz)->dir = NULL;
    }
}

void preordem(no r)
{
    if (r != NULL)
    {
        printf("%d   ", r->elem);
        preordem(r->esq);
        preordem(r->dir);
    }
}

int main()
{
    no arv = NULL;
    printf("Construcao de uma ARVORE Binaria, a partir de sua RAIZ:\n\n");
    le_arvore(&arv);
    printf("\n\nConstrucao Finalizada da ARVORE Binaria ...\n");

    printf("\n\n\nAtravessamento PRE-ORDEM :\n\n");
    preordem(arv);

    puts("\n\n");
    system("PAUSE");
    return 0;
}
