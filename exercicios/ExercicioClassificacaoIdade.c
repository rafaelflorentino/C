/* 
 Objetivo : Classificar a pessoa de acordo com sua idade(criança, adolescente, joven, adulto, idoso).
 Entrada : ano de nascimento, ano atual.
 Saida : Idade e classificação da idade.
 Aluno : Rafael F Barbosa.
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void apresentaClassificacao(int resultado);
int obtemNivel(int anoA, int anoN);

int main()
{
    int idade, anoN, anoA, resultado;

    printf("\nDigite o seu ano de nascimento: ");
    scanf("%d", &anoN);
    fflush(stdin);

    printf("\nDigite o ano atual: ");
    scanf("%d", &anoA);
    fflush(stdin);

    resultado = obtemNivel(anoA, anoN);

    printf("\nVoce tem %d anos", resultado);
    printf("\n\n");

    apresentaClassificacao(resultado);

    getch();
    return 0;
}
int obtemNivel(int anoA, int anoN)
{
    return anoA - anoN;
}
void apresentaClassificacao(int resultado)
{
    if (resultado <= 10)
    {
        printf("A sua classificacao e: \n");
        printf("      Crianca");
    }
    if ((resultado > 10) && (resultado < 18))
    {
        printf("A sua classificacao e: \n");
        printf("      Adolescente");
    }
    if ((resultado >= 18) && (resultado < 25))
    {
        printf("A sua classificacao e: \n");
        printf("      Jovem");
    }
    if ((resultado >= 25) && (resultado < 58))
    {
        printf("A sua classificacao e: \n");
        printf("      Adulto");
    }
    if (resultado >= 58)
    {
        printf("A sua classificacao e: \n");
        printf("      Idoso");
    }
}
