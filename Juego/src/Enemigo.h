#pragma once

#include "ListaDisparos.h"
#include "ObjetoMovil.h"

class Enemigo:public ObjetoMovil
{
protected:
	int vida = 1;
	float altura;
	float ancho = 4;
	ListaDisparos disparos;
	enum Tipo { LADRON };
	Tipo tipo;

public:
	Enemigo(float altura = 5.0, float x = 0.0, float y = 0.0, float vx = 0.0, float vy = 0.0);

	void setPos(float ix, float iy) { posicion.x = ix, posicion.y = iy, sprite->setPos(ix, iy); }; //enemigo
	void setVel(float vx, float vy) { velocidad.x = vx, velocidad.y = vy, sprite->setVel(vx, vy); } //enemigo
	virtual void dibuja();
	void mueve(float t);
	float getAncho() { return ancho; };
	void setTipo(Tipo tipo) { this->tipo = tipo; };

	friend class Interaccion;
	friend class Mundo;
};