#include "Bonus.h"
#include <stdlib.h>
#include "freeglut.h"

Bonus::Bonus()
{
	lado = 1.5f;
	aceleracion.y = -9.8f;
}

Bonus::~Bonus() {}

void Bonus::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);
	glutSolidCube(lado);
	glPopMatrix();
}

void Bonus::Mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Bonus::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}