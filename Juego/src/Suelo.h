#pragma once

#include "ETSIDI.h"
using namespace ETSIDI;
class Suelo
{
private:
	Sprite* personaje;

public:
	Vector2D posicion;
	int lado = 3;
	Vector2D limite1;
	Vector2D limite2;

public:
	Suelo();

	void dibuja();
	void setPos(int x, int y);
	float distancia(Vector2D punto, Vector2D* direccion = 0);
	friend class Interaccion;
};