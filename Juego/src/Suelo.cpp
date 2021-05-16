#include "Suelo.h"
#include "freeglut.h"

Suelo::Suelo(int x, int y)
{
	sprite = new Sprite("imagenes/suelo.png", posicion.x, posicion.y, lado, lado);
	setPos(x, y);
}

void Suelo::dibuja()
{
	sprite->draw();
}

void Suelo::setPos(int x, int y)
{
	posicion.x = x;
	posicion.y = y;
	sprite->setPos(x, y);
}

float Suelo::distancia(Vector2D punto, Vector2D* direccion)
{
	//Calculo de distancia de una pared a un punto, adicionalmente
//se modifica el valor de un vector direccion opcional que contendrá
//el vector unitario saliente que indica la direccion de la
//recta más corta entre el punto y el suelo.
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).unit();
	float longitud = (limite1 - limite2).module();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.module();
	if (direccion != 0) //si nos dan un vector…
		*direccion = dir.unit();
	return distancia;
}
