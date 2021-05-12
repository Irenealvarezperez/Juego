#pragma once

#include "Vector2D.h"

class Bonus
{
private:
	float lado;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	Bonus();
	virtual ~Bonus();

	void Dibuja();
	void Mueve(float t);
	void setPos(float ix, float iy);
};