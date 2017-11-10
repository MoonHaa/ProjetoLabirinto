#include "Imagem.h"
#include <stdio.h>
#include <malloc.h>
#include "Fila.h"

void AbreImagem(char* arquivo, int *** matriz, int * linha, int * coluna)
{
	//variaveis auxiliares
	int i, j;

	//abre o arquivo
	FILE* imagem = fopen(arquivo, "r");

	//palavra chave do arquivo
	char* keyword = (char *)malloc(3*sizeof(char));

	fscanf(imagem, "%s", keyword);

	//numero de coluna e linhas da imagem
	fscanf(imagem, "%i %i", coluna, linha);

	//alocando a matriz
	(*matriz) = (int **)malloc(*linha * sizeof(int*));

	for (i = 0; i < *linha; i++)
		(*matriz)[i] = (int *)malloc(*coluna * sizeof(int));

	//le a imagem
	for (i = 0; i < *linha; i++)
		for (j = 0; j < *coluna; j++)
			fscanf(imagem, "%i", &(*matriz)[i][j]);

	//fecha o arquivo e encerra a função
	free(keyword);
	fclose(imagem);
	return;
}

int ProcessaImagem(int ** matriz, int linha, int coluna)
{
	//contador de objetos
	int count = 0;

	//variaveis auxiliares
	int i, j;

	//percorre a imagem atras de pixels pretos não visitados
	for(i = 0; i< linha;i++)
		for (j = 0; j < coluna; j++)
		{
			if (matriz[i][j] == 1) //pixel preto
			{
				matriz[i][j] += 99; //marca como visitado

				Fila* f = Cria_Fila(); //fila de pixels
				
				f = f = Enfilerar(f, i, j); //enfilera pixel

				while (!Fila_Vazia(f)) //enquanto a fila não estiver vazia
				{
					int x = Frente_x(f); //guarda as posiçoes do pixel
					int y = Frente_y(f);

					f = Desenfilerar(f); //remove o pixel da fila

					//verifica vizinha 4 por pixels pretos não visitados, caso encontre, enfilera o pixel e marca como visitado
					
					if (matriz[x + 1][y] == 1)
					{
						matriz[x + 1][y] += 99;
						f = Enfilerar(f, x + 1, y);
					}

					if (matriz[x - 1][y] == 1)
					{
						matriz[x - 1][y] += 99;
						f = Enfilerar(f, x - 1, y);
					}

					if (matriz[x][y + 1] == 1)
					{
						matriz[x][y + 1] += 99;
						f = Enfilerar(f, x, y + 1);
					}

					if (matriz[x][y - 1] == 1)
					{
						matriz[x][y - 1] += 99;
						f = Enfilerar(f, x, y - 1);
					}
				}

				Free_Fila(f); //desfaz a fila de pixels

				count++; //objeto encontrado!
			}
		}

	//retorna o valor de objetos encontrados
	return count;
}
