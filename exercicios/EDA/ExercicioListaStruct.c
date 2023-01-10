/*
 Objetivo: Faça um programa para criar e um lista e impeima na tela os dados.
 Entrada : nome da lista, valore da lista.
 Saida   : Lista dos dados.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
	
typedef struct nlista
{
   struct nlista *next;      
   struct nlista *ante;      
   int valor;	     

}lista;

lista *criar (int el)
{
   lista *temp;
   temp=(lista *)malloc(sizeof temp);
   temp->valor=el;
   temp->next=NULL;
   temp->ante=NULL;
   return temp;
}
/* Insere o elemento el na lista lis.*/
void  inserir (int el, lista *lis)
{
   lista *temp;
   temp=lis;
   while ((temp->next==NULL)==0)
     temp=temp->next;
   temp->next=(criar (el));
   (temp->next)->ante=temp;
}
/*Vai imprimir todos os elementos da lista */
void  listar (lista *lis)
{
   lista *temp, *t1, *t2;	
   temp=lis;
   while ((temp==NULL)==0)
    {
     t1=temp->next;
     t2=temp->ante;
     printf("O elemento: %d ", temp->valor);

     if ((t1==NULL)==0)
       printf("Tem como proximo o: %d ",t1->valor);
     else
       printf("Noo possui proximo.");
     if ((t2==NULL)==0)
       printf("E o anterior e: %d \n", t2->valor);
     else
       printf("E nao possui anterior. \n");

     temp=temp->next;
    }
}
/*Vai tirar o elemento el da lista lis */
lista  *remover (int el, lista *lis)
{
   lista *temp, *t1, *t2;	
   temp=lis;
   while ((temp==NULL)==0)
    {
     t1=temp->next;
     t2=temp->ante;
     if (temp->valor==el)
       if ((t2==NULL)==0)
         if ((t1==NULL)==0)
          { 
           t2->next=t1;
           t1->ante=t2;
           free (temp);

           return lis;
          } 
         else
          { 
           t2->next=NULL;
           free (temp);
           return lis;
      } 
       else 
        if ((t1==NULL)==0)
         { 
           t1->ante=NULL;
           free (temp);
           lis=t1;
           return lis;
         } 
        else 
         { 
           lis=NULL;
           free (temp);
           return lis;
         } 
     else 
       temp=temp->next; 
    } 
   printf("O Elemento nao se encontra na lista\n");
}
/*Vai devolver a posicao do elemento el */
int  procurar (int el, lista *lis)
{
   lista *temp;
   int pos=0;
	
   temp=lis;
   while ((temp==NULL)==0)
     if ((temp->valor)==el)
      {
       printf("A posicao do elemento %d e %d\n", el, pos);
       return pos;
      }
     else
      {
       pos++;
       temp=temp->next;
      }
   printf("O elemento nao se encontra na lista");
}
/*Devolve o elemento anterior a el */
void  anterior (int el, lista *lis)
{
   lista *temp, *t1;	
   temp=lis;
   while ((temp==NULL)==0)
     if ((temp->valor)==el)
     {
         t1=temp->ante;
         if ((t1==NULL)==0)
           printf("O elemento anterior a %d e %d\n", el,t1->valor);
         else
           printf("nao existe anterior");
      }
     else
       temp=temp->next;
   printf("O elemento nao se encontra na lista");
}
static lista *listas[3];  /* Array com apontadores para as tres listas */

int main()
{
   int op, op1, op2;
   do   {
     printf(" Informe Uma Opcao\n");
     printf("\t1) Criar uma nova lista \n");
     printf("\t2) Inserir um novo elemento \n");
     printf("\t3) Remover um elemento da lista \n");
     printf("\t4) Procurar um elemento \n");
     printf("\t5) Listar a lista\n");
     printf("\t6) Sair do programa\n");
     printf("A escolha e: ");
     scanf ("%d",&op);

     switch(op)
      {
       case 1:
         printf("Qual a lista que deseja iniciar: ");
         scanf ("%d",&op1);
         printf("Qual e o primeiro elemento: ");
         scanf ("%d",&op2);
         listas[op1]=(criar  (op2));
         break;

       case 2:
         printf("Qual a lista em que deseja inserir um elemento: ");
         scanf ("%d",&op1);
         printf("Qual e o elemento que deseja inserir: ");
         scanf ("%d",&op2);
         inserir(op2, listas[op1]);
         break;

       case 3:
         printf("Qual a lista em que deseja remover um elemento: ");
         scanf ("%d",&op1);
         printf("Qual e o elemento que deseja remover: ");
         scanf ("%d",&op2);
         listas[op1]=remover(op2, listas[op1]);
         break;

       case 4:
         printf("Qual a lista em que deseja procurar um elemento: ");
         scanf ("%d",&op1);
         printf("Qual e o elemento que deseja procurar: ");
         scanf ("%d",&op2);
         procurar(op2, listas[op1]);
         break;

       case 5:
         printf("Qual a lista em que deseja listar: ");
         scanf ("%d",&op1);
         listar(listas[op1]);
         break;

       default:
         printf("Opçao errada!");
      }
   }while(op!=6);
}
