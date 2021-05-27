#include "Enemigo.h"

void Enemigo::dibuja()
{
	sprite->draw();
}

void Enemigo::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;

	setPos(posicion.x, posicion.y);
	setVel(velocidad.x, velocidad.y);

	sprite->loop();

	//Esto no deberia ir aqui pero es de prueba
	disparos.mueve(t);
}

Enemigo::Enemigo(float altura, float x, float y, float vx, float vy)
{
	this->altura = altura;

	// Aqui deberia dar igual lo q poner porq luego se modifica desde la clase especializada, por ej Ladron,
	// pero si cambian el numero de filas o columnas de aqui || no se q pasa
	//														 vv
	sprite = new SpriteSequence("imagenes/personaje2.png", 6, 1, 300, true, x, y, ancho, altura);
	setPos(x, y);
	setVel(vx, vy);
}