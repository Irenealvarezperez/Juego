#pragma once

#include "Plataforma.h"
#include "Suelo.h"
#include "Personaje.h"

class Mundo
{
public:
	Plataforma base;
	Plataforma plataforma1, plataforma2;
	Personaje personaje;
	void Tecla(unsigned char key);
	void Inicializa();
	void Mueve();
	void Dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
};