#pragma once

class Personaje
{
private:
	double radio = 2;
public:
	double px = 40, py = 5, pz = 0;
	double vx = 0, vy = 0, vz = 0;
	double ax = 0, ay = 0, az = 0;
	void dibuja();
	void setPos(double x, double y);
	void mueve(double t);
};

