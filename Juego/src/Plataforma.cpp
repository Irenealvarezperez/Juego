#include "Plataforma.h"

Plataforma::Plataforma()
{
	
}

Plataforma::~Plataforma()
{
	delete[] suelo;
}

void Plataforma::setPos(int pos_ini, int pos_fin, int pos_y)
{
	this->pos_ini = pos_ini;
	this->pos_fin = pos_fin;
	this->pos_y = pos_y;

	cont = pos_fin - pos_ini;
	suelo = new Suelo[cont];
}

void Plataforma::dibuja()
{
	for (int i = 0; i < cont; i++)
	{
		suelo[i].setPos(pos_ini + i, pos_y);
		suelo[i].dibuja();
	}
}