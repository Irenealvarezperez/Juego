#pragma once

#include "Suelo.h"
#include "Personaje.h"
#include "Mapa.h"

class Mundo
{
public:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Mapa nivel;
	Personaje personaje;

public:
	void Tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void Inicializa();
	void Mueve();
	void Dibuja();
};