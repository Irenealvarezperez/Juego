#pragma once

#include "Suelo.h"
#include "Personaje.h"
#include "Mapa.h"
#include "ListaEnemigos.h"
#include "ListaBonus.h"
#include "VariablesGlobales.h"
#include "Interaccion.h"

class Mundo
{
private:
	const float y_ojo = ALTO_PANTALLA / 35.0, z_ojo = 60.0f, y_pto_ojo = ALTO_PANTALLA / 35.0, z_pto_ojo = 0.0;
	Mapa nivel;
	Personaje personaje;
	//Bonus bonus[max_bonus];
	ListaBonus bonus;
	ListaEnemigos enemigos;

public:
	float x_ojo, x_pto_ojo;
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();
};