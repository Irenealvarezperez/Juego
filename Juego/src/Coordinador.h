#pragma once
#include "Mundo.h"
class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
protected:
	Mundo mundo;
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSA };
	Estado estado;
};

