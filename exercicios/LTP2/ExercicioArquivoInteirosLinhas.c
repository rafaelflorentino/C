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
    v = (int *)malloc(sizeof(int) * 80);
    for (i = 0; i < 80; i++)
    {
        fscanf(arqTexto, "%d", &v[i]);
        soma += v[i];
    }
    mediaArit = soma / 80.0;
    printf("\nMedia Aritmetica do vetor : %.5f", mediaArit);
    printf("\n\nValores abaixo da Media:\n");
    for (i = 0; i < 80; i++)
        if (v[i] < mediaArit)
            printf("%8d", v[i]);
    free(v);

    // pedido b)
    rewind(arqTexto); // reiniciando o arquivo
    fscanf(arqTexto, "%d", &nr);
    while (!feof(arqTexto))
    {
        if ((nr >= 200) && (nr <= 250))
            quant++;
        fscanf(arqTexto, "%d", &nr);
    }
    printf("\n\nTotal de Numeros do Arquivo, entre 200 e 250 : %d\n", quant);

    // pedido c)
    rewind(arqTexto); // reiniciando o arquivo
    finalarq = ftell(arqTexto);
    fgets(buf, 100, arqTexto);
    while (!feof(arqTexto))
    {
        ult = finalarq;
        finalarq = ftell(arqTexto);
        fgets(buf, 100, arqTexto);
    }
    fseek(arqTexto, ult, 0);
    fgets(buf, 100, arqTexto);
    printf("\n\nValores da ultima linha:\n\n");
    printf("%s", buf);
    fclose(arqTexto);

    // Valores da primeira linha
    arqTexto = fopen("LTPII.txt", "r");
    //rewind(arqTexto); // reiniciando o arquivo

    fseek(arqTexto, 0, SEEK_SET);
    fgets(buf, 100, arqTexto);
    printf("\n\nValores da Primeira linha:\n\n");
    printf("%s", buf);

    // Valores da Segunda linha
    rewind(arqTexto); // reiniciando o arquivo

    fseek(arqTexto, 15.5 * sizeof(int), SEEK_CUR);// 15.5 * 4bits int = 62
    fgets(buf, 100, arqTexto);
    printf("\n\nValores da Segunda linha:\n\n");
    printf("%s", buf);
    
    fclose(arqTexto);
    printf("\n\nPressione uma TECLA para TERMINAR o programa ... ");
    getche();
    return 0;
}
