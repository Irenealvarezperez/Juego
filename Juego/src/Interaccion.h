#pragma once

#include "Personaje.h"
#include "Enemigo.h"
#include "Mapa.h"
#include <math.h>

class Interaccion
{
public:
	static void rebote(Personaje& p, Mapa& m);
	static bool rebote(Enemigo& e, Personaje p);
	static bool rebote(Enemigo& e, Suelo s);
	static bool rebote(Enemigo& enem1, Enemigo& enem2);

	static void choque(ListaDisparos& d, ListaEnemigos& e);
	static void choque(Personaje& p, ListaBonus& b);
	static void compruebaColision(Personaje& p1, Enemigo& p2);
};