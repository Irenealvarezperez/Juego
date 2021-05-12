#pragma once

#include "Suelo.h"
#include "Personaje.h"
#include "Mapa.h"
#include "Disparo.h"
#include "ListaDisparos.h"
#include "Bonus.h"

class Mundo
{
public:
	Mapa nivel;
	Personaje personaje;
	Disparo disparo;
	ListaDisparos disparos;
	Bonus bonus;
	void Tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void Inicializa();
	void Mueve();
	void Dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;

	
};