#pragma once

#include "Vector2D.h"

class Personaje
{
private:
	float radio = 2;
public:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	Personaje();

	void dibuja();
	void setPos(float x, float y);
	void mueve(float t);
};