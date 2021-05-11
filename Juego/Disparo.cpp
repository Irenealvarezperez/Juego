#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo()
{
	radio = 0.25f;
	velocidad.y = .0f;
	aceleracion.x = aceleracion.y = 0;
}

Disparo::~Disparo() {}

void Disparo::dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
}


void Disparo::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}


void Disparo::setPos(float ix, float iy) {
	posicion.x = origen.x = ix;
	posicion.y = origen.y = iy;
}
void Disparo::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

Vector2D Disparo::getPos() {
	return posicion;
}