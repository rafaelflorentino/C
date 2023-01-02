/*
 Objetivo : Escreva um programa em C que cadastre os dados do aluno e imprima na tela todos alunos cadastrados.
 Entrada : Nome, rg, sexo, idade, matricula, mesalidade.
 Saida : Nome, rg, sexo, idade, matricula, mesalidade.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Dados_Aluno
{
   char nome[30];
   char rg[15];
   char sexo[15];
   int idade;
   int matricula;
   float mensalidade;
};

int main(void)
{
   const int qtde_aluno = 2;
   int i;
   /* Turma com qtde_aluno alunos*/
   struct Dados_Aluno Aluno[qtde_aluno];

   for (i = 0; i < qtde_aluno; i++)
   {
      printf("\nAluno %d: \n", i+1);
      printf("Informe o nome: ");
      fflush(stdin);
      gets(Aluno[i].nome);
      printf("Informe a matricula: ");
      scanf("%d", &Aluno[i].matricula);
      fflush(stdin);
      printf("Informe RG: ");
      gets(Aluno[i].rg);
      fflush(stdin);
      printf("Informe a Idade: ");
      scanf("%d", &Aluno[i].idade);
      fflush(stdin);
      printf("Informe o sexo: ");
      gets(Aluno[i].sexo);
      fflush(stdin);
      printf("Informe a mensalidade: ");
      scanf("%f", &Aluno[i].mensalidade);
      fflush(stdin);
      printf("\n");
      system("pause");
      system("cls");
   }

   for (i = 0; i < qtde_aluno; i++)
   {
      printf("\nAluno %d\n\tMatricula: %d\n\tNome: %s\n\tRG: %s\n\tIdade: %d\n\tSexo: %s\n\tMensalidade: %2.2f\n", i + 1, Aluno[i].matricula, Aluno[i].nome, Aluno[i].rg, Aluno[i].idade, Aluno[i].sexo, Aluno[i].mensalidade);
   }
   printf("\n");
   getch();
}
