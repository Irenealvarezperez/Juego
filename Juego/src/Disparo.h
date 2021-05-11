#pragma once

#include "Vector2D.h"

class Disparo
{

public:
	Disparo();
	virtual ~Disparo();
private:
	float radio;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	Vector2D origen;
public:
	void dibuja();
	void mueve(float t);
	
	void setPos(float ix, float iy);
	void setVel(float vx, float vy);
	
	Vector2D getPos();

};

