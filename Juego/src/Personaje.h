#pragma once

#include "ListaDisparos.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"

using namespace ETSIDI;

class Personaje : public ObjetoMovil
{
private:
	float lado = 2.99;
	int vida = 3;
	bool escudo = false;
public:
	ListaDisparos disparos;

	Personaje();

	void dibuja();
	void mueve(float t);
	void dispara(float vx, float vy, float flip);
	float getLado() { return lado; };
	friend class Interaccion;
	friend class Mundo;
};