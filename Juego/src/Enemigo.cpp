#include "Enemigo.h"
#include "freeglut.h"

Enemigo::Enemigo()
{
	rojo = verde = azul = 255; //blanco por defecto
	aceleracion.x = 3.0f;
	aceleracion.y = -9.8f;
	altura = ancho = 5.5f;
	enemigo = new Sprite("imagenes/enemigo.png", posicion.x, posicion.y, ancho, altura);
	setVel(1, 1);
}

void Enemigo::dibuja()
{
	/*
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(rojo, verde, azul);
	glutSolidCube(altura);
	glPopMatrix();
	*/
	//sprite->draw();
	enemigo->draw();
}

void Enemigo::mueve(float t)
{
	//posicion = sprite->getPos();// Sobra, comprobado
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;

	setPos(posicion.x, posicion.y);
	setVel(velocidad.x, velocidad.y);
	//sprite->loop();
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
	rojo = verde = 255;
	azul = 100; //color distinto
	aceleracion.x = 0;
	aceleracion.y = 0;
	enemigo = new Sprite("imagenes/enemigo.png", posicion.x, posicion.y, ancho, altura);
	setPos(x, y);
	setVel(vx, vy);
}

