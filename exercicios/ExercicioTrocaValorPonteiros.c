/*
 Objetivo : Trocar valores de duas variaveis, usando ponteiros.
 Entrada : Valor1 e valor2.
 Saida : Valores trocados.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void troca_valores(int *ptrx, int *ptry);
void recebe_valores(int *valor1, int *valor2);

int main(void)
{
  int valor1, valor2;
  printf("\nEnderecos de valor1: %d e valor2: %d \n", &valor1, &valor2);

  recebe_valores(&valor1, &valor2);
  printf("\nEnderecos valores depois da funcao recebe: %d e %d \n", &valor1, &valor2);
  printf("\nVoce digitou os valores na seguinte ordem: %d e %d \n", valor1, valor2);
  
  /*chamada por referência */
  troca_valores(&valor1, &valor2);
  
  printf("Os valores trocados sao: %d e %d\n", valor1, valor2);
  printf("Enderecos valores depois da funcao troca sao: %d e %d\n", &valor1, &valor2);
  
  getch();
  return 0;
}

void troca_valores(int *ptrx, int *ptry)
{
  int auxiliar;
  
  auxiliar = *ptrx;
  *ptrx = *ptry;
  *ptry = auxiliar;
 
  return;
}

void recebe_valores(int *valor1, int *valor2)
{  
  printf("Digite o primeiro valor: ");
  scanf("%d", *&valor1);
  
  printf("Digite o segundo valor: ");
  scanf("%d", *&valor2);

  return;
}
