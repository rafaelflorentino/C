/* 
 Objetivo : Calcular a média das alturas das mulheres e a média do peso dos homens.
 Entrada : Altura, sexo, peso, nome.
 Saida : A média das alturas das mulheres e a média do peso dos homens.
 Aluno : Rafael Florentino.
 */

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
main()
{
    float altura = 0, alturaA = 0, peso = 0, pesoH = 0, mediaA = 0, mediaP = 0;
    char sexo;
    char nome[40];
    int i, cont1 = 0, cont2 = 0;

    for (i = 1; i <= 4; i = i + 1)
    {
        printf("Digite seu nome: ");
        scanf("%c", &nome);
        fflush(stdin);
        
        printf("Digite o seu sexo : ");
        scanf("%c", &sexo);
        fflush(stdin);

        printf("Digite o seu peso: ");
        scanf("%f", &peso);
        fflush(stdin);

        printf("Digite a sua altura: ");
        scanf("%f", &altura);
        fflush(stdin);
        printf("\n");

        if (sexo == 'f')
        {
            cont1 = cont1 + 1;
            alturaA = alturaA + altura;
            mediaA = alturaA / cont1;
        }
        if (sexo == 'm')
        {
            cont2 = cont2 + 1;
            pesoH = pesoH + peso;
            mediaP = pesoH / cont2;
        }
    }

    printf("A media das alturas das mulheres e : %2.2f \nA media do peso dos homens e: %2.2f", mediaA, mediaP);
    
}
