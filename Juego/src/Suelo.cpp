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