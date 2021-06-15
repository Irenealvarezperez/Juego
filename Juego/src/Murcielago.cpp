#include"Murcielago.h"
#include"freeglut.h"
Murcielago::Murcielago(float altura,float anchura, float x, float y, float vx, float vy) :Enemigo(altura,anchura, x, y, vx, vy)
{
	setTipo(MURCIELAGO);
	sprite = new SpriteSequence("imagenes/murcielago2.png", 4, 4, 300, true, x, y, anchura, altura);
	sprite->setState(9, false);
	vida = 1;
	puntuacion = 1;
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
	disparos.dibuja();
	//dispara(0, -10, 0); //solo una prueba, dispara muchas veces. Arreglarlo

	if (vida == 1)BarradeVida->setState(0, false);
}
