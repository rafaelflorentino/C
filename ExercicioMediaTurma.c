/* 
 Objetivo : Calcular média da turma, calcular se cada aluno passou ou reprovou.
 Entrada : Notas provas, listas.
 Saida : Média da turma,calcular se cada aluno passou ou reprovou.
 Aluno : Rafael Florentino.
*/

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
main()
{
    float a1 = 0, a2 = 0, l1 = 0, l2 = 0, media1 = 0, media2 = 0, media3 = 0, mediaf = 0, mediat = 0, mt = 0;
    int i;

    for (i = 1; i <= 2; i = i + 1)
    {
        printf("Digite a nota da prova 1: ");
        scanf("%f", &a1);
        printf("Digite a nota da prova 2: ");
        scanf("%f", &a2);
        printf("Digite a nota da lista 1: ");
        scanf("%f", &l1);
        printf("Digite a nota da lista 2: ");
        scanf("%f", &l2);

        media1 = (a1 * 2 + l1) / 3;
        media2 = (a2 * 2 + l2) / 3;
        mediaf = (media1 + media2) / 2;
        mediat = mediat + mediaf;
        mt = mediat / i;

        if ((mediaf >= 7))
        {
            printf("Media: %2.2f Aprovado!\n",mediaf);
        }
        else
        {
            printf("Media: %2.2f Reprovado!\n",mediaf);
        }
    }
    printf("A media da turma e: %f ", mt);
    
}
