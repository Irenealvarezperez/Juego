#pragma once

#include "Bonus.h"
#define max_bonus 100

class ListaBonus
{
private:
	Bonus* lista[max_bonus];
	int numero;
	Bonus::Tipo tipo;

public:
	ListaBonus();
	~ListaBonus();

	bool agregar(Bonus* b);
	Bonus* setBonus(const char* path, float x, float y, float ancho, float alto, Bonus::Tipo tipoBonus);
	void destruirContenido();
	void dibuja();
	void mueve(float t);
	void eliminar(int index);
	Bonus::Tipo getTipo(Bonus* bonus) { return tipo; };

	friend class Interaccion; //Necesito saber el valor privado de numero de disparos
	friend class Mapa;
};