#include "Coordinador.h"

void pantallaVacia() { gluLookAt(ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 60.0f, ANCHO_PANTALLA / 35.0, ALTO_PANTALLA / 35.0, 0.0, 0.0, 1.0, 0.0); }
void pantallaVaciaEspecial() { gluLookAt(ANCHO_PANTALLA / 24.0, ALTO_PANTALLA / 25.0, 85.0f, ANCHO_PANTALLA / 24.0, ALTO_PANTALLA / 25.0, 0.0, 0.0, 1.0, 0.0); }
void poner_imagen(const char path[])
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(path).id);
	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex2f(10, 10);
	glTexCoord2d(1, 1); glVertex2f(ANCHO_PANTALLA / 20.0, 10);
	glTexCoord2d(1, 0); glVertex2f(ANCHO_PANTALLA / 20.0, ALTO_PANTALLA / 20.0);
	glTexCoord2d(0, 0); glVertex2f(10, ALTO_PANTALLA / 20.0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE);
}

Coordinador::Coordinador() { estado = HISTORIA; }

Coordinador::~Coordinador() {}

void Coordinador::destruirContenido()
{
	mundo.enemigos.destruirContenido();
	mundo.bonus.destruirContenido();
	mundo.nivel.suelos.destruirContenido();
	mundo.personaje.disparos.destruirContenido();
}

void Coordinador::dibuja()
{
	switch (estado)
	{
	case HISTORIA:
	{
		if (pantalla_historia <= 21)
		{
			path.erase(17, 2);
			path.insert(17, to_string(pantalla_historia));
		}
		else
		{
			estado = INICIO;
			break;
		}

		pantallaVacia();
		poner_imagen(&path[0]);
		break;
	}
	case INICIO:
	{
		pantallaVacia();
		setTextColor(255, 255, 0);
		setFont("fuentes/Pixel.ttf", 30);
		printxy("Juego", 10, 30);
		setTextColor(0, 255, 255);
		setFont("fuentes/Pixel.ttf", 30);
		printxy("The creatives", 10, 25);
		setFont("fuentes/Pixel.ttf", 18);
		setTextColor(255, 255, 255);
		printxy("Pulse -F- para seleccionar los niveles", 10, 15);
		printxy("Pulse -R- para reiniciar las estadisticas y los niveles creados", 10, 10);
		break;
	}
	case NIVELES:
	{
		pantallaVacia();
		setTextColor(255, 255, 255);
		setFont("fuentes/Pixel.ttf", 30);
		printxy("Seleccion de nivel", 30, 40);
		printxy("Pulsa -s- para ver los niveles", 25, 10);
		break;
	}
	case SELECCION_NIVEL:
	{
		pantallaVaciaEspecial();
		setFont("fuentes/Pixel.ttf", 35);
		printxy(&mundo.nivel.str[0], 15, 45);
		setFont("fuentes/Pixel.ttf", 20);
		printxy("Pulsa -S- para seleccionar el siguiente nivel", 60, 60);
		printxy("Pulsa -A- para seleccionar el anterior nivel", 60, 55);
		printxy("Pulsa -E- para comenzar el nivel", 60, 50);
		if (mundo.nivel.pantallas_completada >= mundo.nivel.pantallas_max) printxy("Pulsa -T- para crear un nivel ", 60, 45);
		printxy("Pulsa -F- para salir a la pantalla inicial", 60, 40);
		mundo.dibuja();
		break;
	}
	case JUEGO:
	{
		mundo.tiempo_nivel = getMillis() / 1000 - mundo.time;
		mundo.dibuja();
		if (mundo.personaje.Condicion() == true) //si el personaje se encuentra en posicion>200 y ha recogido un papel puede terminar el nivel
		{
			mundo.enemigos.destruirContenido();
			mundo.bonus.destruirContenido();
			mundo.nivel.suelos.destruirContenido();
			mundo.personaje.disparos.destruirContenido();
			mundo.personaje.reiniciar();
			estado = FIN;
		}
		break;
	}
	case GAMEOVER:
	{
		//Aqui deberia eliminar todos los objetos e inicializar todo a cero
		destruirContenido();
		pantallaVacia();
		poner_imagen("imagenes/Foto5.png");

		setTextColor(0, 0, 1);
		setFont("fuentes/Pixel.ttf", 16);
		printxy("GAMEOVER: Has perdido", 10, 50);
		setTextColor(255, 255, 255);
		printxy("Pulsa -C- para continuar", 10, 5);

		break;
	}
	case FIN:
	{
		pantallaVacia();
		
		if (mundo.nivel.getPantalla() == 1) {
			poner_imagen("imagenes/Foto_finNivel1.png");

			setTextColor(255, 255, 255);
			setFont("fuentes/Pixel.ttf", 26);
			printxy("¡Oh no, el virus ha escapado!", 28, 44);
			printxy("Ahora debes eliminarlos", 28, 40);
			setTextColor(255, 255, 255);
			printxy("Pulsa -C- para continuar", 10, 5);
			mundo.tiempo_nivel = 0;
			break;
		}
		if (mundo.nivel.getPantalla()==2) {
			poner_imagen("imagenes/Foto_finNivel2.png");

			setTextColor(255, 255, 255);
			setFont("fuentes/Pixel.ttf", 26);
			printxy("El ultimo vuelo sale en cinco minutos", 24, 44);
			printxy("Es tu ultima oportunidad de regresar", 24, 42);
			setTextColor(255, 255, 255);
			printxy("Pulsa -C- para continuar", 10, 5);
			mundo.tiempo_nivel = 0;
			break;
		}
		if (mundo.nivel.getPantalla() == 3) {
			poner_imagen("imagenes/Foto_finNivel3.png");

			setTextColor(255, 255, 255);
			setFont("fuentes/Pixel.ttf", 26);
			printxy("¡Por los pelos!", 16, 18);
			printxy("Proximo destino: Madrid.", 16, 16);
			printxy("En el proximo nivel deberas mantener al menos", 16, 14);
			printxy("un rollo de papel, ¡Cuidado, que es muy codiciado!", 16, 12);
			setTextColor(255, 255, 255);
			printxy("Pulsa -C- para continuar", 10, 5);
			mundo.tiempo_nivel = 0;
			break;
		}
		if (mundo.nivel.getPantalla() == 4) {
			poner_imagen("imagenes/Foto_finNivel4.png");

			setTextColor(0, 0, 255);
			setFont("fuentes/Pixel.ttf", 25);
			printxy("ENHORABUENA,", 44, 34);
			printxy("¡Has triunfado!", 44, 32);
			printxy("En el próximo nivel debes", 44, 30);
			printxy("obtener la primera llave", 44, 28);
			printxy("Necesitas dos para poder", 44, 26);
			printxy("pasar al nivel final", 44, 24);
			setTextColor(255, 255, 255);
			printxy("Pulsa -C- para continuar", 10, 5);
			mundo.tiempo_nivel = 0;
			break;
		}
		if (mundo.nivel.getPantalla() == 5) {
			poner_imagen("imagenes/Foto_finNivel5.png");

			setTextColor(255, 255, 255);
			setFont("fuentes/Pixel.ttf", 26);
			printxy("ENHORABUENA, ¡Has triunfado!", 24, 44);
			printxy("En el proximo nivel deberas obtener la segunda llave", 12, 42);
			printxy("¡Ya casi has llegado al final!", 26, 38);
			setTextColor(255, 255, 255);
			printxy("Pulsa -C- para continuar", 10, 5);
			mundo.tiempo_nivel = 0;
			break;
		}
		if (mundo.nivel.getPantalla() == 6) {
			poner_imagen("imagenes/Foto_finNivel6.png");

			setTextColor(255, 255, 255);
			setFont("fuentes/Pixel.ttf", 26);
			printxy("¡ENHORABUENA!, ahora te debes enfrentar al Gran Virus", 10, 44);
			printxy("Recoge todas las vacunas que puedas, las necesitaras", 11, 42);
			setTextColor(255, 255, 255);
			printxy("Pulsa -C- para continuar", 10, 5);
			mundo.tiempo_nivel = 0;
			break;
		}
		if (mundo.nivel.getPantalla() == 7) {
			poner_imagen("imagenes/Foto_finNivel7.png");

			setTextColor(255, 255, 255);
			setFont("fuentes/Pixel.ttf", 26);
			printxy("¡¡ENHORABUENA, HAS CONSEGUIDO", 20, 44);
			printxy("DERROTAR AL VIRUS, EL MUNDO ESTA A SALVO!!", 16, 42);
			setTextColor(255, 255, 0);
			printxy("Ahora ya", 57, 30);
			printxy("puedes crear", 57, 28);
			printxy("tus propios", 57, 26);
			printxy("niveles", 57, 24);
			setTextColor(255, 255, 255);
			printxy("Pulsa -C- para continuar", 10, 5);
			mundo.tiempo_nivel = 0;
			break;
		}
		else {
			
			poner_imagen("imagenes/Foto1.png");
			setTextColor(255, 255, 255);
			setFont("fuentes/Pixel.ttf", 26);
			printxy("ENHORABUENA, ¡Has triunfado!", 26, 24);
			setTextColor(255, 255, 255);
			printxy("Pulsa -C- para continuar", 10, 5);
			mundo.tiempo_nivel = 0;
			break;
		
		}
	}
	case PAUSA:
	{
		mundo.dibuja();
		setFont("fuentes/Pixel.ttf", 16);
		printxy("En pausa", (int)mundo.x_pto_ojo, 40);
		printxy("Pulsa -C- para continuar", (int)mundo.x_pto_ojo, 38);
		break;
	}
	case FINAL:
	{
		pantallaVacia();
		poner_imagen("imagenes/Foto3.png");

		setTextColor(0, 255, 0);
		setFont("fuentes/Pixel.ttf", 16);
		printxy("ENHORABUENA, ¡Has triunfado!", 10, 20);
		printxy("¡Ahora puedes crear tus propios niveles!", 26, 24);
		setTextColor(255, 255, 255);
		printxy("Pulsa -S- para volver a la seleccion de niveles", 10, 10);
		printxy("Pulsa -C- para salir", 10, 5);
		break;
	}
	}
}

void Coordinador::tecla(unsigned char key)
{
	switch (estado)
	{
	case HISTORIA:
	{
		if (key == ' ')
		{
			pantalla_historia++;
			estado = HISTORIA;
		}
		break;
	}
	case INICIO:
	{
		switch (key)
		{
		case 'f': estado = NIVELES; break;
		case 'F': estado = NIVELES; break;
		case 'r': mundo.nivel.reiniciar(); break;
		case 'R': mundo.nivel.reiniciar(); break;
		case 's': exit(0);
		case 'S': exit(0);
		}
		break;
	}
	case NIVELES:
	{
		switch (key)
		{
		case 's':
		{
			mundo.nivel.seleccion(mundo.nivel.pantalla);
			mundo.nivel.inicia(mundo.bonus, mundo.enemigos);
			estado = SELECCION_NIVEL;
			break;
		}
		case 'S':
		{
			mundo.nivel.seleccion(mundo.nivel.pantalla);
			mundo.nivel.inicia(mundo.bonus, mundo.enemigos);
			estado = SELECCION_NIVEL;
			break;
		}
		}
		break;
	}
	case SELECCION_NIVEL:
	{
		switch (key)
		{
		case 'e':
		{
			destruirContenido();
			mundo.inicializa();
			estado = JUEGO;
			break;
		}
		case 'E':
		{
			destruirContenido();
			mundo.inicializa();
			estado = JUEGO;
			break;
		}
		case 's':
		{
			destruirContenido();
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
			break;
		}
		case 'S':
		{
			destruirContenido();
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
			break;
		}
		case 'a':
		{
			destruirContenido();
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
			break;
		}
		case 'A':
		{
			destruirContenido();
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
			break;
		}
		case 't':
		{
			if (mundo.nivel.pantallas_completada >= mundo.nivel.pantallas_max)
			{
				mundo.nivel.crear();
				mundo.nivel.seleccion(mundo.nivel.pantalla);
				mundo.nivel.inicia(mundo.bonus, mundo.enemigos);
			}
			break;
		}
		case 'T':
		{
			if (mundo.nivel.pantallas_completada >= mundo.nivel.pantallas_max)
			{
				mundo.nivel.crear();
				mundo.nivel.seleccion(mundo.nivel.pantalla);
				mundo.nivel.inicia(mundo.bonus, mundo.enemigos);
			}
			break;
		}
		case 'f': estado = INICIO; break;
		case 'F': estado = INICIO; break;
		}
		break;
	}
	case JUEGO:
	{
		mundo.tecla(key);
		if (key == 'p' || key == 'P')
		{
			estado = PAUSA;
		}
		break;
	}
	case GAMEOVER:
	{
		if (key == 'c' || key == 'C')
		{
			destruirContenido();
			mundo.personaje.setPos(2, 4);
			mundo.personaje.setVel(0, 0);
			mundo.personaje.setVida(5);
			mundo.time = 0;
			mundo.tiempo_nivel = 0;
			estado = INICIO;
		}
		break;
	}
	case FIN:
	{
		mundo.nivel.sumaPantallaCompletada();
		if (key == 'c' || key == 'C')
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
		break;
	}
	case PAUSA:
	{
		if (key == 'c' || key == 'C')
		{
			estado = JUEGO;
		}
		break;
	}
	case FINAL:
	{
		switch (key)
		{
		case 'c': exit(0);
		case 'C': exit(0);
		case 's':
		{
			mundo.nivel.seleccion(mundo.nivel.pantalla - 1);
			mundo.nivel.inicia(mundo.bonus, mundo.enemigos);
			mundo.dibuja();
			estado = SELECCION_NIVEL;
			break;
		}
		case 'S':
		{
			mundo.nivel.seleccion(mundo.nivel.pantalla - 1);
			mundo.nivel.inicia(mundo.bonus, mundo.enemigos);
			mundo.dibuja();
			estado = SELECCION_NIVEL;
			break;
		}
		}
		break;
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

		if (mundo.getVida() <= 0 && mundo.nivel.getPantalla() > 1)
		{
			estado = GAMEOVER;
		}
		else if (mundo.getVida() <= 0 && mundo.nivel.getPantalla() == 1)
		{
			mundo.personaje.setPos(2, 4);
			mundo.personaje.setVel(0, 0);
			mundo.personaje.setVida(5);
			estado = FIN;
		}
	}
}
