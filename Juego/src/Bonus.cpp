#include "Bonus.h"
#include <stdlib.h>
#include "freeglut.h"

Bonus::Bonus(const char* path)
{
	bonus = new Sprite(path, posicion.x, posicion.y, ancho * 0.9, alto * 0.9);
}

Bonus::~Bonus() {}

void Bonus::dibuja()
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

	bonus->draw();
}

void Bonus::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Bonus::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
	bonus->setPos(ix, iy);
}	