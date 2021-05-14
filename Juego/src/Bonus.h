#pragma once

#include "ETSIDI.h"
using namespace ETSIDI;

class Bonus
{
protected:
	float lado = 4;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	Sprite* bonus;

public:
	Bonus(const char* path);
	~Bonus();

	void dibuja();
	void mueve(float t);
	void setPos(float ix, float iy);
};