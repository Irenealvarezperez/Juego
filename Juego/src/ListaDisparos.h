#pragma once

#include"Disparo.h"
#define MAX_DISPAROS 15

class ListaDisparos
{
public:

	Disparo* lista[MAX_DISPAROS];
	int max_disparos; //variable creada para añadir una unidad al número de disparos que puede haber a la vez
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