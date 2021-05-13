#include "Enemigo.h"
#include "freeglut.h"

Enemigo::Enemigo()
{
	rojo = verde = azul = 255; //blanco por defecto
	velocidad.x = 5.0f;
	velocidad.y = 5.0f;
	aceleracion.x = 3.0f;
	aceleracion.y = -9.8f;
	altura = 5.5f;
}

void Enemigo::dibuja()
{
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidCube (altura);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Enemigo::mueve(float t)
{
	velocidad = velocidad + aceleracion * t;
	posicion = posicion + velocidad * t * 0.5 * aceleracion * t * t;
	
}
