#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo()
{
	disparo = new Sprite("imagenes/bala.png", posicion.x, posicion.y, lado, lado);
}

Disparo::~Disparo() {}

void Disparo::dibuja()
{
	disparo->draw();
}

void Disparo::mueve(float t)
{
	//posicion = disparo->getPos(); //Sobra,comprobado
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;

	setPos(posicion.x, posicion.y);
	setVel(velocidad.x, velocidad.y);
}

void Disparo::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
	disparo->setPos(ix, iy);
}

void Disparo::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
	disparo->setVel(vx, vy);
}
