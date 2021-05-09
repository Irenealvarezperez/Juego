#include "Mundo.h"
#include "glut.h"
#include <cmath>

void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
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
		personaje.setPos(personaje.x -= 0.3, personaje.y);
	}
	if (key == 'd')
	{
		personaje.setPos(personaje.x += 0.3, personaje.y);
	}
	if (key == 'w')
	{
		personaje.setPos(personaje.x, personaje.y += 0.3);
	}
	if (key == 's')
	{
		personaje.setPos(personaje.x, personaje.y -= 0.3);

		// POSIBLE IDEA PARA INTERACCIONES ENTRE OBJETO Y PLATAFORMA

		/*
			for (int i = 0; i < base.cont; i++)
			{
				double Ix = abs(personaje.x - base.suelo[i].x);
				double Iy = abs(personaje.y - base.suelo[i].y);
				if (sqrt(Ix * Ix + Iy * Iy) < 2.5)
				{
					if (personaje.y - 2.5 <= base.suelo[i].y)
					{
						personaje.y = base.suelo[i].y + 2.5;
					}
				}
			}
			
			for (int i = 0; i < plataforma1.cont; i++)
			{
				double Ix = abs(personaje.x - plataforma1.suelo[i].x);
				double Iy = abs(personaje.y - plataforma1.suelo[i].y);
				if (sqrt(Ix * Ix + Iy * Iy) < 2.5)
				{
					if (personaje.y - 2.5 <= plataforma1.suelo[i].y)
					{
						personaje.y = plataforma1.suelo[i].y + 2.5;
					}
				}
			}

			for (int i = 0; i < plataforma2.cont; i++)
			{
				double Ix = abs(personaje.x - plataforma2.suelo[i].x);
				double Iy = abs(personaje.y - plataforma2.suelo[i].y);
				if (sqrt(Ix * Ix + Iy * Iy) < 2.5)
				{
					if (personaje.y - 2.5 <= plataforma2.suelo[i].y)
					{
						personaje.y = plataforma2.suelo[i].y + 2.5;
					}
				}
			}
		*/

	}
}