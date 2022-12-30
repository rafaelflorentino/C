/*
 Objetivo : Escreva um programa em C que valide os dados de entrada (inteiros entre 0 e 13); E calcule o fatorial.
 Entrada : numero inteito entre o e 13.
 Saida : Valores trocados e listados em ordem crescente.
 Aluno: Rafael Florentino.
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int Fatorial(int N);
void ProcFatorial(int N, int *Resul);
int LerValidar();
void ProcLerValidar(int *Nr);
void  Finalizacao();

//Principal-------------------------------------------------------------------------------------------------------------
int main()
{   int Numero, Aux;
    //Primeiro valor 
    system("color 2");
    Numero = LerValidar();
    printf("\nFuncao Fatorial :      %d! = %d\n",Numero,Fatorial(Numero));
    ProcFatorial(Numero, &Aux);
    printf("\nProcedimento Fatorial : %d! = %d\n\n\n",Numero,Aux);
     
    //Segundo valor
    ProcLerValidar(&Numero);
    printf("\nFuncao Fatorial :     %d! = %d\n",Numero,Fatorial(Numero));
    ProcFatorial(Numero, &Aux);
    printf("\nProcedimento Fatorial :  %d! = %d\n",Numero,Aux);
     
    //Finalização   
    Finalizacao();
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------

//Função Fatorial
int Fatorial(int N)
{    int fator = 1, cont;   
     for(cont = 1; cont <= N; cont++)
            fator = fator * cont;      
     return fator;   
}

//Procedimento Fatorial
void ProcFatorial(int N, int *Resul)
{    int cont;   *Resul = 1;   
     for(cont = 1; cont <= N; cont++)
            *Resul = *Resul * cont;        
}

//Função Ler Validar------------------------------------------------------------------------------------------------
int LerValidar()
{   int Nr;

    do
    {   printf("\nInforme um inteiro entre 0 e 13 : ");
        scanf("%d",&Nr);    
        if((Nr < 0) || (Nr > 13))
              printf("ERRO !!! Valor Invalido ... Tente novamente ...\n\n\n");          
    }  while ((Nr < 0) || (Nr > 13));
    return Nr;
}

//Procedimento Ler validar
void ProcLerValidar(int *Nr)
{   do
    {   printf("Informe um inteiro entre 0 e 13 : ");
        scanf("%d",Nr);    
        if((*Nr < 0) || (*Nr > 13))
              printf("ERRO !!! Valor Invalido ... Tente novamente ...\n\n\n");          
    }  while ((*Nr < 0) || (*Nr > 13));  
    return;  
}
//-------------------------------------------------------------------------------------------------------------------

//Proc Finalização
void  Finalizacao()
{   printf("\nDigite qualquer TECLA para TERMINAR o PROGRAMA .... ");
    getch();
}

