#pragma once

#include "Personaje.h"
#include "Enemigo.h"
#include "Mapa.h"
#include <math.h>

class Interaccion
{
public:
	static void rebote(Personaje& p, Mapa& m);
	static bool rebote(Enemigo& e, Suelo s);
	static void spawn(ListaEnemigos& e);
	static bool rebote(Enemigo& enem1, Personaje& p);
	static void choque(ListaDisparos& d, ListaEnemigos& e, Personaje& p);
	static void choque(ListaDisparos& d, Personaje& p);
	static void choque(Personaje& p, ListaBonus& b);
	static void choque(ListaDisparos& d, Mapa& m);
	static void atacar(ListaEnemigos& e, Personaje& p);
};