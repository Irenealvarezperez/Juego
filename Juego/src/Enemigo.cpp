#include "Enemigo.h"
#include "freeglut.h"

Enemigo::Enemigo()
{
	rojo = verde = azul = 255; //blanco por defecto
	velocidad.x = 5.0f;
	velocidad.y = 5.0f;
	aceleracion.x = 3.0f;
	aceleracion.y = -9.8f;
	altura = ancho = 5.5f;
}

void Enemigo::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rojo, verde, azul);
	glutSolidCube(altura);
	glPopMatrix();
}

void Enemigo::mueve(float t)
{
	posicion = posicion - velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad - aceleracion * t;
}

void Enemigo::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}

Enemigo::Enemigo(float altura, float x, float y, float vx, float vy)
{
	this->altura = altura;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	rojo = verde = 255;
	azul = 100; //color distinto
	aceleracion.x = 0;
	aceleracion.y = 0;
}
