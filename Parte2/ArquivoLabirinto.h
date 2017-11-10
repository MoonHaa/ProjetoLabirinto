#ifndef ARQUIVO_LABIRINTO_H_
#define ARQUIVO_LABIRINTO_H_
#include "Pilha.h"

//abre o arquivo e monta o labirinto em uma matriz, retornando a matriz e seus limites nos parametros da função
void AbreLabirinto(char* arquivo, char*** labirinto, int* linha, int* coluna);

//Processa o labirinto e encontra o resultado, o retornando como uma pilha de posições
Pilha* ProcessaLabirinto(char** labirinto, int linha, int coluna);

#endif // !ARQUIVO_LABIRINTO_H_

