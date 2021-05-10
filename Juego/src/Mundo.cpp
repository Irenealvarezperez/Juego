#include "Mundo.h"
#include "glut.h"
#include <cmath>

void Mundo::Dibuja()
{
	gluLookAt(personaje.px, y_ojo, z_ojo,  // posicion del ojo
		personaje.px, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	base.dibuja();
	plataforma1.dibuja();
	plataforma2.dibuja();
	personaje.dibuja();
}

void Mundo::Mueve()
{
	static const double t = 0.017;
	personaje.mueve(t);

	// POSIBLE IDEA PARA INTERACCIONES ENTRE OBJETO Y PLATAFORMA

	for (int i = 0; i < base.cont; i++)
	{
		if (personaje.py - 2.5 <= base.suelo[i].y)
		{
			personaje.py = base.suelo[i].y + 2.5;
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
}

void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 0;
	z_ojo = 60;
	base.setPos(-40, 40, -20);
	plataforma1.setPos(-20, -15, 10);
	plataforma2.setPos(30, 40, 0);
}

void Mundo::Tecla(unsigned char key)
{
	if (key == 'a')
	{
		personaje.vx = -5;
	}
	if (key == 'd')
	{
		personaje.vx = 5;
	}
	if (key == 'w')
	{
		personaje.vy = 10;
	}
	if (key == 's')
	{
		personaje.vy = -5;
	}
}