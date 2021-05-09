#pragma once

#include "Plataforma.h"

class Personaje
{
private:
	double radio = 2;
public:
	double x = 0, y = 0, z = 0;
	void dibuja();
	void setPos(double x, double y);
};

