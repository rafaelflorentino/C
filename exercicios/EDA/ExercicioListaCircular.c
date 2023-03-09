/*
 Objetivo: Faça um programa para criar e utilizar uma lista encadeada circular
 Entrada : Dado.
 Saida   : Lista dos dados.
 Aluno : Rafael Florentino.
*/
#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
// Lista encadeada circular o último ponterio aponta para o primeiro e o primeiro aponta para o último.     
struct tElemento { 
        int info; 
        struct tElemento *prox; 
};

char tela(); 
struct tElemento *cria_no(); 
void insere (struct tElemento *, int ); 
void meu_remove (struct tElemento *, int); 
void listar(struct tElemento *);

void main() 
{ 
    struct tElemento *ptlista; 
    char linha[80]; 
    char opcao; 
    int sair = 0, valor;

    ptlista = cria_no(); 
    ptlista->prox=ptlista; 
 
    do { 
           opcao = tela(); 
           switch (opcao) { 
                  case 'i': 
                       puts("Qual dado a inserir?"); gets(linha); 
                       sscanf(linha, "%d", &valor); 
                       insere(ptlista, valor); 
                       break; 
                  case 'r': 
                       puts("Qual dado a remover?"); gets(linha); 
                       sscanf(linha, "%d", &valor); 
                       meu_remove(ptlista, valor); 
                       break; 
                  case 'l': 
                       listar(ptlista); 
                       break; 
                  case 's': 
                       sair = 1; 
                       break; 
                  default: 
                          puts("Opcao invalida."); 
                          break; 
           } 
    } while (!sair); 
} 
 
char tela () {

     char opcao, linha[80];

     puts("Qual a sua opcao?"); 
     puts("[L]istar, [I]nserir, [R]emover, [S]air"); 
     gets(linha); 
     sscanf(linha, "%c", &opcao); 
     return tolower(opcao); 
} 

void listar (struct tElemento *ptlista) {

     int i=0; 
     struct tElemento *pont;

     pont = ptlista->prox; 
     while (pont != ptlista) { 
           printf("Elemento %d = %d\n", i++, pont->info); 
           pont = pont->prox; 
     } 
} 
void insere (struct tElemento *ptlista, int valor) {

     struct tElemento *pont, *ant, *pt;
/* Aqui esta o algoritmo de busca em uma lista circular */

   ant = ptlista; pont = ptlista->prox; 
    ptlista->info = valor;

    while (pont->info < valor) { 
             ant = pont; 
             pont = pont->prox; 
    }

    if (pont->info == valor && pont != ptlista) 
       puts("Elemento ja existe na tabela."); 
    else { 
         pt = cria_no(); 
         pt->info = valor; 
         pt->prox = pont; 
         ant->prox = pt; 
     } 
}

void meu_remove (struct tElemento *ptlista, int valor) { 
     struct tElemento *pont, *ant;

    ant = ptlista; pont = ptlista->prox; 
    ptlista->info = valor;

    while (pont->info < valor) { 
          if (pont->info < valor) { 
             ant = pont; 
             pont = pont->prox; 
          } 
    }

    if (pont->info == valor && pont != ptlista) { 
       ant->prox = pont->prox; 
       free(pont); 
    } 
    else puts("Elemento nao existe na tabela."); 
}

struct tElemento *cria_no() {

       struct tElemento *pt;

       if (( pt = (struct tElemento *) malloc(sizeof(struct tElemento)) ) == NULL ) 
       { 
            puts("Nao ha espaco."); 
            exit(1); 
       } 
       pt->info = -1; 
       pt->prox = NULL; 
       return pt; 
}
