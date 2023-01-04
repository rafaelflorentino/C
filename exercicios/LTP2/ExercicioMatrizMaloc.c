/*
 Objetivo : Fazer um programa que crie uma matriz M de inteiros, na área dinámica de memória. A quantidade de linhas e a quantidade de 
 colunas de M devem ser lidas via teclado. Inicializar cada M[i][j] com o valor de (i+j) . Escrever M na tela, em formato matricial.
 Entrada : Quantidade de linhas e colunas.
 Saida : Matriz.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
/* Início do programa. */
int main()
{
  /* Declaração das variáveis. */
  int **M;
  int i, j, linhas, colunas;
  
  /* Leitura das linhas e colunas. */
  printf("Entre com a Quantidade de linhas: ");
  scanf("%d", &linhas);  

  printf("Entre com a Quantidade de colunas: ");
  scanf("%d", &colunas);  
  
  /* Alocação da M. */
  M = (int **) malloc(sizeof(int *) * linhas);
  for (i = 0; i < linhas; i++){
      M[i] = (int *) malloc(sizeof(int) * colunas);
  }
  
  /* Preenchimento da M. */
  for (i = 0; i < linhas; i++){
      for (j = 0; j < colunas; j++){
          M[i][j] = i + j;
      }
  }

  /* Escrita da M na tela. */ 
  printf("\n\n Matriz Criada : \n\n");
  for (i = 0; i < linhas; i++){
      for (j = 0; j < colunas; j++){
          printf("%4d ", M[i][j]);
      }
      printf("\n\n");
  }
  printf("\n");
  system("PAUSE");	
  return 0;
}
