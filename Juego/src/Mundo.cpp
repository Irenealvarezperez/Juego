#include "Mundo.h"
#include "glut.h"
#include <Windows.h>
#include <stdio.h>
#include <string>
#include "ETSIDI.h"


void texto(float x, float y, const char* string);



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

	if (time > 1000)
	{
		tiempo_nivel += 1.0 / 100.0;
		time = 0;
	}

	string str = "Vida: ";
	string vida = to_string(personaje.vida);
	string str2 = "Escudo: ";
	string escudo = to_string(personaje.escudo);
	string str3 = "Tiempo: ";
	string tiempo = to_string(int(tiempo_nivel));
	str.append(vida);
	str2.append(escudo);
	str3.append(tiempo);
	texto(x_ojo - 42, 46, &str[0]);
	texto(x_ojo - 42, 44, &str2[0]);
	texto(x_ojo + 30, 46, &str3[0]);
}

void Mundo::mueve()
{
	static const float t = FREC / 1000.0;

	personaje.mueve(t);
	enemigos.mueve(t);
	bonus.mueve(t);

	Interaccion::choque(personaje.disparos, enemigos);
	Interaccion::choque(personaje, bonus);
	Interaccion::choque(personaje.disparos, nivel);
	for (int i = 0; i < enemigos.numero; i++)
	{
		Interaccion::choque(enemigos.lista[i]->disparos, nivel);
	}
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
		personaje.velocidad.x = -5;

		break;
	}
	case 'd':
	{
		personaje.velocidad.x = 5;

		break;
	}
	case 'w':
	{
		personaje.velocidad.y = 5;
		break;
	}
	/*case 's':
	{

		personaje.velocidad.y = -5;
		
		break;
	}*/
	case 't':
	{
		personaje.posicion.x = 150;
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
		for (int i = 0; i < enemigos.numero; i++)
		{
			//Arreglar esto
			if (enemigos.lista[i]->tipo == Enemigo::LADRON)
			{
				reinterpret_cast<Ladron*>(enemigos.lista[i])->dispara(0, 10.0f, 0);
			}

			//Lo de abajo no lo veo como solucion definitiva porq todos los enemigos de lista
			//de enemigos se pueden convertir a ladrones
			// 
			//Ladron* l = dynamic_cast<Ladron*>(enemigos.lista[i]);
			//if (l) l->dispara(0, 10.0f, 0);
		}
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

//Posiblememnte añadir esto a una clase Texto ?
void texto(float x, float y, const char* string)
{
	glColor3f(0, 255, 0);
	glRasterPos3f(x, y, 0.01);
	int len, i;
	len = strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
	}
}