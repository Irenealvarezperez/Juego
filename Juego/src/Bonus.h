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
	enum Tipo { BOTIQUIN, ESCUDO, ESPIRAL, VACUNA, MASCARILLAS, PAPEL };
	Tipo tipo;

public:
	Bonus(const char* path, float ancho, float alto);
	~Bonus();

	void dibuja();
	void mueve(float t);
	void setPos(float ix, float iy);
	void setVel(float vel_x, float vel_y);
	Vector2D getPos() { return posicion; };
	float getLado() { return lado; };
	void setTipo(Tipo tipo) { this->tipo = tipo; };
	Tipo getTipo() { return tipo; };
};