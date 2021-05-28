#include"Murcielago.h"
Murcielago::Murcielago(float altura, float x, float y, float vx, float vy) :Enemigo(altura, x, y, vx, vy)
{
	setTipo(MURCIELAGO);
	sprite = new SpriteSequence("imagenes/murcielago2.png", 4, 4, 300, true, x, y, ancho, altura);
	sprite->setState(9, false);
}

void Murcielago::dibuja()
{	
	if (velocidad.x > 0.01) {
		sprite->flip(false, false);
		if (sprite->getState() > 11) sprite->setState(9, false);
	}
	if (velocidad.x < -0.01) {
		sprite->flip(true, false);
		if (sprite->getState() > 11) sprite->setState(9, false);
	}
	Enemigo::dibuja();
}

void Murcielago::dispara(float vx, float vy, float flip)
{
	Disparo* d = new Disparo();

	d->setPos(static_cast<float>(posicion.x), static_cast<float>(posicion.y));
	d->setVel(vx, vy);
	disparos.agregar(d, flip);
	disparos.dibuja();
}