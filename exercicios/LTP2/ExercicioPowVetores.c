/*
 Objetivo : Escreva um programa em C que gere 20 numeros aleatorios e  eleve a quinta potência.
 Entrada : Sem Entrada.
 Saida : Números elevados a quinta potência.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int V[20],A[20],I;
    
    srand(time(NULL));
    printf("\n\tNumeros Elevados a Quinta Potencia: \n\n");
    for(I = 0; I < 20; I ++){        
        V[I] = (rand() % 46 - 15);         
        A[I]= pow(V[I],5);//V[I]*V[I]* V[I]* V[I]* V[I];
        printf("\n\tV[%2d] = %d  \tV[%2d] = %2d",I,V[I],I,A[I]);                      
    }     
    return 0; 
}
