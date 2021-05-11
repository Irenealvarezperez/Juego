#pragma once

#include "Suelo.h"

class Mapa
{
private:

public:
	static const int fila_max = 17;
	static const int columna_max = 40;
	Suelo suelo[fila_max + 1][columna_max + 1];
	char cad[fila_max + 1][columna_max + 1] = { 0 };
	void iniciar_nivel(int nivel);
	void dibuja();
};

