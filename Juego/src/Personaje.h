#pragma once

#include "ListaDisparos.h"
#include "ETSIDI.h"
using namespace ETSIDI;

class Personaje
{
private:
	float lado = 4;
	int vida = 3;
	bool escudo = false;
	SpriteSequence* sprite;

public:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	ListaDisparos disparos;

	Personaje();

	void dibuja();
	void setPos(float x, float y);
	void setVel(float vx, float vy);
	void mueve(float t);
	void dispara(float vx, float vy, float flip);
	float getLado() { return lado; };
	Vector2D getPos() { return posicion; };
	friend class Interaccion;
	friend class Mundo;
};