#include "Enemigo.h"
#include "freeglut.h"

Enemigo::Enemigo()
{
	enemigo = new Sprite("imagenes/enemigo.png", posicion.x, posicion.y, altura, altura);
}

void Enemigo::dibuja()
{
	enemigo->draw();
}

void Enemigo::mueve(float t)
{
	posicion = posicion - velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad - aceleracion * t;
}

Enemigo::Enemigo(float altura, float x, float y, float vx, float vy)
{
	this->altura=altura;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	enemigo = new Sprite("imagenes/enemigo.png", posicion.x, posicion.y, altura, altura);
}

void Enemigo::setPos(float ix, float iy)
{
	enemigo->setPos(ix, iy);
}