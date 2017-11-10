#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "Pilha.h"
#include "ArquivoLabirinto.h"

int main(int argc, char* argv[])
{
	//verifica quantidade minima de paramentros
	if (argc < 2)
	{
		printf("Uso: %s arquivo_labirinto.txt\n", argv[0]);
		return(1);
	}

	//declaracao de variaveis
	char** labirinto = NULL; //matriz labirinto
	int linha, coluna; //limites da matriz
	Pilha* resultado = NULL; //resultado do labirinto

	//abre o arquivo e monta o labirinto
	AbreLabirinto(argv[1], &labirinto, &linha, &coluna);

	//Processa o labirinto e encontra o resultado
	resultado = ProcessaLabirinto(labirinto, linha, coluna);

	//exibe o resultado na tela
	printf("Caminho encontrado [ x , y ]:\n");
	while (!PilhaVazia(resultado))
	{
		int x = Topo_x(resultado);
		int y = Topo_y(resultado);

		printf("[ %i , %i ]\n", x, y);

		resultado = Pop(resultado);
	}

	//limpa a memoria e encerra o programa
	free(labirinto);
	FreePilha(resultado);
	return 0;

}
