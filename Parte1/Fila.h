#ifndef FILA_H_
#define FILA_H_

//define o tipo fila
typedef struct fila Fila;

//cria uma fila
Fila* Cria_Fila();

//desaloca a fila
void Free_Fila(Fila* f);

//enfilera um elemento na fila
Fila* Enfilerar(Fila* f, int elem_info1, int elem_info2);

//desenfilera um elemento da fila
Fila* Desenfilerar(Fila* f);

//acessa parte x do elemento na frente da fila sem remove-lo. Retorna -1 senão encontrar elementos validos!
int Frente_x(Fila* f);
//acessa parte y do elemento na frente da fila sem remove-lo. Retorna -1 senão encontrar elementos validos!
int Frente_y(Fila* f);

//verifica se a fila está vazia
int Fila_Vazia(Fila* f);
#endif // !FILA_H_

