#include "Bonus.h"
#include <stdlib.h>
#include "freeglut.h"

Bonus::Bonus(const char* path, float ancho, float alto)
{
	bonus = new Sprite(path, posicion.x, posicion.y, ancho, alto);
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
}

void Bonus::setPos(float ix, float iy)
{
	bonus->setPos(ix, iy);
}	