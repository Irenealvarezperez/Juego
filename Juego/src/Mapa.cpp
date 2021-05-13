#include "Mapa.h"
#include <iostream>
#include <fstream>
#include "VariablesGlobales.h"

#pragma warning(disable : 4996)

void Mapa::inicia(int nivel, Bonus bonus[], ListaEnemigos &enemigos)
{
    char c = NULL;
    FILE* fichero;
    int fila = 0;
    int columna = 0;

    int cont_suelo = 0, cont_bonus = 0;

    switch (nivel)
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
            switch (c)
            {
            case '#': {cont_suelo++; break; }
            case 'B': {cont_bonus++; break; }
            }
        }
        fclose(fichero);
        fichero = nullptr;
    }
    bonus->numero = cont_bonus;

    int Iy = 0;
    for (int i = fila_max - 1; i >= 0; i--)
    {
        for (int j = 0; j < columna_max; j++)
        {
            switch (cad[i][j])
            {
            case '#': {suelo[i][j].setPos(suelo[i][j].lado * j, Iy); break; }
            case 'B': {bonus[--cont_bonus].setPos(suelo[i][j].lado * j, Iy); break; }
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