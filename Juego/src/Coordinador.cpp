#include "Coordinador.h"

Coordinador::Coordinador()
{
	estado = INICIO;
}

void Coordinador::dibuja()
{
	if (estado == INICIO)
	{//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS
		gluLookAt(ANCHO_PANTALLA/35.0, ALTO_PANTALLA / 35.0, 60.0f, // posicion del ojo
			ANCHO_PANTALLA/35.0, ALTO_PANTALLA / 35.0, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Pixel.ttf", 30);
		ETSIDI::printxy("Juego", 38,30);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Pixel.ttf", 14);
		ETSIDI::printxy("The creatives", 38, 18);
		ETSIDI::setFont("fuentes/Pixel.ttf", 18);
		//ETSIDI::printxy("Pulse -e- para empezar", 34, 24);
		ETSIDI::printxy("Pulse -f- para seleccionar los niveles", 34, 20);
	}
	else if (estado == NIVELES)
	{
		gluLookAt(ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 60.0f, // posicion del ojo
			ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Pixel.ttf", 30);
		ETSIDI::printxy("Seleccion de nivel", 20, 40);
		//ETSIDI::printxy("Pulsa -e- para empezar por el nivel 1", 34, 14);
		ETSIDI::printxy("Pulsa -s- para ver los niveles", 30, 10);
		//ETSIDI::printxy("Pulsa -t- para crear otro nivel", 26, 6);
	}
	else if (estado == SELECCION_NIVEL)
	{
		gluLookAt(ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 60.0f, // posicion del ojo
			ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/
		ETSIDI::setFont("fuentes/Pixel.ttf", 30);
		ETSIDI::printxy(&mundo.nivel.str[0], 20, 40);
		ETSIDI::printxy("Pulsa -s- para seleccionar el siguiente nivel", 10, 10);
		ETSIDI::printxy("Pulsa -e- para comenzar el nivel", 10, 5);
	}
	else if (estado == JUEGO)
	{
		long int t1 = getMillis();
		mundo.time = t1 - t0;
		mundo.dibuja();
		if (mundo.personaje.posicion.x > 200)
		{
			mundo.enemigos.destruirContenido();
			mundo.bonus.destruirContenido();
			mundo.nivel.suelos.destruirContenido();
			mundo.personaje.disparos.destruirContenido();
			mundo.personaje.setPos(2, 6);
			mundo.personaje.setVel(0, 0);
			estado = FIN;
		}
	}
	else if (estado == GAMEOVER)
	{
		mundo.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Pixel.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == FIN)
	{
		gluLookAt(ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 60.0f, // posicion del ojo
			ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/
		ETSIDI::setFont("fuentes/Pixel.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", 10, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", 10, 5);
		estado = SELECCION_NIVEL;
	}
	else if (estado == PAUSA)
	{
		mundo.dibuja();
		ETSIDI::setFont("fuentes/Pixel.ttf", 16);
		ETSIDI::printxy("En pausa", mundo.x_pto_ojo, 40);
		ETSIDI::printxy("Pulsa -C- para continuar", mundo.x_pto_ojo, 38);
	}
}
void Coordinador::tecla(unsigned char key) {
	if (estado == INICIO) {
		if (key == 'e')
		{
			mundo.inicializa();
			estado = JUEGO;
		}
		if (key == 'f')
		{
			estado = NIVELES;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == NIVELES)
	{
		if (key == 's')
		{
			mundo.nivel.seleccion(mundo.nivel.pantalla);
			estado = SELECCION_NIVEL;
		}
	}
	else if (estado == SELECCION_NIVEL)
	{
		static int cont = 1;
		if (key == 'e')
		{
			mundo.inicializa();
			estado = JUEGO;
			t0 = getMillis();
		}
		if (key == 's')
		{
			if (cont < mundo.nivel.pantallas_max)
			{
				mundo.nivel.pantalla++;
				cont++;
				mundo.nivel.seleccion(mundo.nivel.pantalla);
			}
		}
		if (key == 't')
		{
			mundo.nivel.crear();
		}
	}
	else if (estado == JUEGO)
	{
		mundo.tecla(key);
		if (key == 'p')
			estado = PAUSA;
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == PAUSA) {
		if (key == 'c')
			estado = JUEGO;
	}
}

void Coordinador::teclaEspecial(unsigned char key)
{
	if (estado == JUEGO)
		mundo.teclaEspecial(key);
}

void Coordinador::mueve()
{
	if (estado == JUEGO)
	{
		mundo.mueve();
		//if (mundo.
		//{
			//	estado = FIN;
		//}
		if (mundo.getVida()==0)
		{
			estado = GAMEOVER;
		}
	}
}

Coordinador::~Coordinador() {}