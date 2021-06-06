#pragma once

#include"Disparo.h"
#define MAX_DISPAROS 3

class ListaDisparos
{
public:
	Disparo* lista[MAX_DISPAROS];
	int numero;

public:
	ListaDisparos();
	~ListaDisparos();

	bool agregar(Disparo* d, float flip);
	void destruirContenido();
	void mueve(float t);
	void dibuja();
	void eliminar(int index);

	friend class Interaccion; //Necesito saber el valor privado de numero de disparos
};