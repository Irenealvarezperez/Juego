#include "ListaSuelos.h"

ListaSuelos::ListaSuelos()
{
	numero = 0;
	for (int i = 0; i < MAX_SUELOS; i++)
		lista[i] = 0;//punteros a 0
}

ListaSuelos::~ListaSuelos()
{
	destruirContenido();
}

bool ListaSuelos::agregar(Suelo* s)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == s)//enemigo ya existente
			return false;

	if (numero < MAX_SUELOS)
		lista[numero++] = s; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}

void ListaSuelos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaSuelos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de enemigos contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void ListaSuelos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaSuelos::eliminar(Suelo* s)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == s)
		{
			eliminar(i);
			return;
		}
}
