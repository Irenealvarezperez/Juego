#include "Coordinador.h"

Coordinador::Coordinador() { estado = INICIO; }

void Coordinador::dibuja()
{
	if (estado == INICIO)
	{//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS
		gluLookAt(ANCHO_PANTALLA/35.0, ALTO_PANTALLA / 35.0, 60.0f, // posicion del ojo
			ANCHO_PANTALLA/35.0, ALTO_PANTALLA / 35.0, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Pixel.ttf", 30);
		ETSIDI::printxy("Juego", 10,30);
		ETSIDI::setTextColor(0, 1, 1);
		ETSIDI::setFont("fuentes/Pixel.ttf", 30);
		ETSIDI::printxy("The creatives", 10, 25);
		ETSIDI::setFont("fuentes/Pixel.ttf", 18);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("Pulse -F- para seleccionar los niveles", 10, 15);
		ETSIDI::printxy("Pulse -R- para reiniciar las estadisticas y los niveles creados", 10, 10);
	}
	else if (estado == NIVELES)
	{
		gluLookAt(ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 60.0f, // posicion del ojo
			ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Pixel.ttf", 30);
		ETSIDI::printxy("Seleccion de nivel", 30, 40);
		ETSIDI::printxy("Pulsa -s- para ver los niveles", 25, 10);
	}
	else if (estado == SELECCION_NIVEL)
	{
		gluLookAt(ANCHO_PANTALLA / 24.0, ALTO_PANTALLA / 25.0, 85.0f, // posicion del ojo
			ANCHO_PANTALLA / 24.0, ALTO_PANTALLA / 25.0, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/
		ETSIDI::setFont("fuentes/Pixel.ttf", 35);
		ETSIDI::printxy(&mundo.nivel.str[0], 15, 45);
		ETSIDI::setFont("fuentes/Pixel.ttf", 20);
		ETSIDI::printxy("Pulsa -S- para seleccionar el siguiente nivel", 60, 60);
		ETSIDI::printxy("Pulsa -A- para seleccionar el anterior nivel", 60, 55);
		ETSIDI::printxy("Pulsa -E- para comenzar el nivel", 60, 50);
		if (mundo.nivel.pantallas_completada >= mundo.nivel.pantallas_max)
		{
			ETSIDI::printxy("Pulsa -T- para crear un nivel ", 60, 45);
		}
		ETSIDI::printxy("Pulsa -F- para salir a la panatalla inicial", 60, 40);
		mundo.dibuja();
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
		//Aqui deberia eliminar todos los objetos e inicializar todo a cero
		mundo.enemigos.destruirContenido();
		mundo.bonus.destruirContenido();
		mundo.nivel.suelos.destruirContenido();
		mundo.personaje.disparos.destruirContenido();

		gluLookAt(ANCHO_PANTALLA / 24.0, ALTO_PANTALLA / 25.0, 85.0f, // posicion del ojo
			ANCHO_PANTALLA / 24.0, ALTO_PANTALLA / 25.0, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/

		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Pixel.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", 10, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", 10, 5);
	}
	else if (estado == FIN)
	{
		gluLookAt(ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 60.0f, // posicion del ojo
			ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/
		ETSIDI::setFont("fuentes/Pixel.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", 10, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", 10, 5);
		mundo.tiempo_nivel = 0;
	}
	else if (estado == PAUSA)
	{
		mundo.dibuja();
		ETSIDI::setFont("fuentes/Pixel.ttf", 16);
		ETSIDI::printxy("En pausa", mundo.x_pto_ojo, 40);
		ETSIDI::printxy("Pulsa -C- para continuar", mundo.x_pto_ojo, 38);
	}
	else if (estado == FINAL)
	{
		gluLookAt(ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 60.0f, // posicion del ojo
			ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/
		ETSIDI::setFont("fuentes/Pixel.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", 10, 20);
		ETSIDI::printxy("¡Ahora puedes crear tus propios niveles!", 10, 15);
		ETSIDI::printxy("Pulsa -S- para volver a la seleccion de niveles", 10, 10);
		ETSIDI::printxy("Pulsa -C- para salir", 10, 5);
	}
}
void Coordinador::tecla(unsigned char key) {
	if (estado == INICIO) {
		if (key == 'f')
		{
			estado = NIVELES;
		}
		if (key == 'r')
		{
			mundo.nivel.reiniciar();
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == NIVELES)
	{
		if (key == 's')
		{
			mundo.nivel.seleccion(mundo.nivel.pantalla);
			mundo.nivel.inicia(mundo.bonus, mundo.enemigos);
			estado = SELECCION_NIVEL;
		}
	}
	else if (estado == SELECCION_NIVEL)
	{
		if (key == 'e')
		{
			mundo.enemigos.destruirContenido();
			mundo.bonus.destruirContenido();
			mundo.nivel.suelos.destruirContenido();
			mundo.personaje.disparos.destruirContenido();
			
			mundo.inicializa();
			estado = JUEGO;
			t0 = getMillis();
		}
		if (key == 's')
		{
			mundo.enemigos.destruirContenido();
			mundo.bonus.destruirContenido();
			mundo.nivel.suelos.destruirContenido();
			mundo.personaje.disparos.destruirContenido();

			mundo.nivel.pantalla++;
			if (mundo.nivel.pantalla <= mundo.nivel.pantallas_max && mundo.nivel.pantalla <= mundo.nivel.pantallas_completada + 1)
			{
				mundo.nivel.seleccion(mundo.nivel.pantalla);
			}
			else
			{
				mundo.nivel.pantalla--;
				mundo.nivel.seleccion(mundo.nivel.pantalla);
			}
			mundo.nivel.inicia(mundo.bonus, mundo.enemigos);
		}
		if (key == 'a')
		{
			mundo.enemigos.destruirContenido();
			mundo.bonus.destruirContenido();
			mundo.nivel.suelos.destruirContenido();
			mundo.personaje.disparos.destruirContenido();

			mundo.nivel.pantalla--;
			if (mundo.nivel.pantalla > 1)
			{
				mundo.nivel.seleccion(mundo.nivel.pantalla);
			}
			else
			{
				mundo.nivel.pantalla = 1;
				mundo.nivel.seleccion(mundo.nivel.pantalla);
			}
			mundo.nivel.inicia(mundo.bonus, mundo.enemigos);
		}
		if (key == 't')
		{
			if (mundo.nivel.pantallas_completada >= mundo.nivel.pantallas_max)
			{
				mundo.nivel.crear();
				mundo.nivel.seleccion(mundo.nivel.pantalla);
				mundo.nivel.inicia(mundo.bonus, mundo.enemigos);
			}
		}
		if (key == 'f')
		{
			estado = INICIO;
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
		mundo.nivel.sumaPantallaCompletada();
		if (key == 'c')
		{
			if (mundo.nivel.pantallas_completada == mundo.nivel.pantallas_max)
			{
				estado = FINAL;
			}
			else
			{
				mundo.nivel.seleccion(mundo.nivel.pantalla);
				mundo.nivel.inicia(mundo.bonus, mundo.enemigos);
				estado = NIVELES;
			}
		}
	}
	else if (estado == PAUSA) {
		if (key == 'c')
			estado = JUEGO;
	}
	else if (estado == FINAL)
	{
		if (key == 'c')
			exit(0);
		if (key == 's')
		{
			mundo.nivel.seleccion(mundo.nivel.pantalla - 1);
			mundo.nivel.inicia(mundo.bonus, mundo.enemigos);
			mundo.dibuja();
			estado = SELECCION_NIVEL;
		}
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