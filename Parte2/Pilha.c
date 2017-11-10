#include "Pilha.h"
#include <malloc.h>

struct pilha
{
	int x;
	int y;
	Pilha* proximo;
};

Pilha * CriaPilha()
{
	return NULL;
}

void FreePilha(Pilha * p)
{
	while (p != NULL)
	{
		Pilha* aux = p->proximo;
		free(p);
		p = aux;
	}
}

Pilha * Push(Pilha * p, int x, int y)
{
	Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
	novo->x = x;
	novo->y = y;
	novo->proximo = p;
	return novo;
}

Pilha * Pop(Pilha * p)
{
	if (!PilhaVazia(p))
	{
		Pilha* aux = p->proximo;
		free(p);
		return aux;
	}
	else
		return NULL;
}

int Topo_x(Pilha * p)
{
	if (!PilhaVazia(p))
		return p->x;

	return -1;
}

int Topo_y(Pilha * p)
{
	if (!PilhaVazia(p))
		return p->y;

	return -1;
}

int PilhaVazia(Pilha * p)
{
	return (p == NULL);
}
