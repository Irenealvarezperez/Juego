#include "ContagiadoLeve.h"

ContagiadoLeve::ContagiadoLeve(float altura, float anchura, float x, float y, float vx, float vy) :Enemigo(altura, anchura, x, y, vx, vy)
{
	setTipo(CONTAGIADOLEVE);
	sprite = new SpriteSequence("imagenes/zombie.png", 1, 1, 300, true, x, y, anchura, altura * 1.5);
	vida = 2;
}

void ContagiadoLeve::dibuja()
{
	Enemigo::dibuja();
	sprite->flip(true, false);

	if (vida == 2)BarradeVida->setState(0, false);
	else if (vida == 1)BarradeVida->setState(4, false);
	BarradeVida->setPos(posicion.x, posicion.y + altura / 2);
	BarradeVida->draw();
}