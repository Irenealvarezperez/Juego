#include "Personaje.h"
#include "freeglut.h"

Personaje::Personaje()
{
	posicion.x = 2;
	posicion.y = 4;
}

void Personaje::setPos(float x, float y)
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

	disparos.dibuja();
}

void Personaje::mueve(float t)
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

	disparos.mueve(t);
}

void Personaje::dispara(float vx, float vy)
{
	Disparo* d = new Disparo();
	d->setPos(posicion.x, posicion.y);
	d->setVel(vx, vy);
	disparos.agregar(d);
}