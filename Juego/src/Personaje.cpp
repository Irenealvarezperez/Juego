#include "Personaje.h"
#include"VariablesGlobales.h"

Personaje::Personaje()
{
	sprite = new SpriteSequence("imagenes/personaje.png", 5, 4, 200, true, posicion.x, posicion.y, lado, lado, 6);
	setPos(2, 4);
}

void Personaje::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
	sprite->setPos(x, y);
}

void Personaje::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
	sprite->setVel(vx, vy);
}

void Personaje::dibuja()
{
	if (velocidad.x > 0.01) {
		if (sprite->getState() < 5 || sprite->getState() > 8) sprite->setState(5, false);
	}
	if (velocidad.x < -0.01) {
		if (sprite->getState() < 1 || sprite->getState()>4) sprite->setState(1, false);
	}
	if (velocidad.x <= 0.01 && velocidad.x >= -0.01) sprite->setState(6, false);

	sprite->draw();

	disparos.dibuja();
}

void Personaje::mueve(float t)
{
	//posicion=sprite->getPos(); //Sobra, comprobado
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;

	sprite->loop();

	if (posicion.x < 0) { posicion.x = 0; }
	if (posicion.y < 0) { posicion.y = 0; }
	if (posicion.y > 46) { posicion.y = 46; }
	setPos(posicion.x, posicion.y);
	setVel(velocidad.x, velocidad.y);

	disparos.mueve(t);
}

void Personaje::dispara(float vx, float vy, float flip)
{
	Disparo* d = new Disparo();

	d->setPos(posicion.x, posicion.y);
	d->setVel(vx, vy);
	disparos.agregar(d, flip);
}