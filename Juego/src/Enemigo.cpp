#include "Enemigo.h"
#include "freeglut.h"

Enemigo::Enemigo(const char* path)
{
	enemigo = new Sprite(path, posicion.x, posicion.y, ancho * 1.1, alto * 1.2);
}

void Enemigo::dibuja()
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

	enemigo->draw();
}

void Enemigo::mueve(float t)
{
	posicion = posicion - velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad - aceleracion * t;
}

void Enemigo::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
	enemigo->setPos(ix, iy);
}