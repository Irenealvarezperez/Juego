#include "Suelo.h"
#include "freeglut.h"

Suelo::Suelo()
{
	posicion.x = 0;
	posicion.y = 0;
}

void Suelo::dibuja()
{
	glPushMatrix();
	glColor3ub(227, 165, 123);
	glTranslatef(posicion.x, posicion.y, 0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glVertex2f(lado / 2.0f, lado / 2.0f);
	glVertex2f(lado / 2.0f, -lado / 2.0f);
	glVertex2f(-lado / 2.0f, -lado / 2.0f);
	glVertex2f(-lado / 2.0f, lado / 2.0f);
	glEnd();
	glPopMatrix();
}

void Suelo::setPos(int x, int y)
{
	posicion.x = x;
	posicion.y = y;
}

float Suelo::distancia(Vector2D punto, Vector2D* direccion)
{
	//Calculo de distancia de una pared a un punto, adicionalmente
//se modifica el valor de un vector direccion opcional que contendrá
//el vector unitario saliente que indica la direccion de la
//recta más corta entre el punto y el suelo.
	Vector2D u = (punto - );
	Vector2D v = (limite2 - limite1).unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector…
		*direccion = dir.unitario();
	return distancia;
}
