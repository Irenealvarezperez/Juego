#include "Fondo.h"
#include "ETSIDI.h"
#include "glut.h"
#include "VariablesGlobales.h"

void Fondo::ponerFondo(int indice) {
	switch (indice)
	{
	case 1: {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondohospital.png").id);
		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex3f(-2, -2, -0.01);
		glTexCoord2d(1, 1); glVertex3f(ANCHO_PANTALLA / 6.75, -2, -0.01);
		glTexCoord2d(1, 0); glVertex3f(ANCHO_PANTALLA / 6.75, ALTO_PANTALLA / 16.0, -0.01);
		glTexCoord2d(0, 0); glVertex3f(-2, ALTO_PANTALLA / 16.0, -0.01);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE);
		break;
	}
	case 2: {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondoaeropuerto.png").id);
		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex3f(-2, -2, -0.01);
		glTexCoord2d(1, 1); glVertex3f(ANCHO_PANTALLA / 6.75, -2, -0.01);
		glTexCoord2d(1, 0); glVertex3f(ANCHO_PANTALLA / 6.75, ALTO_PANTALLA / 16.0, -0.01);
		glTexCoord2d(0, 0); glVertex3f(-2, ALTO_PANTALLA / 16.0, -0.01);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE);
		break;
	}
	case 3: {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondosupermercado.png").id);
		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex3f(-2, -2, -0.01);
		glTexCoord2d(1, 1); glVertex3f(ANCHO_PANTALLA / 6.75, -2, -0.01);
		glTexCoord2d(1, 0); glVertex3f(ANCHO_PANTALLA / 6.75, ALTO_PANTALLA / 16.0, -0.01);
		glTexCoord2d(0, 0); glVertex3f(-2, ALTO_PANTALLA / 16.0, -0.01);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE);
		break;
	}
	case 4: {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondoapartamento.png").id);
		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex3f(-2, -2, -0.01);
		glTexCoord2d(1, 1); glVertex3f(ANCHO_PANTALLA / 6.75, -2, -0.01);
		glTexCoord2d(1, 0); glVertex3f(ANCHO_PANTALLA / 6.75, ALTO_PANTALLA / 16.0, -0.01);
		glTexCoord2d(0, 0); glVertex3f(-2, ALTO_PANTALLA / 16.0, -0.01);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE);
		break;
	}
	case 5: {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondociudad.png").id);
		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex3f(-2, -2, -0.01);
		glTexCoord2d(1, 1); glVertex3f(ANCHO_PANTALLA / 6.75, -2, -0.01);
		glTexCoord2d(1, 0); glVertex3f(ANCHO_PANTALLA / 6.75, ALTO_PANTALLA / 16.0, -0.01);
		glTexCoord2d(0, 0); glVertex3f(-2, ALTO_PANTALLA / 16.0, -0.01);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE);
		break;
	}
	case 6: {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondofinal.png").id);
		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex3f(-2, -2, -0.01);
		glTexCoord2d(1, 1); glVertex3f(ANCHO_PANTALLA / 6.75, -2, -0.01);
		glTexCoord2d(1, 0); glVertex3f(ANCHO_PANTALLA / 6.75, ALTO_PANTALLA / 16.0, -0.01);
		glTexCoord2d(0, 0); glVertex3f(-2, ALTO_PANTALLA / 16.0, -0.01);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE);
		break;
	}
	}
}