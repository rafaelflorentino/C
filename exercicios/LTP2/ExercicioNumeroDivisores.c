/*
 Objetivo : Escreva um programa em C que receba números inteiros e mostre os seus divisores.
 Entrada : Números.
 Saida : Lista dos divisores do número.
 Aluno: Rafael Florentino.
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void ListaDivisores(int N);

int main(){
    int i, quant, N, n, aux;
    
    printf("\nDigite quantos Valores inteiros deseja ler: "); 
    scanf("%d",&quant);
    system("cls");

    for(i=0; i < quant; i++){
        printf("Digite um numero inteiro:\n");
        scanf("%d",&N);
        fflush(stdin);
        ListaDivisores(N);

        printf("\n\nDigite qualquer tecla para continuar...");
        getch();
        system("cls");
    }
    return 0;   
}
      
void ListaDivisores(int N){
    int aux, atual;

    atual = N;
    printf("\nDivisores de %d:\n", N);
    for (aux = 1; aux <= N; aux++) {
        if (N % atual == 0) {
            printf("%d\n", atual);
        }
        atual--;
    }
}
