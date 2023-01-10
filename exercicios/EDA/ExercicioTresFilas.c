/*
 Objetivo: Escrever um programa que receba duas filas de inteiros com dados ordenados em ordem crescente e retorne uma
 terceira fila, também ordenada em ordem crescente, com todos os dados das filas de entrada. Ao final as filas de entrada
 devem estar inalteradas. (para implementar essa rotina considere a adição de uma nova função de fila chamada head(F)
 que retorna o dado do início da fila sem retirá-lo da fila).
 Entrada : Valores das pilhas.
 Saida   : Terceira pilha gerada.
 Aluno : Rafael Florentino.
*/
#include <stdio.h>
#define max 3

int main()
{
    int p1[max], p2[max], p3[max], p4[max], t1, t2, t3 = -1, t4 = -1, t, cheia, i;

    printf("Inserindo os elementos na pilha 1 \n");
    for (t1 = 0; t1 < max; t1++){
        scanf("%d", &p1[t1]);
    }
    printf("Inserindo os elementos na pilha 2 \n");
    for (t2 = 0; t2 < max; t2++){
        scanf("%d", &p2[t2]);
    }
    p3[t3] = -90000000;

    // printf ("%d %d\n", t1, t2);
    while (t1 >= 0 || t2 >= 0)
    {
        printf("t1 %d t2 %d  ", t1, t2);
        system("pause");

        t1 = t2 = t1 - 1;

        printf("t3 %d t1 %d\n", t3, t1);

        if (p1[t1] < p2[t2])
        {
            if (p1[t1] == p3[t3]){
                t1--;
            } else
            {
                if (p1[t1] > p3[t3])
                {
                    // teste t1 t3 vale
                    printf("antes incrementacao t3 %d t1 %d\n", t3, t1);
                    printf("antes incrementacao p3[t3] %d p1[t1] %d\n", p3[t3], p1[t1]);

                    p3[++t3] = p1[t1--];

                    // teste t1 t3 vale depois incrementacao
                    printf("depois incrementacao t3 %d t1 %d\n", t3, t1);
                    printf("antes incrementacao p3[t3] %d p1[t1] %d\n", p3[t3], p1[t1]);
                }
                else
                {
                    if (p1[t1] <= p3[t3])
                    {
                        while (p3[t3] >= p1[t1])
                        {

                            if (p1[t1] == p3[t3]){
                                t3--;
                            }else{
                                p4[++t4] = p3[t3--];
                            }
                            p4[++t4] = p3[t3--];
                        }
                        p3[++t3] = p1[t1--];
                    }
                    else if(p2[t2] > p1[t1])
                    {
                        if (p2[t2] == p3[t3]){
                            t2--;
                        }else
                        {
                            if (p2[t2] > p3[t3]){
                                p3[++t3] = p2[t2--];

                            }else
                            {
                                while (p3[t3] >= p2[t2])
                                {
                                    if (p3[t3] == p2[t2])
                                    {
                                        t3--;
                                    }
                                    else{
                                        p4[++t4] = p3[t3--];
                                    }
                                }
                                p4[++t4] = p3[t3--];

                                while (t4 > -1)
                                {
                                    p3[++t3] = p4[t4--];
                                }
                            }
                        }
                    }
                }
            }
        }  
                
               
    }
        for (i = t3; i >= 0; i--)
        {

            printf("%d\t", p3[i]);
            p4[++t4] = p3[i];
        }

        system("pause");
    }

