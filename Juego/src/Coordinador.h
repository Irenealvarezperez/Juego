#pragma once

#include "Mundo.h"

class Coordinador
{
private:
	long int t0 = 0;
	Mundo mundo;
	enum Estado { INICIO, NIVELES, SELECCION_NIVEL, JUEGO, GAMEOVER, FIN, PAUSA, FINAL };
	Estado estado;
public:
	Coordinador();
	~Coordinador();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	void destruirContenido();
};

