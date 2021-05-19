#pragma once
#include "Mundo.h"
class Coordinador
{
public:
	Coordinador();
	~Coordinador();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
protected:
	Mundo mundo;
	enum Estado { INICIO, NIVELES, SELECCION_NIVEL, JUEGO, GAMEOVER, FIN, PAUSA };
	Estado estado;
};

