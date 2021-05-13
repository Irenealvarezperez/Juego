#include "Bonus.h"
#include <stdlib.h>
#include "freeglut.h"

Bonus::Bonus(const char* path)
{
	bonus = new Sprite(path, posicion.x, posicion.y, 6, 6);
	bonus->setPos(posicion.x, posicion.y);
	bonus->setVel(0, 0);
}

Bonus::~Bonus() {}

void Bonus::Dibuja()
{
	bonus->draw();
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