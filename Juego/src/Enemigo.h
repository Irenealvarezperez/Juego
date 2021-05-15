#pragma once

#include "ListaDisparos.h"
#include"ETSIDI.h"
using namespace ETSIDI;

class Enemigo
{
public:
	int vida = 1;
	const float alto = 4, ancho = 4;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	ListaDisparos disparos;
	Sprite* enemigo;

public:
	Enemigo(const char* path);

	void setPos(float ix, float iy);
	void dibuja();
	void mueve(float t);
	void setVel(float vel_x, float vel_y);
	Vector2D getPos() { return posicion; };
	float getLado() { return alto; };

	friend class Interaccion;
};