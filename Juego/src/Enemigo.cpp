#include "Enemigo.h"
#include "freeglut.h"

Enemigo::Enemigo()
{
	rojo = verde = azul = 255; //blanco por defecto
	aceleracion.x = 3.0f;
	aceleracion.y = -9.8f;
	altura = ancho = 5.5f;
	//enemigo = new Sprite("imagenes/enemigo.png", posicion.x, posicion.y, ancho, altura);
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
	sprite->draw();
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
	// Aqui deberia dar igual lo q poner porq luego se modifica desde la clase especializada, por ej Ladron,
	// pero si cambian el numero de filas o columnas de aqui || no se q pasa
	//														 vv
	sprite = new SpriteSequence("imagenes/personaje2.png", 6, 1, 300, true, x, y, ancho, altura);
	setPos(x, y);
	setVel(vx, vy);
}

