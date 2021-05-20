#include "Personaje.h"
#include"VariablesGlobales.h"

Personaje::Personaje()
{
	sprite = new SpriteSequence("imagenes/personaje2.png", 8, 5, 300, true, posicion.x, posicion.y, lado*2, lado*2, 6);
	setPos(2, 6);
	aceleracion.y = -3;
	aceleracion.x = -0.5;
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
		sprite->flip(false, false);
		if ( sprite->getState() > 6) sprite->setState(0, false);
	}
	if (velocidad.x < -0.01) {
		sprite->flip(true, false);
		if ( sprite->getState()>6) sprite->setState(0, false);
	}
	if (velocidad.x <= 0.01 && velocidad.x>= -0.01 && velocidad.y>= -0.01 && velocidad.y<=0.01) sprite->setState(12, false);
	if (velocidad.y > 0.01) {
		if (sprite->getState() < 6 || sprite->getState() > 10) sprite->setState(6, false);
	}

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