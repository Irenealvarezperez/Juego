#pragma once

#include "Vector2D.h"

class Suelo
{
public:
	Vector2D posicion;
	int lado = 3;

public:
	Suelo();

	void dibuja();
	void setPos(int x, int y);
};