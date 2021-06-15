#pragma once

#include "ETSIDI.h"
using namespace ETSIDI;

class Disparo
{
private:
	float lado = 2.5;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	Vector2D origen;

public:
	Sprite* disparo;
	Disparo();
	~Disparo();

	void dibuja();
	void mueve(float t);
	void setPos(float ix, float iy);
	void setVel(float vx, float vy);
	Vector2D getPos() { return posicion; };
};