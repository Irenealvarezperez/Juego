#pragma once

#include "Suelo.h"
#include "Bonus.h"
#include "ListaEnemigos.h"
#include "ListaBonus.h"

class Mapa
{
private:
	static const int fila_max = 17;
	static const int columna_max = 80;
	Suelo suelo[fila_max + 1][columna_max + 1];
	char cad[fila_max + 1][columna_max + 1] = { 0 };
	int pantalla = 1;

public:
	void inicia(ListaBonus& bonus, ListaEnemigos &enemigos);
	void dibuja();
	const int getFila_Max() { return fila_max; };
	const int getColumna_Max() { return columna_max; };
	void setPantalla(int nivel) { pantalla = nivel; };
	friend class Interaccion;
};
