#pragma once

#include "ListaDisparos.h"
#include "ETSIDI.h"
using namespace ETSIDI;

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
	Sprite* sprite;
	ListaDisparos disparos;

public:
	Personaje();

	void dibuja();
	void setPos(float x, float y);
	void mueve(float t);
	void dispara(float vx, float vy, float flip);
};