/*
 Objetivo: Escreva um programa que receba duas pilhas p1 e p2 como entrada e que adicione o conteúdo de p1 em p2 respeitando a mesma ordem. Ou seja, ao final o topo de p2 será o mesmo topo de p1 na entrada.  P1 deve terminar a rotina exatamente como começou.
 Utilizar pilhas de inteiros. implementar os subprogramas (operações) necessários para o utilizar pilhas.
 Entrada : nome da lista, valore da lista.
 Saida   : Lista dos dados.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct s_cel
{
    int elem;
    struct s_cel *prox;
} Pilha;

int tamanhoPilha(Pilha* pilha) {
        Pilha* aux = pilha_cria();
        int contador = 0;
         while (!pilha_vazia(pilha)) {
             pilha_push(aux,pilha_pop(pilha));
             contador++;
         }    
          while(!pilha_vazia(aux))
             pilha_push(pilha,pilha_pop(aux)); 
         return contador;
}   

int main() {
    Pilha* p1 = pilha_cria();
    Pilha* p2 = pilha_cria() ;
    char c;
    for (c = 'a';c <= 'c'; c++)
        pilha_push(p1,c);
    printf("Pilha p1 eh igual a:\n");   
    pilha_imprime(p1);
    for (c = 'd';c <= 'f'; c++)
        pilha_push(p2,c); 
    printf("Pilha p2 eh igual a:\n");
    pilha_imprime(p2);
    printf("Pilha p1 e p2 sao iguais? Resposta = %d\n",iguais(p1,p2));
    concatena_pilhas(p1,p2);
    printf("Pilha p1 concatenada com p2 eh igual a:\n");   
    pilha_imprime(p1);
    
    printf("O tamanho da Pilha eh igual a: %d\n", tamanhoPilha(p1));   
    
    system("PAUSE");   
    return 1;
}            
