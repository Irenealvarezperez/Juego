#include "Ladron.h"

Ladron::Ladron(float altura, float anchura, float x, float y, float vx, float vy) :Enemigo(altura, anchura, x, y, vx, vy)
{
	setTipo(LADRON);
	sprite = new SpriteSequence("imagenes/ladron2.png", 6, 1, 300, true, x, y, anchura, altura * 1.25);
	vida = 2;
	puntuacion = 2;
}

void Ladron::dibuja()
{
	Enemigo::dibuja();
	disparos.dibuja();
	sprite->flip(true, false);
	//if (sprite->getState() > 5)sprite->setState(0, false);

	//disparos.dibuja();

	if (vida == 2)BarradeVida->setState(0, false);
	else if (vida == 1)BarradeVida->setState(4, false);
	BarradeVida->setPos(posicion.x, posicion.y + altura / 2);
	BarradeVida->draw();
}
