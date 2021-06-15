#pragma once

#include "ListaDisparos.h"
#include "ObjetoMovil.h"
#include "VariablesGlobales.h"

class Enemigo:public ObjetoMovil
{
protected:
	int vida;
	float altura;
	float ancho = 4;
	ListaDisparos disparos;
	enum Tipo { LADRON, MURCIELAGO, MINIVIRUS, GRANVIRUS, CONTAGIADO };
	Tipo tipo;
	int puntuacion;
	long t0 = 0;
	long t1;

public:
	Enemigo(float altura = 5.0,float anchura=5.0, float x = 0.0, float y = 0.0, float vx = 0.0, float vy = 0.0);

	void dispara(float vx, float vy, float flip);
	void setPos(float ix, float iy) { posicion.x = ix, posicion.y = iy, sprite->setPos(ix, iy); }; //enemigo
	void setVel(float vx, float vy) { velocidad.x = vx, velocidad.y = vy, sprite->setVel(vx, vy); }; //enemigo
	virtual void dibuja();
	void mueve(float t);
	float getAncho() { return ancho; };
	void setTipo(Tipo tipo) { this->tipo = tipo; };
	Tipo getTipo() { return tipo; };
	long getTime0() { return t0; };
	long getTime1() { return t1; };
	void setTime0(long t0) { this->t0 = t0; };
	void setTime1(long t1) { this->t1 = t1; };

	friend class Interaccion;
	friend class Mundo;
};