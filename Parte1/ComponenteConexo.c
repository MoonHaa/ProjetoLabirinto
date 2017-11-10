#include <stdlib.h>
#include <stdio.h>
#include "Imagem.h"

int main(int argc, char* argv[])
{
	//uso do programa
	if (argc < 2)
	{
		printf("Uso: %s imagem_de_entrada.pbm\n",argv[0]);
		return(1);
	}

	//declaração de variaveis
	int** matriz = NULL; //matriz da imagem
	int linha, coluna; //limites da matriz
	int numero_objetos; //numero de objetos da imagem

	//le a imagem e monta a matriz
	AbreImagem(argv[1], &matriz, &linha, &coluna);

	//Processa a imagem e conta o numero de objetos conexos
	numero_objetos = ProcessaImagem(matriz, linha, coluna);

	//exibe resultado na tela
	printf("Foram encontrados %i componentes conexos!\n", numero_objetos);

	//limpa memoria e encerra o programa
	free(matriz);
	return 0;
}