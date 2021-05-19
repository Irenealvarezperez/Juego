#include "Mapa.h"
#include <iostream>
#include <fstream>
#include "VariablesGlobales.h"

#pragma warning(disable : 4996)

void Mapa::inicia(ListaBonus& bonus, ListaEnemigos& enemigos)
{
	FILE* fichero = nullptr;
	char c = NULL;
	int fila = 0, columna = 0;
	Vector2D posicion;
	posicion.y = fila_max * Suelo::getLado();
	string nombre;

	switch (pantalla)
	{
	case 1: {nombre = "1"; break; }
	case 2: {nombre = "2"; break; }
	default: {nombre = "1"; break; }
	}

	path.erase(12, 1);
	path.insert(12, nombre);
	fichero = fopen(&path[0], "rt");

	if (fichero)
	{
		while (!feof(fichero)) {
			fscanf(fichero, "%c", &c);
			if (c != '\n' && !feof(fichero) && columna <= columna_max && fila <= fila_max)
			{
				switch (c)
				{
				case '#': {suelos.agregar(new Suelo(posicion.x, posicion.y)); break; }
				case 'M': {bonus.agregar(bonus.setBonus("imagenes/mascarilla.png", posicion.x, posicion.y, 5, 4)); break; } //bonus mascarilla
				case 'P': {bonus.agregar(bonus.setBonus("imagenes/papel.png", posicion.x, posicion.y, 4, 4)); break; } //bonus papel
				case 'V': {bonus.agregar(bonus.setBonus("imagenes/vacuna.png", posicion.x, posicion.y, 4, 4)); break; } //bonus vacuna
				case 'B': {bonus.agregar(bonus.setBonus("imagenes/botiquin.png", posicion.x, posicion.y, 7, 4)); break; } //bonus botiquin
				case 'S': {bonus.agregar(bonus.setBonus("imagenes/escudo.png", posicion.x, posicion.y, 5, 6)); break; } //bonus escudo
				case 'L': {bonus.agregar(bonus.setBonus("imagenes/espiral.png", posicion.x, posicion.y, 5, 5)); break; } //bonus espiral
				case 'E': {enemigos.agregar(new Enemigo(5, posicion.x, posicion.y, 1, 1)); break; }
				}
				columna++;
				posicion.x += Suelo::getLado();
			}
			if (c == '\n' && columna <= columna_max && fila <= fila_max)
			{
				columna = 0;
				fila++;
				posicion.x = 0;
				posicion.y -= Suelo::getLado();
			}
		}
		fclose(fichero);
		fichero = nullptr;
	}
}

void Mapa::dibuja()
{
	suelos.dibuja();
}

void Mapa::crear()
{
	FILE* fichero = nullptr, * registro = fopen("..\\src\\Registro_Niveles.txt", "w+");
	char c, tmp;
	int fila, columna;
	string nombre;
	int num;

	cout << "Introduce el nombre del nivel: ";
	cin >> nombre;


	path.insert(12, nombre);
	fichero = fopen(&path[0], "at");

	fscanf(registro, "%d", &num);
	num++;
	fprintf(registro, "%d", num);
	fclose(registro);

	if (fichero && registro)
	{
		cout << "Introduce el numero de filas y columnas: ";
		cin >> fila >> columna;
		cout << "Ahora, introduce el diseño" << endl;
		scanf("%c", &tmp);
		for (int i = 0; i < fila; i++)
		{
			for (int j = 0; j <= columna; j++)
			{
				c = getc(stdin);
				fprintf(fichero, "%c", c);
			}
		}
		fclose(fichero);
		fichero = nullptr;
	}
}

int Mapa::seleccion(int nivel)
{
	FILE* registro = fopen("..\\src\\Registro_Niveles.txt", "rt");
	int puntuacion = 0;
	char tmp;
	char nombre[100];

	if (registro)
	{
		fscanf(registro, "%d%c", &pantallas_max, &tmp);
		if (nivel <= pantallas_max)
		{
			str = '\0';
			for (int i = 0; i < nivel; i++)
			{
				nombre[0] = '\0';
				fgets(nombre, 100, registro);
			}
			str.insert(0, nombre);
			fclose(registro);
			registro = nullptr;
		}
	}
	return puntuacion;
}