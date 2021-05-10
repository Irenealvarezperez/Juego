#pragma once

#include "Plataforma.h"

class Personaje
{
private:
	double radio = 2;
public:
	double px = 0, py = 0, pz = 0;
	double vx = 0, vy = 0, vz = 0;
	double ax = 0, ay = -9.81, az = 0;
	void dibuja();
	void setPos(double x, double y);
	void mueve(double t);
};

