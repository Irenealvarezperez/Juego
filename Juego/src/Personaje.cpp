#include "Personaje.h"
#include "freeglut.h"

Personaje::Personaje()
{
	posicion.x = 2;
	posicion.y = 4;
}

void Personaje::setPos(double x, double y)
{
	posicion.x = x;
	posicion.y = y;
}

void Personaje::dibuja()
{
	glPushMatrix();
	glColor3ub(0, 255, 0);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 2);
	glPopMatrix();
}

void Personaje::mueve(double t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;

	if (posicion.x < 0)
	{
		posicion.x = 0;
	}
	if (posicion.y < 0)
	{
		posicion.y = 0;
	}
	if (posicion.y > 46)
	{
		posicion.y = 46;
	}
}