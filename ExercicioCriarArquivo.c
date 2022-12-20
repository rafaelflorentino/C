/* 
 Objetivo : Escreva um programa em C que crie um arquivo e escreva nele.
 Entrada : Texto, nome do arquivo.
 Saida : Arquivo editado.
 Aluno: Rafael Florentino.
*/
#include <stdio.h>
int main(){
		char arquivo[100];
		char texto[100];
		
		FILE * pFile;//Ponteiro(link para o endereço da memória) para o arquivo de nome: 'pFile
		
		printf("Informe o nome do novo arquivo, ou nome do ja existente(voce pode por caminho da pasta, opcional): \n");
		scanf("%s", &arquivo);
		
		pFile = fopen(arquivo , "w");// fopen 'w' Abre um arquivo texto para gravação, se o arquivo não existir, ele será criado, se já existe sera destruido.
		
		if(pFile!=NULL){ //Se o arquivo não for vazio 
            printf("Digite o que voce deseja escrever no arquivo(sem espacos): \n");
            scanf("%s", &texto);
            fputs(texto, pFile);/*Escreve o texto no arquivo. */
            printf("Arquivo Salvo com Sucesso! \n");
            fclose(pFile);//fechar arquivo	
        }else{
            printf("Arquivo nao pode ser aberto.");
        }
	return 0; 
}