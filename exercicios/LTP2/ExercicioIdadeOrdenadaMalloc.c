/*
 Objetivo : Faça um programa que inteiros N, aleatório entre 100 e 500. Alocar, em área dinámica de memória,
 um vetor com N idades de pessoas. Cada idade deve ser gerada por um valor aleatório entre 0 e 99 anos.
 Escrever na tela todas as idades na ordem inversa a ordem que foram geradas.não deve ocorrer desperdecio de alocação
 de meméria; após ser utilizada, a memória alocada deve ser devolvida ao Sistema Operacional.
 Entrada : Sem entrada.
 Saida : Arquivo binário, conteudo do arquivo ordenado na tela.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
int main()
{
    int N, *V, i, aux;
    srand(time(NULL));

    N = rand() % 401 + 100;
    V = (int *)malloc(N * sizeof(int));

    printf("\n%d Idades geradas, em ORDEM de Criacao :\n\n", N);
    for (i = 0; i < N; i++)
    {
        V[i] = rand() % 100;
        printf("V[%3d] = %d\n", i, V[i]);
    }

    printf("\n\n\n%d Idades geradas, em ORDEM Inversa :\n\n", N);
    for (i = N - 1; i >= 0; i--)
    {
        printf("V[%3d] = %d\n", i, V[i]);
    }
    // Ordenando Crescente
    for(int varreduras = 0; varreduras < N ; varreduras++){
        for(i = 0; i < (N-1) ; i++){
            if(V[i] > V[i+1])
            {
                aux =  V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
            }
        }
    }
    // Listando Crescente
    printf("\n\nLista dos %d numeros em Ordem Crescente: \n", N);
    for(i = 0; i < N; i++){
        printf("\nV[%d] N[%d] ",i, V[i]);
    }

    free(V);
    printf("\n\nPressione uma TECLA para TERMINAR o programa ... ");
    getche();
    return 0;
}

/*
int main()
{    
    int i, *V, numero=0, aux=0;
    srand(time(NULL));

    printf("\nDigite a quantidade de vetores a ser Criada: ");
    scanf(" %d", &numero);
    fflush(stdin);

    V = (int *)malloc(numero * sizeof(int));

    printf("\nLista dos %d numeros gerados: \n", numero);
    for(i = 0; i < numero; i++){
        V[i] = rand() % 51 +100;
        printf("\nV[%d] N[%d] ",i, V[i]);
    }

    // Ordenando Crescente
    for(int varreduras = 0; varreduras < numero ; varreduras++){
        for(i = 0; i < (numero-1) ; i++){
            if(V[i] > V[i+1])
            {
                aux =  V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
            }
        }
    }
    // Listando Crescente
    printf("\n\nLista dos %d numeros em Ordem Crescente: \n", numero);
    for(i = 0; i < numero; i++){
        printf("\nV[%d] N[%d] ",i, V[i]);
    }

    // Ordenando Descente
    for(int varreduras = 0; varreduras < numero ; varreduras++){
        for(i = 0; i < (numero-1) ; i++){
            if(V[i +1] > V[i])
            {
                aux =  V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
            }
        }
    }

    // Listando Descente
    printf("\n\nLista dos %d numeros em Ordem Decrescente: \n", numero);
    for(i = 0; i < numero; i++){
        printf("\nV[%d] N[%d] ",i, V[i]);
    }

    free(V);
    printf("\n\n");
    return 0;
    }*/

