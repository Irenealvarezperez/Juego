#include "ListaEnemigos.h"
#include"Interaccion.h"

ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		lista[i] = 0;//punteros a 0
}

ListaEnemigos::~ListaEnemigos()
{
	destruirContenido();
}

bool ListaEnemigos::agregar(Enemigo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)//enemigo ya existente
			return false;

	if (numero < MAX_ENEMIGOS)
		lista[numero++] = e; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}

void ListaEnemigos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaEnemigos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaEnemigos::rebote()
{
	for (int i = 0; i < numero - 1; i++)
	{
		for (int j = i + 1; j < numero; j++)
		{
			Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}

void ListaEnemigos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de enemigos contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void ListaEnemigos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaEnemigos::eliminar(Enemigo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}