#include "Personaje.h"
#include "freeglut.h"

void Personaje::setPos(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Personaje::dibuja()
{
	glPushMatrix();
	glColor3ub(0, 255, 0);
	glTranslatef(x, y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
}