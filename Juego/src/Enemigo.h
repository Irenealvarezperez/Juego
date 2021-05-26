#pragma once

#include "ListaDisparos.h"
#include"ETSIDI.h"
#include "ObjetoMovil.h"
using namespace ETSIDI;

class Enemigo:public ObjetoMovil
{
protected:
	int vida = 1;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float altura;
	float ancho = 4;
	ListaDisparos disparos;

public:
	Enemigo();
	Enemigo(float altura = 5.0, float x = 0.0, float y = 0.0, float vx = 0.0, float vy = 0.0);

	void setPos(float ix, float iy) { posicion.x = ix, posicion.y = iy, sprite->setPos(ix, iy); }; //enemigo
	void setVel(float vx, float vy) { velocidad.x = vx, velocidad.y = vy, sprite->setVel(vx, vy); } //enemigo
	virtual void dibuja();
	void mueve(float t);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	float getAncho() { return ancho; };

	friend class Interaccion;
};