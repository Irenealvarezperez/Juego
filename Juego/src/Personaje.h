#pragma once

#include "Vector2D.h"
#include "ListaDisparos.h"

class Personaje
{
private:
	float radio = 2;
	int vida = 3;
	bool escudo = false;

public:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	ListaDisparos disparos;

public:
	Personaje();

	void dibuja();
	void setPos(float x, float y);
	void mueve(float t);
	void dispara(float vx, float vy);
};