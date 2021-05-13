#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo()
{
	sprite_disparo = new Sprite("imagenes/bala.png", posicion.x, posicion.y, 2.5, 1.5);
	sprite_disparo->setPos(2, 4);
	sprite_disparo->setVel(0, 0);
}

Disparo::~Disparo() {}

void Disparo::dibuja()
{
	sprite_disparo->draw();
}

void Disparo::mueve(float t)
{
	posicion = sprite_disparo->getPos();
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	sprite_disparo->setPos(posicion.x, posicion.y);
	sprite_disparo->setVel(velocidad.x, velocidad.y);
}

void Disparo::setPos(float ix, float iy) {
	sprite_disparo->setPos(ix, iy);
}

void Disparo::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

Vector2D Disparo::getPos() {
	return posicion;
}