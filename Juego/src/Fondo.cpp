#include "Fondo.h"
#include "ETSIDI.h"
#include "glut.h"
#include "VariablesGlobales.h"

void ponerimagen(const char path[])
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(path).id);
	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(-2, -2, -0.01);
	glTexCoord2d(1, 1); glVertex3f(ANCHO_PANTALLA / 6.75, -2, -0.01);
	glTexCoord2d(1, 0); glVertex3f(ANCHO_PANTALLA / 6.75, ALTO_PANTALLA / 16.0, -0.01);
	glTexCoord2d(0, 0); glVertex3f(-2, ALTO_PANTALLA / 16.0, -0.01);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE);
}

void Fondo::ponerFondo(int indice) {
	switch (indice)
	{
	case 1: ponerimagen("imagenes/fondohospital.png"); break;
	case 2: ponerimagen("imagenes/fondoaeropuerto.png"); break;
	case 3: ponerimagen("imagenes/fondosupermercado.png"); break;
	case 4: ponerimagen("imagenes/fondoapartamento.png"); break;
	case 5: ponerimagen("imagenes/fondociudad.png"); break;
	case 6: ponerimagen("imagenes/fondofinal.png"); break;
	default: ponerimagen("imagenes/fondohospital.png"); break;
	}
}