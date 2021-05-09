#pragma once

#include "Suelo.h"

class Plataforma
{
private:

public:
	int pos_ini = 0, pos_fin = 0, pos_y = 0;
	Suelo* suelo = nullptr;
	int cont = 0;
	Plataforma();
	~Plataforma();
	void setPos(int pos_ini, int pos_fin, int pos_y);
	void dibuja();
};

