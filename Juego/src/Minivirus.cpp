#include "Minivirus.h"
Minivirus::Minivirus(float altura,float anchura, float x, float y, float vx, float vy) :Enemigo(altura,anchura, x, y, vx, vy)
{
	setTipo(MINIVIRUS);
	sprite = new SpriteSequence("imagenes/minivirus.png", 1, 1, 300, true, x, y, ancho, altura);
	sprite->setState(0, false);
}

void Minivirus::dibuja() {
	Enemigo::dibuja();
}