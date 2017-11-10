#include "Fila.h"
#include <malloc.h>

struct fila
{
	int x, y;
	struct fila *proximo;
};

Fila * Cria_Fila()
{
	return NULL;
}

void Free_Fila(Fila * f)
{
	while (f != NULL)
	{
		Fila* aux = f->proximo;
		free(f);
		f = aux;
	}
}

Fila * Enfilerar(Fila * f, int elem_info1, int elem_info2)
{
	Fila* novo = (Fila*)malloc(sizeof(Fila));
	novo->x = elem_info1;
	novo->y = elem_info2;
	novo->proximo = NULL;

	Fila* aux, *fim = NULL;

	for (aux = f; aux != NULL; aux = aux->proximo)
		fim = aux;

	if (fim != NULL)
	{
		fim->proximo = novo;
		return f;
	}
	else
		return novo;
}

Fila * Desenfilerar(Fila * f)
{
	if (!Fila_Vazia(f))
	{
		Fila* aux = f->proximo;
		free(f);
		return aux;
	}
	else
		return NULL;
}

int Frente_x(Fila * f)
{
	if (!Fila_Vazia(f))
		return f->x;
	else
		return -1;
}

int Frente_y(Fila * f)
{
	if (!Fila_Vazia(f))
		return f->y;
	else
		return -1;
}

int Fila_Vazia(Fila * f)
{
	return (f == NULL);
}
