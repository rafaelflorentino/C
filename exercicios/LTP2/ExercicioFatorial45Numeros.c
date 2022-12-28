/*
 Objetivo : Escreva um programa em C mostre o fatorial de 0 a 45 interativo e recursivo, o número atual anterior e o próximo.
 Entrada : Sem Entrada.
 Saida : O fatorial interativo e recursivo de 45 números, numero atual, anterior, próximo.
 Aluno: Rafael Florentino.
*/
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
int fatIter(int N);
int fatRec(int N);

int main()
{
	int anterior = 0, atual = 0, proximo = 0, total = 0, fatIter(int N), fatRec(int N);

	while (total <= 45)
	{
        anterior = atual - 1;
        atual = atual + 1;
		proximo = atual + 1;
		
		printf("\nTotal: %d\n", total);
		printf("Anterior: %d\n", anterior);
		printf("Atual: %d\n", atual);
		printf("Proximo: %d\n", proximo);
		printf("Fatorial Interativo: %d \n", fatIter(total));
		printf("Fatorial Recursiva: %d \n", fatIter(total));
		total++;
	}
	getch();
	return 0;
}

int fatIter(int N)
{
	int fatorial = 1, cont;
	for (cont = 1; cont <= N; cont++)
	{
		fatorial = fatorial * cont;
	}
	return (fatorial);
}

int fatRec(int N)
{
	if (N == 0)
	{
		return 1;
	}
	else
	{
		return (fatRec(N - 1) * N);
	}
}
