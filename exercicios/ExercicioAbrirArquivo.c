/* 
 Objetivo : Escreva um programa em C que indique se é possível abrir um determinado arquivo ou não.
 Entrada : Arquivo.
 Saida : Se é possível abrir um determinado arquivo 
 Aluno: Rafael Florentino.
*/
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

int main (void) {

FILE *p_arquivo;
    if ((p_arquivo = fopen("Teste.txt","wt")) == NULL) {
        printf("Arquivo nao pode ser aberto.");
    }
    else {
        printf("Arquivo aberto com sucesso.");
        fclose(p_arquivo); 
    }
    getch();
}
