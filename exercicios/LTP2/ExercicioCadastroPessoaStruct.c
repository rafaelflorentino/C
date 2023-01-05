/*
 Objetivo : Fazer um programa que receba nome, sexo e a matricula e gerada automaticamente, ordema por matricula orddem crescente, listar mulheres em ordem decrescente.
 Entrada : Nome, sexo.
 Saida : Nome, sexo, matricula.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    
    int i, Trocou=1;
    const qnt=5; // Quantidade de pessoas

    typedef struct {
        int  matricula;
        char sexo;
        char nome[50];
    } Pessoa;
    
    Pessoa pessoas[qnt], aux;

    printf("------------ INFORME OS DADOS DOS ALUNOS ------------\n\n");
    for( i=0; i<qnt; i++) {

        srand (time (NULL));

        pessoas[i].matricula =  rand() % (999 - 100 + 1) + 100;

        printf("      Pessoa %d\n", i+1 );
        printf("\nNome: ");
        fflush(stdin);
        gets(pessoas[i].nome);

        printf("\nSexo: ");
        pessoas[i].sexo = toupper(getchar());

        printf("\n\nAperte qualquer tecla para continuar...");
        getch();
        system("cls");
        printf("\n\n");
    }
    
    system("cls");
    printf("------------ PESSOAS ------------\n\n");

    for( i=0; i<qnt; i++) {
        printf("      Pessoa %d\n", i+1 );
        printf("\nNome: %s", pessoas[i].nome);
        printf("\nSexo: %c", pessoas[i].sexo);
        printf("\nMatricula: %d", pessoas[i].matricula);
        printf("\n\n");
    }

    printf("\n\nAperte qualquer tecla para continuar...");
    getch();
    system("cls");

    // COLOCA TODOS EM ORDEM DECRESCENTE DE ACORDO COM A MATRICULA
    while(Trocou) {
        Trocou=0;
        for( i=0; i<=(qnt-2); i++) {
            if( pessoas[i].matricula < pessoas[i+1].matricula ) {
                aux = pessoas[i];
                pessoas[i] = pessoas[i+1];
                pessoas[i+1] = aux; 
                Trocou = 1; 
            }
        }
    }

   // EXIBE SOMENTE AS MULHERES
    printf("------------ MULHERES EM ORDEM DECRESCENTE ------------\n\n");

    for( i=0; i<qnt; i++) {

        if ( pessoas[i].sexo == 'F' ) {
            printf("      Mulher %d\n", i+1 );
            printf("\nNome: %s", pessoas[i].nome);
            printf("\nSexo: %c", pessoas[i].sexo);
            printf("\nMatricula: %d", pessoas[i].matricula);
            printf("\n\n");
        }
    }

    printf("\n\nAperte qualquer tecla para sair...");
    getch();
}
