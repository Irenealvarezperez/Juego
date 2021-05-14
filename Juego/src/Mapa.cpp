#include "Mapa.h"
#include <iostream>
#include <fstream>
#include "VariablesGlobales.h"

#pragma warning(disable : 4996)

void Mapa::inicia(ListaBonus& bonus, ListaEnemigos &enemigos)
{
    FILE* fichero = nullptr;
    char c = NULL;
    int fila = 0, columna = 0;

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
            if (c != '\n' && !feof(fichero) && columna < columna_max)
            {
                cad[fila][columna] = c;
                columna++;
            }
            if (c == '\n' && fila < fila_max)
            {
                columna = 0;
                fila++;
            }
        }
        fclose(fichero);
        fichero = nullptr;
    }

    int Iy = 0;
    for (int i = fila_max - 1; i >= 0; i--)
    {
        for (int j = 0; j < columna_max; j++)
        {
            switch (cad[i][j])
            {
            case '#': {suelo[i][j].setPos(suelo[i][j].lado * j, Iy); break; }
            case 'M': {bonus.agregar(bonus.setBonus("imagenes/mascarilla.png", suelo[i][j].lado * j, Iy, 5, 4)); break; } //bonus mascarilla
            case 'P': {bonus.agregar(bonus.setBonus("imagenes/papel.png", suelo[i][j].lado * j, Iy, 4, 4)); break; } //bonus papel
            case 'V': {bonus.agregar(bonus.setBonus("imagenes/vacuna.png", suelo[i][j].lado * j, Iy, 4,4)); break; } //bonus vacuna
            case 'B': {bonus.agregar(bonus.setBonus("imagenes/botiquin.png", suelo[i][j].lado * j, Iy, 7, 4)); break; } //bonus botiquin
            case 'S': {bonus.agregar(bonus.setBonus("imagenes/escudo.png", suelo[i][j].lado * j, Iy, 5, 6)); break; } //bonus escudo
            case 'L': {bonus.agregar(bonus.setBonus("imagenes/espiral.png", suelo[i][j].lado * j, Iy, 5, 5)); break; } //bonus espiral
            case 'E': {enemigos.agregar(new Enemigo(5, suelo[i][j].lado * j, Iy, 0, 0)); break; }
            }
        }
        Iy += suelo[i][0].lado;
    }
}

void Mapa::dibuja()
{
    int Ix = 0;
    for (int i = fila_max - 1; i >= 0; i--)
    {
        for (int j = 0; j < columna_max; j++)
        {
            switch (cad[i][j])
            {
            case '#': {suelo[i][j].dibuja(); break; }
            }
        }
        Ix += suelo[i][0].lado;
    }
}