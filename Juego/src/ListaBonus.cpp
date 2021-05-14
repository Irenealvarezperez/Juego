#include "ListaBonus.h"

ListaBonus::ListaBonus()
{
	numero = 0;
	for (int i = 0; i < max_bonus; i++) {
		lista[i] = 0;
	}
}

bool ListaBonus::agregar(Bonus* b)
{
	if (numero < max_bonus)
	{
		lista[numero++] = b;
	}
	else return false;
	return true;
}

Bonus* ListaBonus::setBonus(const char* path, float x, float y, float ancho, float alto)
{
	Bonus* bonus = new Bonus(path, ancho, alto);
	bonus->setPos(x, y);
	return bonus;
}

void ListaBonus::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaBonus::dibuja()
{
	for (int i = 0; i < numero; i++) {
		lista[i]->dibuja();
	}
}

ListaBonus::~ListaBonus() {
	destruirContenido();
}