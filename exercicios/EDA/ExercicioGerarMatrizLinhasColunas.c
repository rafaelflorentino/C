/*
 Objetivo: Gerar uma matiz e um vetor.
 Entrada : Número de Linhas, numero de Colunas.
 Saida   : Matriz impressa vetor impresso.
 Aluno   : Rafael Florentino.
*/
int** GeraMatriz(int L,int C);

int main()
{   int **Mat, N, M, i, j,soma;
    printf("Entre com a quantidade de LINHAS da Matriz : ");
    scanf("%d",&N);
    printf("Entre com a quantidade de COLUNAS da Matriz : ");
    scanf("%d",&M);
    
    int *V;
    V = (int *)malloc( N * sizeof(int));
    Mat = GeraMatriz(N,M);
    printf("\n\nMatriz Gerada:\n");
    for(i=0;i<N;i++)
    {  printf("\n\n");
        for(j=0;j<M;j++)
            printf("%5d",Mat[i][j]);
    }
     
    printf("\n\nVetor Gerado: \n\n");
    for(j=0;j<M;j++){	 /*Percorre toda a matriz somando os valores das colunas*/
        for(i=0;i<N;i++)
            V[j]= soma = soma + Mat[i][j];	 /*Soma os valores contido em cada coluna*/
        printf("%5d",V[j]);/*Imprime os valores de cada coluna*/
        soma = 0.0;	 /*Zera a variável soma para reultilizá-la*/
    }       
    return 0;    
}

int** GeraMatriz(int L,int C)
{  int **pMatriz, i, j,soma;
    pMatriz=(int **)malloc(L*sizeof(int *));
    for (i=0;i<L;i++)
    {    pMatriz[i]=(int *)malloc(C*sizeof(int));
        for (j=0;j<C;j++){
            pMatriz[i][j] =1 + ( rand() % 10 ) ;}        
    }   
    return (pMatriz);
}
