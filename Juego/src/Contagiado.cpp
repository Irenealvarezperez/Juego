#include "Contagiado.h"

Contagiado::Contagiado(float altura, float anchura, float x, float y, float vx, float vy) :Enemigo(altura, anchura, x, y, vx, vy)
{
	setTipo(CONTAGIADO);
	sprite = new SpriteSequence("imagenes/zombie.png", 1, 1, 300, true, x, y, anchura, altura * 1.25);
	vida = 2;
}

void Contagiado::dibuja()
{
	Enemigo::dibuja();
	sprite->flip(true, false);

	if (vida == 2)BarradeVida->setState(0, false);
	else if (vida == 1)BarradeVida->setState(4, false);
	BarradeVida->setPos(posicion.x, posicion.y + altura / 2);
	BarradeVida->draw();
}