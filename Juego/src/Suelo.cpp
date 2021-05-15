#include "Suelo.h"
#include "freeglut.h"

Suelo::Suelo()
{
	personaje = new Sprite("imagenes/suelo.png", posicion.x, posicion.y, lado, lado);
}

void Suelo::dibuja()
{
	personaje->draw();
}

void Suelo::setPos(int x, int y)
{
	personaje->setPos(x, y);
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
