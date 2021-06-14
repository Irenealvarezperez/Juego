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
	bool escudo ;
	int duracionEscudo ;
	char tecla_bloq ;
	bool invencible; //si ha usado la espiral
	bool papel;//true si ha cogido el papel necesario para pasar de nivel
public:
	ListaDisparos disparos;
	

	Personaje();

	void dibuja();
	void mueve(float t);
	void dispara(float vx, float vy, float flip);
	float getLado() { return lado; };
	int getVida() { return vida; };
	void setVida(int vida) { this->vida = vida; };
	void setEscudo(bool Escudo);
	bool getEscudo() { return escudo; };
	void restaDuracionEscudo() { duracionEscudo -= 1; };
	int getDuracionEscudo() { return duracionEscudo; };
	bool Condicion();
	void setPapel() { papel = true; };
	void reiniciar();

	friend class Interaccion;
	friend class Mundo;
};