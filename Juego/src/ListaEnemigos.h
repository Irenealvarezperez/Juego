#pragma once
#include"Enemigo.h"
#define MAX_ENEMIGOS 100 

class ListaEnemigos
{
	Enemigo* lista[MAX_ENEMIGOS];
	int numero;//numero enemigos

public:
	ListaEnemigos();
	//virtual ~ListaEsferas();
	bool agregar(Enemigo* e);
	void dibuja();
	void mueve(float t);
	//void rebote(Caja caja);
	//void rebote(Pared p);
	void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Enemigo* e);
	//Enemigo* colision(Personaje& p);


};

