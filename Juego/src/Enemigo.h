#pragma once

#include "ListaDisparos.h"
#include"ETSIDI.h"
using namespace ETSIDI;

class Enemigo
{
public:
	int vida = 1;
	float altura = 4, ancho = 4;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	ListaDisparos disparos;
	Sprite* enemigo;

public:
	Enemigo();
	Enemigo(float altura = 5.0, float x = 0.0, float y = 0.0, float vx = 0.0, float vy = 0.0);

	void setPos(float ix, float iy);
	void dibuja();
	void mueve(float t);
	void setVel(float vel_x, float vel_y);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	Vector2D getPos() { return posicion; };
	float getLado() { return altura; };

	friend class Interaccion;
};