/*
 Objetivo: Escrever um programa que receba crie uma Lista Duplamente encadeada
 Entrada : Codigo, Número.
 Saida   : lista.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Tipo_Lista{
    int cod;
    struct Tipo_Lista *Prox;
    struct Tipo_Lista *Ant;
};

struct Tipo_Lista *Primeiro;
struct Tipo_Lista *Ultimo;

void FLVazia(){
    
    struct Tipo_Lista *aux;
    aux = (struct Tipo_Lista *)malloc(sizeof(struct Tipo_Lista));
    Primeiro =aux;
    Ultimo=Primeiro;
    Primeiro->Ant=NULL;
}
int Insere(int x){
    struct Tipo_Lista *aux;
    aux = (struct Tipo_Lista *)malloc(sizeof(struct Tipo_Lista));
    aux->cod=x;
    Ultimo->Prox=aux;
    aux->Ant=Ultimo;
    Ultimo=Ultimo->Prox;
    aux->Prox=NULL;
}
void Imprime(){
    struct Tipo_Lista *aux;
    aux=Primeiro->Prox;
    
    while (aux!=NULL) {
        printf("\nitem = %d",aux->cod);
        aux=aux->Prox;
    }
}
void Imprime_Atraz(){
    struct Tipo_Lista *aux;
    aux=Ultimo;
    
    while (aux->Ant!=NULL) {
        printf("\nitem = %d",aux->cod);
        aux=aux->Ant;
    }
}
int Pesquisa(int x){
    int flag=0,continuar;
    struct Tipo_Lista *aux;
    aux=Primeiro->Prox;
    
    while (aux!=NULL) {
        if(aux->cod==x){
            printf("ACHOU o item: %d !!",x);
            aux=NULL;
            flag=1;
            printf("\nDeseja remover o item encontrado SIM(1) NAO outro valor: ");
            scanf("%d",&continuar);
            if (continuar==1) {
                Remove(x);
                Imprime();
            }
            
        }
        else{
            aux=aux->Prox;
        }
    }
    if (flag==0) {
        printf("O item: %d  nao se encontra na lista",x);
        
    }
    
}
int Remove(int x){
    struct Tipo_Lista *aux;
    int flag=0;
    
    aux=Primeiro->Prox;
    
    while (aux!=NULL) {
        if(aux->cod==x){
            if(aux->Prox==NULL){
                Ultimo=aux->Ant;
                aux->Ant->Prox=NULL;
                aux=NULL;
                flag=1;
            }
            else{
            printf("\nREMOVEU o item: %d !!",x);
            aux->Ant->Prox=aux->Prox;
            aux->Prox->Ant=aux->Ant;
            aux=NULL;
            flag=1;
            }
        }
        else{
            aux=aux->Prox;
        }
    }
    free(aux);
    if (flag==0) {
        printf(" o item: %d  nao se encontra na lista",x);   
    }   
}

int main()
{
    int codigo,continuar=1;
    float numero;
    FLVazia();
    while (continuar==1) {
        printf("\nDigite o codigo: ");
        scanf("%d",&codigo);
        Insere(codigo);
        printf("\nDeseja continuar com o cadastro SIM digite (1) Nao digite outro valor: ");
        scanf("%d",&continuar);
    }
    Imprime();

    printf("\n\nImprime atraz");
    Imprime_Atraz();

    printf("\nEntre com um item para pesquisa: ");
    scanf("%d",&codigo);
    Pesquisa(codigo);

    printf("\nDigite o numero que dejesa remover : ");
    scanf("%d",&codigo);
    Remove(codigo);

    Imprime();
}
    
    