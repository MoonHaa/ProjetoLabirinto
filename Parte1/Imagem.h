#ifndef IMAGEM_H_
#define IMAGEM_H_

//abre uma imagem pbm e monta a matriz correspondente, retornando a matriz e os seus limites nos parametros da função
void AbreImagem(char* arquivo, int*** matriz, int* linha, int* coluna);

//processa a imagem e conta o numero de objetos conexos usando vizinhança 4
int ProcessaImagem(int** matriz, int linha, int coluna);

#endif // !IMAGEM_H_
