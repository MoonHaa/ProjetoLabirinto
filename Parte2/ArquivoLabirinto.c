#include "ArquivoLabirinto.h"
#include <stdio.h>
#include <malloc.h>

void AbreLabirinto(char * arquivo, char *** labirinto, int * linha, int * coluna)
{
	//variaveis auxiliares
	int i, j;
	char c;

	//abre o arquivo
	FILE* arquivo_labirinto = fopen(arquivo, "r");

	//numero de coluna e linhas do labirinto
	fscanf(arquivo_labirinto, "%i %i", coluna, linha);

	//alocando a matriz
	(*labirinto) = (char **)malloc(*linha * sizeof(char*)); //bug? com *linha, ao compilar com gcc, programa da segmentation fault durante sua execucao...

	for (i = 0; i < *linha; i++)
		(*labirinto)[i] = (char *)malloc(*coluna * sizeof(char));

	//remove o \n apos os valores de coluna e linha da matriz
	fscanf(arquivo_labirinto, "%c", &c);

	//le o labirinto
	for (i = 0; i < *linha; i++)
	{
		for (j = 0; j < *coluna; j++)
		{
			fscanf(arquivo_labirinto, "%c", &c);
			if (c != '\n')
				(*labirinto)[i][j] = c;
		}

		//remove o \n apos cada linha da matriz
		fscanf(arquivo_labirinto, "%c", &c);
	}

	//fecha o arquivo e encerra a funcao
	fclose(arquivo_labirinto);
	return;
}

Pilha* ProcessaLabirinto(char ** labirinto, int linha, int coluna)
{
	//Pilha de processamento
	Pilha *p = CriaPilha();

	//Pilha com o auxiliar
	Pilha *auxiliar = CriaPilha();

	//variaveis auxiliares
	int i, j, pto_inicial = 1;

	//processa a matriz do labirinto, ignorando as bordas
	for (i = 1; (i< (linha - 1)) && pto_inicial; i++)
		for (j = 1; (j < (coluna - 1)) && pto_inicial; j++)
		{
			//encontra a posicao inicial e a empilha
			if (labirinto[i][j] == 'i')
			{
				p = Push(p, i, j);
				pto_inicial = 0;
			}
		}

	//enquanto pilha tiver posicoes, procura por posicoes vizinhas validas e as empilha
	while (!PilhaVazia(p))
	{
		//guarda os valores de posicao
		int x = Topo_x(p);
		int y = Topo_y(p);

		//desempilha posicao
		p = Pop(p);

		//empilha posicao na auxiliar
		auxiliar = Push(auxiliar, x, y);

		//encontrou fim do labirinto
		if (labirinto[x][y] == 'f')
		{
			//cria a pilha com o resultado encontrado
			Pilha* resultado = CriaPilha();

			//desempilha as posicoes da pilha auxiliar e empilha na resultado
			while (!PilhaVazia(auxiliar))
			{
				//guarda o valor das posicoes
				x = Topo_x(auxiliar);
				y = Topo_y(auxiliar);

				//desempilha posicao
				auxiliar = Pop(auxiliar);

				//empilha na resultado
				resultado = Push(resultado, x, y);
			}

			//empilha posicao inicial na resultado
			resultado = Push(resultado, i - 1, j - 1);

			//limpas as lista p e auxiliar
			FreePilha(p);
			FreePilha(auxiliar);

			//retorna o resultado
			return resultado;
		}
		else
		{
			//flag para limpeza da pilha resultado
			int flag = 1;

			//verifica os vizinhos, se nao encontrar caminhos validos, limpa a pilha auxiliar
			if (labirinto[x + 1][y] != '*')
			{
				p = Push(p, x + 1, y);
				flag = 0;
			}

			if (labirinto[x - 1][y] != '*')
			{
				p = Push(p, x - 1, y);
				flag = 0;
			}

			if (labirinto[x][y + 1] != '*')
			{
				p = Push(p, x, y + 1);
				flag = 0;
			}

			if (labirinto[x][y - 1] != '*')
			{
				p = Push(p, x, y - 1);
				flag = 0;
			}

			//marca posicao como visitada
			labirinto[x][y] = '*';

			//nao foram encontrados caminhos validos, entao reseta a pilha auxiliar
			if (flag)
			{
				FreePilha(auxiliar);
				auxiliar = CriaPilha();
			}
		}
	}

	return NULL;
}
