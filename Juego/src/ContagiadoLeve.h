#pragma once
#include "Enemigo.h"
class ContagiadoLeve:public Enemigo
{
public:
	ContagiadoLeve(float altura, float anchura, float x, float y, float vx, float vy);
	void dibuja();
};

