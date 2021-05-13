#pragma once

#include "Suelo.h"
#include "Personaje.h"
#include "Mapa.h"
#include "ListaEnemigos.h"
#include "ListaBonus.h"

class Mundo
{
public:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Mapa nivel;
	Personaje personaje;
	//Bonus bonus[max_bonus];
	ListaBonus bonus;
	ListaEnemigos enemigos;

public:
	void Tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void Inicializa();
	void Mueve();
	void Dibuja();
};