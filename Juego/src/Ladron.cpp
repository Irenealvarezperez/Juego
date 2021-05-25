#include "Ladron.h"
Ladron::Ladron(float altura, float x, float y, float vx, float vy) :Enemigo(altura, x, y, vx, vy)
{
	sprite = new SpriteSequence("imagenes/ladron.png", 6, 1, 300, true, x, y, ancho, altura);
}

void Ladron::dibuja()
{
	Enemigo::dibuja();
	sprite->flip(true, false);
	if (sprite->getState() > 5)sprite->setState(0, false);
}
