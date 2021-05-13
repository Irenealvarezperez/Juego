#pragma once
#include "ListaDisparos.h"
#include"Vector2D.h"
//#include<freeglut.h>

class Enemigo
{
	int vida = 1;
	int rojo;
	int verde;
	int azul;
	float altura;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	ListaDisparos disparos;
public:
	Enemigo();
	void setPos(float ix, float iy);
	void dibuja();
	void mueve(float t);
	void setVel(float vel_x, float vel_y);
};

