#pragma once

#include "Suelo.h"
#define MAX_SUELOS 1000

class ListaSuelos
{
private:
	Suelo* lista[MAX_SUELOS];
	int numero;

public:
	ListaSuelos();
	~ListaSuelos();

	bool agregar(Suelo* e);
	void dibuja();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Suelo* e);

	friend class Interaccion; //Necesito saber el valor privado de numero de suelos
};