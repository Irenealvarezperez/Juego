#include "Personaje.h"
#include "freeglut.h"

void Personaje::setPos(double x, double y)
{
	this->px = x;
	this->py = y;
}

void Personaje::dibuja()
{
	glPushMatrix();
	glColor3ub(0, 255, 0);
	glTranslatef(px, py, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
}

void Personaje::mueve(double t)
{
	px = px + vx * t + 0.5f * ax * t * t;
	py = py + vy * t + 0.5f * ay * t * t;
	vx = vx + ax * t;
	vy = vy + ay * t;
}