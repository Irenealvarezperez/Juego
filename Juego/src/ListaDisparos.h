#pragma once

#include"Disparo.h"
#define MAX_DISPAROS 15

class ListaDisparos
{
private:
	Disparo* lista[MAX_DISPAROS];
	int numero;

public:
	ListaDisparos();
	virtual ~ListaDisparos();

	bool agregar(Disparo* d);
	void destruirContenido();
	void mueve(float t);
	void dibuja();
};