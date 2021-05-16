#include "Mapa.h"
#include <iostream>
#include <fstream>
#include "VariablesGlobales.h"

#pragma warning(disable : 4996)

void Mapa::inicia(ListaBonus& bonus, ListaEnemigos &enemigos)
{
    FILE* fichero = nullptr;
    char c = NULL;
    int fila = 0 , columna = 0;
    Vector2D posicion;
    posicion.y = fila_max * Suelo::getLado();

    switch (pantalla)
    {
    case 1: {fichero = fopen("..\\src\\Nivel1.txt", "rt"); break; }
    case 2: {fichero = fopen("..\\src\\Nivel2.txt", "rt"); break; }
    default: {fichero = fopen("..\\src\\Nivel1.txt", "rt"); break; }
    }

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