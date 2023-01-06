/*
 Objetivo : O arquivo texto "LTPII.txt" contém 900 valores inteiros.
    a)	- Faça um programa que leia os 80 primeiros valores do arquivo e os coloque num vetor, alocado
        em área dinâmica de memória. Calcular e escrever na tela a Média Aritmética do vetor. Listar
        na tela os elementos do vetor que sejam menores que a Média Aritmética.
    b)	- O mesmo programa deve verificar e escrever na tela a quantidade de valores, entre 200 e 250
        (inclusive), existentes no arquivo.
    c)	- O mesmo programa deve ler do arquivo e escrever na tela os valores localizados na última
        linha do arquivo.
 Entrada : Sem entrada.
 Saida : Média Aritmética do vetor, quantidade de valores, entre 200 e 250, lementos do vetor que sejam
 menores que a Média Aritmética, valores localizados na última linha do arquivo..
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
int main()
{
    FILE *arqTexto;
    int *v, i, soma = 0, quant = 0, nr;
    float mediaArit;
    char buf[100];
    long int ult, finalarq;
    arqTexto = fopen("LTPII.txt", "r");

    if (arqTexto == NULL)
    {
        printf("\n\nErro ao abrir o arquivo!!!");
        getche();
        return 0;
    }
    // pedido a)
    v = (int *)calloc(80, sizeof(int));
    for (i = 0; i < 80; i++)
    {
        fscanf(arqTexto, "%d", &v[i]);
        soma += v[i];
    }
    mediaArit = soma / 80.0;
    printf("Media Aritmetica do vetor : %.5f", mediaArit);
    printf("\n\nValores do Vetor abaixo da Media:\n");
    for (i = 0; i < 80; i++)
    {
        if (v[i] < mediaArit)
        {
            printf("%5d", v[i]);
            quant++;
            if (quant % 10 == 0)
                printf("\n");
        }
    }
    free(v);

    // pedido b)
    rewind(arqTexto); // reiniciando o arquivo
    quant = 0;
    while (fscanf(arqTexto, "%d", &nr) != EOF)
        if ((nr >= 200) && (nr <= 250))
            quant++;
    printf("\n\nTotal de Numeros do Arquivo, entre 200 e 250 : %d\n", quant);

    // pedido c)
    rewind(arqTexto); // reiniciando o arquivo
    finalarq = ftell(arqTexto);
    while (fgets(buf, 100, arqTexto) != NULL)
    {
        ult = finalarq;
        finalarq = ftell(arqTexto);
    }
    fseek(arqTexto, ult, 0);
    fgets(buf, 100, arqTexto);
    printf("\n\nValores da ultima linha:\n\n");
    printf("%s", buf);
    fclose(arqTexto);

    printf("\n\nPressione uma TECLA para TERMINAR o programa ... ");
    getche();
    return 0;
}
