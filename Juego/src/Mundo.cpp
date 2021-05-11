#include "Mundo.h"
#include "glut.h"
#include <cmath>
#include "VariablesGlobales.h"
#include <iostream>

void Mundo::Dibuja()
{
	gluLookAt(personaje.px, y_ojo, z_ojo,   // posicion del ojo
		personaje.px, ALTO_PANTALLA / 35, 0.0,       // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo

	personaje.dibuja();
	nivel.dibuja();
}

void Mundo::Mueve()
{
	static const double t = FREC / 1000.0;

	printf_s("%.4lf %.4lf\n", personaje.px, personaje.py);

	personaje.mueve(t);

	// POSIBLE IDEA PARA INTERACCIONES ENTRE OBJETO Y PLATAFORMA

	/*
	for (int i = 0; i < base.cont; i++)
	{
		double Ix = abs(personaje.px - base.suelo[i].x);
		double Iy = abs(personaje.py - base.suelo[i].y);
		if (sqrt(Ix * Ix + Iy * Iy) < 2.5)
		{
			if (personaje.py - 2.5 <= base.suelo[i].y)
			{
				personaje.py = base.suelo[i].y + 2.5;
			}
		}
	}

	for (int i = 0; i < plataforma1.cont; i++)
	{
		double Ix = abs(personaje.px - plataforma1.suelo[i].x);
		double Iy = abs(personaje.py - plataforma1.suelo[i].y);
		if (sqrt(Ix * Ix + Iy * Iy) < 2.5)
		{
			if (personaje.py - 2.5 <= plataforma1.suelo[i].y)
			{
				personaje.py = plataforma1.suelo[i].y + 2.5;
			}
		}
	}

	for (int i = 0; i < plataforma2.cont; i++)
	{
		double Ix = abs(personaje.px - plataforma2.suelo[i].x);
		double Iy = abs(personaje.py - plataforma2.suelo[i].y);
		if (sqrt(Ix * Ix + Iy * Iy) < 2.5)
		{
			if (personaje.py - 2.5 <= plataforma2.suelo[i].y)
			{
				personaje.py = plataforma2.suelo[i].y + 2.5;
			}
		}
	}
	*/
}

void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = ALTO_PANTALLA / 35;
	z_ojo = 60;
	nivel.iniciar_nivel(1);
}

void Mundo::Tecla(unsigned char key)
{
	if (key == 'a')
	{
		personaje.vx -= 5;
		if (personaje.vx < -5)
		{
			personaje.vx = -5;
		}
	}
	if (key == 'd')
	{
		personaje.vx += 5;
		if (personaje.vx > 5)
		{
			personaje.vx = 5;
		}
	}
	if (key == 'w')
	{
		personaje.vy += 5;
		if (personaje.vy > 5)
		{
			personaje.vy = 5;
		}
	}
	if (key == 's')
	{
		personaje.vy -= 5;
		if (personaje.vy < -5)
		{
			personaje.vy = -5;
		}
	}
}