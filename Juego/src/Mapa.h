#pragma once

#include "Suelo.h"
#include "Bonus.h"
#include "ListaEnemigos.h"
#include "ListaBonus.h"

class Mapa
{
public:
	static const int fila_max = 17;
	static const int columna_max = 80;
	Suelo suelo[fila_max + 1][columna_max + 1];
	char cad[fila_max + 1][columna_max + 1] = { 0 };

public:
	void inicia(int nivel, ListaBonus& bonus, ListaEnemigos &enemigos);
	void dibuja();
};
