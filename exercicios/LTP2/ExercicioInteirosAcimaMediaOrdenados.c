/*
 Objetivo : Faça um programa que gere 30 inteiros aleatórios entre 10 e 99. (em área dinámica de  memória).
 Escrever os números na ordem gerada. Escrever a Média dos números gerados. Escrever todos os números que estejam acima da Média.
 Ordenar CRESCENTE os 30 valores e reescrevé-los na tela.
 Entrada : Sem entrada.
 Saida : 30 inteiros, media, numeros acima da menia ordenados.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
// Protótipos
void EscreveVetorInt(int *Vet, int N);
void OrdenaVetIntBolha(int *, int);
void Finalizacao();
// Principal
int main()
{
    int *V, I, Aux, Soma = 0;
    float Media;
    srand(time(NULL));
    system("color 17");
    // Geração dos 30 valores em área dinámica de memória
    // V = (int *) calloc(30,sizeof(int));
    V = (int *)malloc(sizeof(int) * 30); // Alocação dinámica na memória
    for (I = 0; I < 30; I++)
    {
        V[I] = rand() % 90 + 10;
        Soma += V[I];
    }
    // Escrever os 30 valores gerados
    printf("\nLista dos 30 numeros aleatorios entre 10 e 99 na Ordem Gerada: \n\n");
    EscreveVetorInt(V, 30);
    // Cálculo e Escrita da Média
    Media = Soma / 30.0;
    printf("\n\nMedia dos valores = %f", Media);
    // Escrita dos Valores acima da Média
    printf("\n\n\nValores acima da MEDIA : \n");
    for (I = 0; I < 30; I++)
        if (V[I] > Media)
            printf("\nV[%2d] = %d", I, *(V + I));
    // Ordenação Crescente
    OrdenaVetIntBolha(V, 30);
    // Escrita dos 30 valores Ordenados CRESCENTE
    printf("\n\nNumeros Ordenados CRESCENTE: \n");
    EscreveVetorInt(V, 30);
    // Finalização
    Finalizacao();
    return 0;
}
// Procedimento para escrever vetor de inteiros na tela
void EscreveVetorInt(int *Vet, int N)
{
    int I;
    for (I = 0; I < N; I++)
        printf("Vetor[%2d] = %d\n", I, Vet[I]);
}
// Ordenação de um vetor de inteiros com N valores, Método da BOLHA
void OrdenaVetIntBolha(int *Vet, int N)
{
    int I, J, Aux;
    for (I = 0; I < N - 1; I++)
        for (J = I + 1; J < N; J++)
            if (Vet[I] > Vet[J])
            {
                Aux = Vet[I];
                Vet[I] = Vet[J];
                Vet[J] = Aux;
            }
}
// Procedimento Finalização
void Finalizacao()
{
    printf("\n\nPressione uma TECLA para TERMINAR o PROGRAMA ... ");
    getch();
}
