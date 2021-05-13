#pragma once

#include "ETSIDI.h"
using namespace ETSIDI;

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