#include "Mundo.h"
#include "glut.h"
#include <Windows.h>
#include <stdio.h>
void Mundo::dibuja()
{
	x_pto_ojo = personaje.posicion.x;

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
	bonus.dibuja();
	enemigos.dibuja();

}

void Mundo::mueve()
{
	static const float t = FREC / 1000.0;

	personaje.mueve(t);
	if (personaje.posicion.x > 200)
	{
		enemigos.destruirContenido();
		bonus.destruirContenido();
		nivel.setPantalla(2);
		nivel.inicia(bonus, enemigos);
		personaje.setPos(2, 4);
	}
	enemigos.mueve(t);

	Interaccion::choque(personaje.disparos, enemigos);
	Interaccion::rebote(personaje, nivel);
}

void Mundo::inicializa()
{
	nivel.inicia(bonus, enemigos);
}

void Mundo::tecla(unsigned char key)
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
	/*
	intento de hacer que no se mueva el personaje sin pulsar ninguna tecla
	if(GetAsyncKeyState(0x41) & 0x8000)
	{
		personaje.velocidad.x = -5;
	}
	if(GetAsyncKeyState(0x44) & 0x8000)
	{
		personaje.velocidad.x = 5;
	}
	if (GetAsyncKeyState(0x57) & 0x8000)
	{
		personaje.velocidad.y = +5;
	}
	if((GetAsyncKeyState(0x53) & 0x8000))
	{
		personaje.velocidad.y = -5;
	}
	//if ((GetAsyncKeyState(0x41) & 0x01))
	//if ((!(GetAsyncKeyState(0x41) & 0x8000) && !(GetAsyncKeyState(0x44) & 0x8000) && !(GetAsyncKeyState(0x53) & 0x8000) && !(GetAsyncKeyState(0x57) & 0x8000)))
	//if (((GetAsyncKeyState(0x41) & 0x0001) && (GetAsyncKeyState(0x44) & 0x0001) && (GetAsyncKeyState(0x53) & 0x0001) && (GetAsyncKeyState(0x57) & 0001)))
	if ((!(GetKeyState(0x41) & 0x8000) && !(GetKeyState(0x44) & 0x8000) && !(GetKeyState(0x53) & 0x8000) && !(GetKeyState(0x57) & 0x8000)))
	{
		personaje.velocidad.x = 0;
		personaje.velocidad.y = 0;
	}*/

	
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