#pragma once

#include "Bonus.h"
#define max_bonus 10

class ListaBonus
{
public:
	Bonus* lista[max_bonus];
	int numero;

public:
	ListaBonus();
	virtual ~ListaBonus();

	bool agregar(Bonus* b);
	Bonus* setBonus(const char* path, float x, float y);
	void destruirContenido();
	void dibuja();
};