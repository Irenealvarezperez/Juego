#pragma once
#include "Personaje.h"
#include "Enemigo.h"
#include "Suelo.h"

class Interaccion
{
public:
	static void rebote(Personaje& p, Suelo s);
	static bool rebote(Enemigo& e, Personaje p);
	static void rebote(Enemigo& e, Suelo s);
	static bool rebote(Enemigo& esfera1, Enemigo& esfera2);
	
};
};

