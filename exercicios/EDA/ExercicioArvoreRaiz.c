/*
 Objetivo: Criar Funções para a Arvore Binária.
 Entrada : Sem Entrada.
 Saida   : Arvore Binária.
 Aluno : Rafael Florentino.
*/
#define MININT -32768
#include <stdio.h>

typedef struct s_cel {
           float elem;
           struct s_cel *esq,*dir;
        } cel;
typedef cel* no;

int main()
{
    printf("Teste \n");
    return 0;
}

//Função que retorna a altura de uma árvore binária
int altura(no raiz){
   if (raiz == NULL) 
      return 0; // altura de árvore vazia é 0
   else {
      int hesq = altura( raiz->esq);
      int hdir = altura( raiz->dir);
      if (hesq < hdir) return hdir + 1;
      else             
      return hesq + 1;
   }
}

//Função que retorna o número de nós de uma árvore binária
int QuantNos(no raiz){
    if (raiz == NULL)    return 0;
    return  (QuantNos(raiz->esq) + QuantNos(raiz->dir) + 1);
}

//Função que retorna a soma dos elementos de uma árvore 
//passada como parâmetro;
int SomaArvore(no raiz) {
    if (raiz == NULL)    return 0;
    return  (raiz->elem + SomaArvore(raiz->esq) + SomaArvore(raiz->dir));
}
//Função que retorna o Maior dos elementos de uma árvore binária
int Maior(no raiz) {
    int Valor=MININT;   //Erro
    if  (raiz != NULL) {
         Valor = raiz->elem;
         int MaiorEsq = Maior(raiz->esq);
         if (Valor < MaiorEsq)
                Valor = MaiorEsq;  
         int MaiorDir = Maior(raiz->dir);
         if (Valor < MaiorDir)
                Valor = MaiorDir; 
    }
    return Valor;
}

//Função que recebe uma  árvore e um valor inteiro 
//- retorna o nó do elemento que possua tal valor inteiro, 
//caso exista na árvore;
no Pesquisa(no raiz, int X) {
    no Resul = NULL;
    if (X == raiz->elem) 
           return raiz;
    if (Resul = Pesquisa(raiz->esq,X) != NULL)
           return Resul;   
    if (Resul = Pesquisa(raiz->dir,X) != NULL)
           return Resul;  
    return Resul; 
}



