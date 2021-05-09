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
	glutSolidCube(lado);
	glPopMatrix();
}

void Suelo::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}