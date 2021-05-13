#pragma once

#include "Suelo.h"
#include "Personaje.h"
#include "Mapa.h"
#include "Enemigo.h"

class Mundo
{
public:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Mapa nivel;
	Personaje personaje;
	Enemigo enemigo;

public:
	void Tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void Inicializa();
	void Mueve();
	void Dibuja();
};