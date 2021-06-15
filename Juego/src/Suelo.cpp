#include "Suelo.h"
#include "freeglut.h"

Suelo::Suelo(int x, int y,int indice)
{
	if (indice == 0)sprite = new Sprite("imagenes/suelo.png", posicion.x, posicion.y, lado, lado);
	if (indice == 1)sprite = new Sprite("imagenes/suelog.png", posicion.x, posicion.y, lado, lado);
	if (indice == 2)sprite = new Sprite("imagenes/suelob.png", posicion.x, posicion.y, lado, lado);
	if (indice == 3)sprite = new Sprite("imagenes/suelo3.png", posicion.x, posicion.y, lado, lado);
	if (indice == 4)sprite = new Sprite("imagenes/suelo4.png", posicion.x, posicion.y, lado, lado);
	if (indice == 5)sprite = new Sprite("imagenes/suelo5.png", posicion.x, posicion.y, lado, lado);
	if (indice == 6)sprite = new Sprite("imagenes/suelo7.png", posicion.x, posicion.y, lado, lado);
	if (indice == 7)sprite = new Sprite("imagenes/cama1.png", posicion.x, posicion.y, 7, 5);
	if (indice == 8)sprite = new Sprite("imagenes/valla.png", posicion.x, posicion.y, 9, 5);
	if (indice == 9)sprite = new Sprite("imagenes/maleta1.png", posicion.x, posicion.y, 5, 5);
	if (indice == 10)sprite = new Sprite("imagenes/maleta2.png", posicion.x, posicion.y, 4, 5);
	if (indice == 11)sprite = new Sprite("imagenes/caja.png", posicion.x, posicion.y, 4, 4);
	if (indice == 12)sprite = new Sprite("imagenes/cono.png", posicion.x, posicion.y, 5, 6);
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
