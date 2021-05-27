#include"Murcielago.h"
Murcielago::Murcielago(float altura, float x, float y, float vx, float vy) :Enemigo(altura, x, y, vx, vy)
{
	setTipo(MURCIELAGO);
	sprite = new SpriteSequence("imagenes/Murcielago.png", 6, 1, 300, true, x, y, ancho, altura);
}

void Murcielago::dibuja()
{
	Enemigo::dibuja();
	sprite->flip(true, false);
	//if (sprite->getState() > 5)sprite->setState(0, false);

	
}

void Murcielago::dispara(float vx, float vy, float flip)
{
	Disparo* d = new Disparo();

	d->setPos(static_cast<float>(posicion.x), static_cast<float>(posicion.y));
	d->setVel(vx, vy);
	disparos.agregar(d, flip);
	disparos.dibuja();
}