#include "Mundo.h"
#include "glut.h"
#include <Windows.h>
#include <stdio.h>
#include <string>
#include "ETSIDI.h"

#pragma warning(disable : 4996)

void texto(float x, float y, const char* string);

Mundo::Mundo()
{
	tiempo_nivel = 0;
	time = 0;
}

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

	string str = "Vida: ";
	string vida = to_string(personaje.vida);
	string str2 = "Escudo: ";
	string escudo = to_string(personaje.escudo);
	string str3 = "Tiempo: ";
	string tiempo = to_string(int(tiempo_nivel));
	string str4 = "Velocidad X: ";
	string velx = to_string(float(personaje.getVel().x));
	string str5 = "Velocidad Y: ";
	string vely = to_string(float(personaje.getVel().y));
	string str6 = "Tecla Bloq: ";
	string tecla(1, personaje.tecla_bloq);
	string str7 = "Puntuacion: ";
	string punt = to_string(int(personaje.getPuntuacion()));
	str.append(vida);
	str2.append(escudo);
	str3.append(tiempo);
	str4.append(velx);
	str5.append(vely);
	str6.append(tecla);
	str7.append(punt);
	texto(x_ojo - 42, 46, &str[0]);
	texto(x_ojo - 42, 44, &str2[0]);
	texto(x_ojo - 42, 42, &str4[0]);
	texto(x_ojo - 42, 40, &str5[0]);
	texto(x_ojo - 42, 38, &str6[0]);
	texto(x_ojo - 42, 36, &str7[0]);
	texto(x_ojo + 30, 46, &str3[0]);
	//aun no funciona lo de abajo
	if (personaje.invencible == true) {
		setTextColor(0,0,0);
		setFont("fuentes/Pixel.ttf", 10);
		printxy("Espiral Activada", x_ojo-42,36);
	}
}

void Mundo::mueve()
{
	static const float t = FREC / 1000.0;
	
	personaje.mueve(t);
	enemigos.mueve(t);
	bonus.mueve(t);

	Interaccion::choque(personaje.disparos, enemigos, personaje);
	Interaccion::choque(personaje, bonus);
	Interaccion::choque(personaje.disparos, nivel);
	for (int i = 0; i < enemigos.numero; i++)
	{
		Interaccion::choque(enemigos.lista[i]->disparos, nivel);
		Interaccion::choque(enemigos.lista[i]->disparos, personaje);
	}
	Interaccion::rebote(personaje, nivel);
	Interaccion::atacar(enemigos, personaje);
	Interaccion::spawn(enemigos);
}

void Mundo::inicializa()
{
	nivel.inicia(bonus, enemigos);
	time = getMillis() / 1000;
}

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case 'a':
	{
		personaje.setVel(-12, personaje.getVel().y);
		break;
	}
	case 'd':
	{
		personaje.setVel(12, personaje.getVel().y);
		break;
	}
	case 'w':
	{
		if (personaje.tecla_bloq != 'w')
		{
			personaje.setVel(personaje.getVel().x, 16);
			if (personaje.getVel().x > 0.01)
			{
				personaje.setVel(8, personaje.getVel().y);
			}
			else if (personaje.getVel().x < -0.01)
			{
				personaje.setVel(-8, personaje.getVel().y);
			}
		}
		personaje.tecla_bloq = 'w';
		break;
	}
	case 't':
	{
		personaje.posicion.x = 200;
		personaje.papel = true;
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
		ETSIDI::play("sonidos/disparo.mp3");
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		personaje.dispara(10.0f, 0, 270);
		ETSIDI::play("sonidos/disparo.mp3");
		break;
	}
	case GLUT_KEY_LEFT:
	{
		personaje.dispara(-10.0f, 0,90);
		ETSIDI::play("sonidos/disparo.mp3");
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