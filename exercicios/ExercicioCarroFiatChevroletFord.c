/* 
 Objetivo : Receber a marca e o modelo do carro por opções de menu : FIAT, CHEVROLET e FORD.
 Entrada : Marca , carro.
 Saida : Nome, carro e mensagem.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void menu();
void menuFiat();
void menuChevrolet();
void menuFord();

int main()
{
    char resultado, nome[40];
    int marca=0, carro=0;

    puts("\nDigite seu nome: ");
    gets(nome);
    fflush(stdin);
    printf("\nEscolha uma das marcas de veiculos abaixo ");
    menu();
    
    printf("Escolha e digite (1, 2 ou 3): ");
    scanf("%d", &marca);
    fflush(stdin);

    if (marca == 1)
    {
        menuFiat();
        printf("\nEscolha um carro (1, 2 ou 3): \n");
        scanf("%d", &carro);
        if (carro == 1)
        {
            printf("\n%s Obrigado por escolher nosso carro: Uno", nome);
        }
        else if (carro == 2)
        {
            printf("\n%s Obrigado por escolher nosso carro: Palio", nome);
        }
        else if (carro == 3)
        {
            printf("\n%s Obrigado por escolher nosso carro: Mobi", nome);
        }
    }
    else if(marca == 2)
    {
        menuChevrolet();
        printf("Escolha um carro (1, 2 ou 3): \n");
        scanf("%d", &carro);
        if (carro == 1)
        {
            printf("\n%s Obrigado por escolher nosso carro: Vectra", nome);
        }
        else if (carro == 2)
        {
            printf("\n%s Obrigado por escolher nosso carro: Camaro", nome);
        }
        else if (carro == 3)
        {
            printf("\n%s Obrigado por escolher nosso carro: Cruze", nome);
        }
    }
    else if(marca == 3)
    {
        menuFord();
        printf("\nEscolha um carro (1, 2 ou 3): ");
        scanf("%d", &carro);
        if (carro == 1)
            {
                printf("\n%s Obrigado por escolher nosso carro: Fiesta", nome);
            }
        else if (carro == 2)
            {
                printf("\n%s Obrigado por escolher nosso carro: Fusion", nome);
            }
        else if (carro == 3)
            {
                printf("\n%s Obrigado por escolher nosso carro: Ranger", nome);
            }
    }
    else{
        printf("Valor digitado Invalido!!! \n");
    }
    return 0;
}

void menu()
{
    printf("\n");
    printf("  1       2         3 \n");
    printf(" FIAT   CHEVROLET  FORD \n");
    printf("\n");   
}
void menuFiat()
{
    printf("\n");
    printf("  1       2         3 \n");
    printf(" Uno    Palio     Mobi \n"); 
    printf("\n");   
}
void menuChevrolet()
{
    printf("\n");
    printf("  1         2         3 \n");
    printf(" Vectra    Camaro     Cruze \n");
    printf("\n");   
}
void menuFord()
{
    printf("\n");
    printf("  1         2         3 \n");
    printf(" Fiesta    Fusion     Ranger \n");  
    printf("\n"); 
}
