#include "Enemigo.h"

void Enemigo::dibuja()
{
	sprite->draw();

}

void Enemigo::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f *static_cast<double>(t) * static_cast<double>(t));
	velocidad = velocidad + aceleracion * t;

	setPos(static_cast<float>(posicion.x), static_cast<float>(posicion.y));
	setVel(static_cast<float>(velocidad.x), static_cast<float>(velocidad.y));

	sprite->loop();

	//Esto no deberia ir aqui pero es de prueba
	disparos.mueve(t);
}

Enemigo::Enemigo(float altura,float anchura, float x, float y, float vx, float vy)
{
	this->altura = altura;

	// Aqui deberia dar igual lo q poner porq luego se modifica desde la clase especializada, por ej Ladron,
	// pero si cambian el numero de filas o columnas de aqui || no se q pasa
	//														 vv
	sprite = new SpriteSequence("imagenes/personaje2.png", 99, 99, 300, true, x, y, anchura, altura);
	setPos(x, y);
	setVel(vx, vy);

	//BarradeVida = new SpriteSequence("imagenes/barradevida.png", 3, 3, 100, true, x_ojo-42,46, 15,2,0);
	BarradeVida = new SpriteSequence("imagenes/barradevida.png", 3, 3, 100, true, posicion.x, posicion.y + altura / 2, 6, 1, 0);
}