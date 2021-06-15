#include "Minivirus.h"
Minivirus::Minivirus(float altura,float anchura, float x, float y, float vx, float vy) :Enemigo(altura,anchura, x, y, vx, vy)
{
	setTipo(MINIVIRUS);
	sprite = new SpriteSequence("imagenes/minivirus.png", 1, 1, 300, true, x, y, ancho, altura);
	sprite->setState(0, false);
	vida = 1;
	puntuacion = 1;
}

void Minivirus::dibuja() {
	Enemigo::dibuja();
	if (vida == 1)BarradeVida->setState(0, false);
	BarradeVida->setPos(posicion.x, posicion.y + altura / 2);
	BarradeVida->draw();
}