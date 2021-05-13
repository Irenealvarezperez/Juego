#include "ListaDisparos.h"


ListaDisparos::ListaDisparos() {
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++) {
		lista[i] = 0;
	}
}

bool ListaDisparos::agregar(Disparo* d, float flip) {
	if (numero < MAX_DISPAROS) {
		lista[numero++] = d;
		if (flip != 0)
			d->sprite_disparo->setAngle(flip);
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

