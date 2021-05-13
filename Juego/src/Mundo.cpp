#include "Mundo.h"
#include "glut.h"
#include "VariablesGlobales.h"

void Mundo::Dibuja()
{
	float x_pto_ojo = personaje.posicion.x;
	static const float y_pto_ojo = ALTO_PANTALLA / 35.0;
	static const float z_pto_ojo = 0.0;

	x_ojo = personaje.posicion.x;
	if (x_ojo < 42)
	{
		x_ojo = 42;
		x_pto_ojo = 42;
	}

	gluLookAt(x_ojo, y_ojo, z_ojo,   // posicion del ojo
		x_pto_ojo, y_pto_ojo, z_pto_ojo,       // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	//aqui es donde hay que poner el codigo de dibujo

	personaje.dibuja();
	nivel.dibuja();
	for (int i = 0; i < bonus->numero; i++)
	{
		bonus[i].Dibuja();
	}
	enemigos.dibuja();
}

void Mundo::Mueve()
{
	static const float t = FREC / 1000.0;

	personaje.mueve(t);
	if (personaje.posicion.x > 200)
	{
		nivel.inicia(2, bonus, enemigos);
		personaje.setPos(2, 4);
	}
	for (int i = 0; i < bonus->numero; i++)
	{
		bonus[i].Mueve(t);
	}
	enemigos.mueve(t);
}

void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = ALTO_PANTALLA / 35.0;
	z_ojo = 60;

	nivel.inicia(1, bonus, enemigos);
}

void Mundo::Tecla(unsigned char key)
{
	switch (key)
	{
	case 'a':
	{
		personaje.velocidad.x -= 5;
		if (personaje.velocidad.x < -5) { personaje.velocidad.x = -5; }
		break;
	}
	case 'd':
	{
		personaje.velocidad.x += 5;
		if (personaje.velocidad.x > 5) { personaje.velocidad.x = 5; }
		break;
	}
	case 'w':
	{
		personaje.velocidad.y += 5;
		if (personaje.velocidad.y > 5) { personaje.velocidad.y = 5; }
		break;
	}
	case 's':
	{
		personaje.velocidad.y -= 5;
		if (personaje.velocidad.y < -5) { personaje.velocidad.y = -5; }
		break;
	}
	}
}

void Mundo::teclaEspecial(unsigned char key)
{

	switch (key)
	{
	case GLUT_KEY_UP:
	{
		personaje.dispara(0, 10.0f, 0);
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		personaje.dispara(10.0f, 0, 270);
		break;
	}
	case GLUT_KEY_LEFT:
	{
		personaje.dispara(-10.0f, 0,90);
		break;
	}
	}
}