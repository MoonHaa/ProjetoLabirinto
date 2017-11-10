#ifndef PILHA_H_
#define PILHA_H_

//define o tipo pilha
typedef struct pilha Pilha;

//cria a pilha
Pilha* CriaPilha();

//destroi a pilha
void FreePilha(Pilha* p);

//empilha uma posicao (coordenadas x e y)
Pilha* Push(Pilha* p, int x, int y);

//desempilha uma posicao
Pilha* Pop(Pilha* p);

//acessa o valor x da posicao do topo da pilha sem remove-lo. Retorna -1 senão encontrar elemento valido.
int Topo_x(Pilha* p);

//acessa o valor y da posicao do topo da pilha sem remove-lo. Retorna -1 senão encontrar elemento valido.
int Topo_y(Pilha* p);

//verifica se a pilha está vazia
int PilhaVazia(Pilha* p);
#endif // !PILHA_H_

