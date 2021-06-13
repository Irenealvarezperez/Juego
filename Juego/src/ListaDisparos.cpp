#include "ListaDisparos.h"

ListaDisparos::ListaDisparos() {
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++) {
		lista[i] = 0;
	}
	max_disparos = 1;
}

bool ListaDisparos::agregar(Disparo* d, float flip) {
	if (numero < max_disparos) {
		lista[numero++] = d;
		if (flip != 0)
			d->disparo->setAngle(flip);
		ETSIDI::play("sonidos/disparo.mp3");
	}
	else return false;
	return true;
}

void ListaDisparos::destruirContenido() {
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaDisparos::mueve(float t) {
	for (int i = 0; i < numero; i++) {
		lista[i]->mueve(t);
	}
}

void ListaDisparos::dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->dibuja();
	}
}

ListaDisparos::~ListaDisparos() {
	destruirContenido();
}

void ListaDisparos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}