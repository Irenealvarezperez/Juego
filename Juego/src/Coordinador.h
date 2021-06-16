#pragma once

#include "Mundo.h"
#include <string>

class Coordinador
{
private:
	long int t0 = 0;
	Mundo mundo;
	enum Estado { HISTORIA, INICIO, NIVELES, SELECCION_NIVEL, JUEGO, GAMEOVER, FIN, PAUSA, FINAL };
	Estado estado;
	string path = "imagenes/historia00.png";
	int pantalla_historia = 10;
	long duracionPausa = 0.0f;
public:
	Coordinador();
	~Coordinador();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	void destruirContenido();
};

