#include "Ladron.h"

Ladron::Ladron(float altura, float x, float y, float vx, float vy) :Enemigo(altura, x, y, vx, vy)
{
	setTipo(LADRON);
	sprite = new SpriteSequence("imagenes/ladron2.png", 6, 1, 300, true, x, y, ancho*1.5, altura*1.25);
}

void Ladron::dibuja()
{
	Enemigo::dibuja();
	sprite->flip(true, false);
	//if (sprite->getState() > 5)sprite->setState(0, false);

	//disparos.dibuja();
}

void Ladron::dispara(float vx, float vy, float flip)
{
	Disparo* d = new Disparo();

	d->setPos(static_cast<float>(posicion.x), static_cast<float>(posicion.y));
	d->setVel(vx, vy);
	disparos.agregar(d, flip);
	disparos.dibuja();
}