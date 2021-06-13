#pragma once
#include "Enemigo.h"
class Contagiado:public Enemigo
{
public:
	Contagiado(float altura, float anchura, float x, float y, float vx, float vy);
	void dibuja();
};

