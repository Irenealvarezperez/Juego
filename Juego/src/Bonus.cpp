#include "Bonus.h"
#include <stdlib.h>
#include "freeglut.h"

Bonus::Bonus(const char* path, float ancho, float alto)
{
	bonus = new Sprite(path, posicion.x, posicion.y, ancho, alto);
	setVel(5, 5);
}

Bonus::~Bonus() {}

void Bonus::dibuja()
{
	bonus->draw();
}

void Bonus::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;

	setPos(posicion.x, posicion.y);
	setVel(velocidad.x, velocidad.y);
}

void Bonus::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
	bonus->setPos(x, y);
}
void Bonus::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
	bonus->setVel(vx, vy);
}