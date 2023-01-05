/*
 Objetivo : Escreva um programa em linguagem C que solicita ao usuário a quantidade de alunos de uma turma e
 aloca um vetor de notas (números reais). Depois de ler as notas, imprime a média aritmética.
 Obs: não deve ocorrer desperdício de memória; e, após ser utilizada, a memória deve ser devolvida.
 Entrada : Quantidade de alunos.
 Saida : Média Aritimetica da turma.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
int main()
{
    int I, Quant;
    float Soma = 0, *V;
    printf("Entre com a quantidade de alunos da turma : ");
    scanf("%d", &Quant);

    V = (float *) malloc(Quant * sizeof(float));
    //V = (float *)calloc(Quant, sizeof(float)); // separa espaço de memória dinâmica

    for (I = 0; I < Quant; I++)
    {
        printf("\nEntre com a Nota do %da Aluno: ", I + 1);
        scanf("%f", &V[I]);
        Soma += V[I];
    }
    printf("\nMedia das Notas lidas = %2.2f\n", Soma / Quant);
    free(V); // Libera memória
    printf("\n\nPressione uma TECLA para encerrar ... ");
    getche();
    return 0;
}
