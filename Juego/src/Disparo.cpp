#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo()
{
	disparo = new Sprite("imagenes/bala.png", posicion.x, posicion.y, lado, lado);
}

Disparo::~Disparo() {}

void Disparo::dibuja()
{
	glPushMatrix();
	glColor3d(255, 0, 0);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(0.25, 10, 10);
	glPopMatrix();

	disparo->draw();
}

void Disparo::mueve(float t)
{
	posicion = disparo->getPos();
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	disparo->setPos(posicion.x, posicion.y);
	disparo->setVel(velocidad.x, velocidad.y);
}

void Disparo::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
	disparo->setPos(ix, iy);
}

void Disparo::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
	disparo->setVel(vx, vy);
}
