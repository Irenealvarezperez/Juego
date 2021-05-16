#pragma once

#include "ETSIDI.h"
using namespace ETSIDI;

class Bonus
{
protected:
	float lado;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	Sprite* bonus;

public:
	Bonus(const char* path, float ancho, float alto);
	~Bonus();

	void dibuja();
	void mueve(float t);
	void setPos(float ix, float iy);
	void setVel(float vel_x, float vel_y);
};