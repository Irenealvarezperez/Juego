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
	enemigos.dibuja();
}

void Mundo::Mueve()
{
	static const float t = FREC / 1000.0;

	personaje.mueve(t);
	if (personaje.posicion.x > 200)
	{
		nivel.iniciar_nivel(2);
		personaje.posicion.x = 2;
		personaje.posicion.y = 4;
	}
	enemigos.mueve(0.025f);
}

void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = ALTO_PANTALLA / 35.0;
	z_ojo = 60;

	nivel.iniciar_nivel(1);

	Enemigo* e1 = new Enemigo(5,26,13,7,7); // enemigo 1 (altura, x, y, vx, vy)
	e1->setColor(255, 0, 0);
	enemigos.agregar(e1); // enemigo 1 a la lista
	Enemigo* e2 = new Enemigo(2,50,4,5,15); // enemigo 2
	e2->setColor(0,255, 0);
	enemigos.agregar(e2); // enemigo 2 a la lista
	
}

void Mundo::Tecla(unsigned char key)
{
	switch (key)
	{
	case 'a':
	{
		personaje.velocidad.x -= 5;
		if (personaje.velocidad.x < -5)
		{
			personaje.velocidad.x = -5;
		}
		break;
	}
	case 'd':
	{
		personaje.velocidad.x += 5;
		if (personaje.velocidad.x > 5)
		{
			personaje.velocidad.x = 5;
		}
		break;
	}
	case 'w':
	{
		personaje.velocidad.y += 5;
		if (personaje.velocidad.y > 5)
		{
			personaje.velocidad.y = 5;
		}
		break;
	}
	case 's':
	{
		personaje.velocidad.y -= 5;
		if (personaje.velocidad.y < -5)
		{
			personaje.velocidad.y = -5;
		}
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
		personaje.dispara(0, 10.0f);
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		personaje.dispara(10.0f, 0);
		break;
	}
	case GLUT_KEY_LEFT:
	{
		personaje.dispara(-10.0f, 0);
		break;
	}
	}
}