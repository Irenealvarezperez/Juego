#pragma once

#include "Enemigo.h"
#define MAX_ENEMIGOS 100 

class ListaEnemigos
{
private:
	Enemigo* lista[MAX_ENEMIGOS];
	int numero;	//numero enemigos

public:
	ListaEnemigos();
	~ListaEnemigos();

	bool agregar(Enemigo* e);
	void dibuja();
	void mueve(float t);
	//void rebote(Caja caja);
	//void rebote(Pared p);
	void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Enemigo* e);

	friend class Interaccion; //Necesito saber el valor privado de numero de enemigos
};