#include "GranVirus.h"
GranVirus::GranVirus(float altura, float anchura, float x, float y, float vx, float vy) :Enemigo(altura, anchura, x, y, vx, vy)
{
	setTipo(GRANVIRUS);
	sprite = new SpriteSequence("imagenes/virus.png", 1, 1, 300, true, x, y, anchura, altura);
	sprite->setState(0, false);
}

void GranVirus::dibuja() {
	Enemigo::dibuja();
}