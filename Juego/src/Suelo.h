#pragma once

#include "ETSIDI.h"
using namespace ETSIDI;
class Suelo
{
private:
	Sprite* sprite;

public:
	Vector2D posicion;
	static const int lado = 3;
	Vector2D limite1;
	Vector2D limite2;

public:
	Suelo(int x, int y, int indice);

	void dibuja();
	void setPos(int x, int y);
	Vector2D getPos() { return posicion; };
	static const int getLado() { return lado; };
	float distancia(Vector2D punto, Vector2D* direccion = 0);
	friend class Interaccion;
};