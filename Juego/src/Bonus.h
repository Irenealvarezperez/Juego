#pragma once

#include "ETSIDI.h"
using namespace ETSIDI;

class Bonus
{
private:
	long t0 = 0; //variables para controlar el tiempo en bonus
	long t1;
protected:
	float lado = 4;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	Sprite* bonus;
public:
	enum Tipo { BOTIQUIN, ESCUDO, ESPIRAL, VACUNA, MASCARILLAS, PAPEL };
	Tipo tipo;
	long getTime0() { return t0; };
	long getTime1() { return t1; };
	void setTime0(long t0) { this->t0 = t0; };
	void setTime1(long t1) { this->t1 = t1; };

public:
	//Bonus(const char* path,float x, float y, float ancho, float alto, Tipo tipo);
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