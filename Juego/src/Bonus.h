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
public:
	Sprite* bonus;

public:
	Bonus(const char* path);
	virtual ~Bonus();

	int numero = 0;

	void Dibuja();
	void Mueve(float t);
	void setPos(float ix, float iy);
};