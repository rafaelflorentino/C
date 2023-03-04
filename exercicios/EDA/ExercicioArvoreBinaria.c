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
    if (Resp == 'S')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int vai_ter_filho_a_direita(float Elemento)
{
    char Resp;
    fflush(stdin);
    printf("\nDeseja filho a DIREITA de %d ? 'S' para Sim ou 'N' para Nao : ", Elemento);
    Resp = toupper(getchar());
    if (Resp == 'S')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Rotina le_arvore - Constrói árvore Binária NAO ORDENADA, via teclado
void le_arvore(no *raiz)
{
    *raiz = (no)malloc(sizeof(cel));
    (*raiz)->elem = le_conteudo();
    if (vai_ter_filho_a_esquerda((*raiz)->elem))
    {
        le_arvore(&((*raiz)->esq));
    }
    else
    {
        (*raiz)->esq = NULL;
    }
    if (vai_ter_filho_a_direita((*raiz)->elem))
    {
        le_arvore(&(*raiz)->dir);
    }
    else
    {
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
/*
// inserção na arvore
insere(arvore r, no *novo)
{
    if (r == NULL) // quando acha o campo vazio null, insere nessa posição
        return novo;
    if (r->chave > novo->chave)
        r->esq = insere(r->esq, novo);
    else
        r->dir = insere(r->dir, novo);
    return r;
}
// busca na arvore
busca(arvore r, int k)
{
    if (r == NULL || r->chave == k) // retorna nulo caso não ache o número
        return r;
    if (r->chave > k)
        return busca(r->esq, k);
    else
        return busca(r->dir, k);
}
// Remover o Elemento Raiz da Arvore
// Recebe uma árvore não vazia r.
// Remove a raiz da árvore e rearranja a árvore de modo que ela continue sendo
// de busca. Devolve o endereço da nova raiz.
removeraiz(arvore r)
{
    no *p, *q;
    if (r->esq == NULL)
    {
        q = r->dir;
        free(r);
        return q;
    }
    p = r;
    q = r->esq;
    while (q->dir != NULL)
    {
        p = q;
        q = q->dir;
    }
    // q é nó anterior a r na ordem e-r-d
    // p é pai de q
    if (p != r)
    {
        p->dir = q->esq;
        q->esq = r->esq;
    }
    q->dir = r->dir;
    free(r);
    return q;
}
// Travessia de Arvore
// em-ordem
    // Esquerda, Raiz, Direita
void ListarEmOrdem(PNodoArv T){
    if(T != null ){
        ListarEmOrdem(T-> Esquerda);
        printf(T -> Elemento);
        ListarEmOrdem(T-> Direita);
    }
}

// Pre-ordem
    // Raiz, Esquerda, Direita
void ListarPreOrdem(PNodoArv T){
    if(T != null ){
        printf(T -> Elemento);
        ListarPreOrdem(T-> Esquerda);
        ListarPreOrdem(T-> Direita);
    }
}
// Pós ordem
// Esquerda, Dierita Raiz
void ListarPosOrdem(PNodoArv T){
    if(T != null ){
        ListarPosOrdem(T-> Esquerda);
        ListarPosOrdem(T-> Direita);
        printf(T -> Elemento);
    }
}
*/

