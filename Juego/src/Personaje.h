#pragma once

#include "Vector2D.h"

class Personaje
{
private:
	float radio = 2;
public:
	Personaje();
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	void dibuja();
	void setPos(double x, double y);
	void mueve(double t);
};

