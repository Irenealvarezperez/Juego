#include "Personaje.h"
#include "VariablesGlobales.h"
#include "freeglut.h"

Personaje::Personaje()
{
	sprite = new SpriteSequence("imagenes/personaje.png", 5, 4, 200, true, posicion.x, posicion.y, 8, 5.5, 6);
	sprite->setPos(50, 20);
}

void Personaje::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
	sprite->setPos(x, y);
}

void Personaje::dibuja()
{
	glPushMatrix();
	glColor3d(255, 0, 0);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(0.25, 10, 10);
	//glPopMatrix();

	glTranslatef(0, 0, -1);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3d(0, 255, 0);
	glVertex2f(ancho / 2.0f, alto / 2.0f);
	glVertex2f(ancho / 2.0f, -alto / 2.0f);
	glVertex2f(-ancho / 2.0f, -alto / 2.0f);
	glVertex2f(-ancho / 2.0f, alto / 2.0f);
	glEnd();
	glPopMatrix();

	if (velocidad.x > 0.01) {
		if (sprite->getState() < 5 || sprite->getState() > 8) sprite->setState(5, false);
	}
	if (velocidad.x < -0.01) {
		if (sprite->getState() < 1 || sprite->getState()>4) sprite->setState(1, false);
	}
	if (velocidad.x <= 0.01 && velocidad.x >= -0.01) sprite->setState(6, false);

	sprite->draw();

	disparos.dibuja();
}

void Personaje::mueve(float t)
{
	posicion=sprite->getPos();
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;

	sprite->loop();

	if (posicion.x < 0) { posicion.x = 0; }
	if (posicion.y < 0) { posicion.y = 0; }
	if (posicion.y > 46) { posicion.y = 46; }
	sprite->setPos(posicion.x, posicion.y);
	sprite->setVel(velocidad.x, velocidad.y);

	disparos.mueve(t);
}

void Personaje::dispara(float vx, float vy, float flip)
{
	Disparo* d = new Disparo();

	d->setPos(posicion.x, posicion.y);
	d->setVel(vx, vy);
	disparos.agregar(d, flip);
}