/*
 Objetivo : O número de candidatos do sexo feminino, o número de candidatos do sexo masculino e a idade média dos homens que já tem experiência no serviço
 Entrada : Idade, sexo e experiência.
 Saida : O número de candidatos.
 Aluno : Rafael Florentino.
*/
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
main()
{
    int i, j, idade = -1, contf = 0, contm = 0, contMexperiencia = 0;
    float mediai = 0, media = 0;
    char sexo, experiencia;

    while (idade != 0)
    {
        printf("Digite sua idade ou zero para sair: ");
        scanf("%d", &idade);
        if (idade != 0)
        {
            fflush(stdin);
            printf("Digite seu sexo: ");
            scanf("%c", &sexo);
            fflush(stdin);
            printf("Digite se tem experiencia(S ou N): ");
            scanf("%c", &experiencia);
            fflush(stdin);

            if (sexo == 'f')
            {
                contf = contf + 1;
            }
            if (sexo == 'm')
            {
                contm = contm + 1;
                if (experiencia == 's')
                {         
                    contMexperiencia = contMexperiencia +1;        
                    mediai = mediai + idade;
                    media = mediai / contMexperiencia;
                }
            }

        }
    }

    printf("\nO numero de mulheres e: %d \nO numero de homens e: %d \nO numero de homens com experiencia e: %d \nA media da idade dos homens com experiencia e: %f ", contf, contm, contMexperiencia, media);
}
