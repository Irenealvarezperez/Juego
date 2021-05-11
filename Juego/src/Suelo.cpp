#include "Suelo.h"
#include "freeglut.h"

Suelo::Suelo()
{

}

Suelo::Suelo(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Suelo::dibuja()
{
	glPushMatrix();
	glColor3ub(227, 165, 123);
	glTranslatef(x, y, 0);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glVertex2f(lado / 2.0, lado / 2.0);
	glVertex2f(lado / 2.0, -lado / 2.0);
	glVertex2f(-lado / 2.0, -lado / 2.0);
	glVertex2f(-lado / 2.0, lado / 2.0);
	glEnd();
	glPopMatrix();
}

void Suelo::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}