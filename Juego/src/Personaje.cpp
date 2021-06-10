#include "Personaje.h"
#include"VariablesGlobales.h"


Personaje::Personaje()
{
	sprite = new SpriteSequence("imagenes/personaje2.png", 8, 5, 300, true, posicion.x, posicion.y, lado*2, lado*1.5, 6);

	//BarradeVida = new SpriteSequence("imagenes/barradevida.png", 3, 3, 100, true, x_ojo-42,46, 15,2,0);
	BarradeVida = new SpriteSequence("imagenes/barradevida.png", 3, 3, 100, true, posicion.x, posicion.y + lado / 2, 6, 1, 0);
	setPos(2, 4);
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
	if (velocidad.y > 0.0000001) {
		if (sprite->getState() < 7 || sprite->getState() > 8) sprite->setState(7, false);
	}
	if (velocidad.y < -0.000001) {
		if (sprite->getState() < 7 || sprite->getState() > 8) sprite->setState(7, false);
	}

	if (vida == 5)BarradeVida->setState(0, false);
	else if (vida == 4)BarradeVida->setState(2, false);
	else if (vida == 3)BarradeVida->setState(4, false);
	else if (vida == 2)BarradeVida->setState(6, false);
	else if (vida == 1)BarradeVida->setState(7, false);
	BarradeVida->setPos(posicion.x, posicion.y + lado / 2);
	BarradeVida->draw();

	sprite->draw();

	disparos.dibuja();
}

void Personaje::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	
	if (posicion.x < 0) { posicion.x = 0; }
	if (posicion.y < 0) { posicion.y = 0; }
	if (posicion.y > 46) { posicion.y = 46; }

	sprite->loop();

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