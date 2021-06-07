#pragma once

#include "ListaDisparos.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"

using namespace ETSIDI;

class Personaje : public ObjetoMovil
{
private:
	int vida = 5;
	float lado = 4;
	bool escudo = false;
	int duracionEscudo = 2;
	char tecla_bloq = 0;
public:
	ListaDisparos disparos;
	

	Personaje();

	void dibuja();
	void mueve(float t);
	void dispara(float vx, float vy, float flip);
	float getLado() { return lado; };
	int getVida() { return vida; };
	void setVida(int vida) { this->vida = vida; };
	void setEscudo(bool Escudo) { this->escudo = Escudo; };
	bool getEscudo() { return escudo; };
	void restaDuracionEscudo() { this->duracionEscudo - 1; };
	int getDuracionEscudo() { return duracionEscudo; };

	friend class Interaccion;
	friend class Mundo;
};