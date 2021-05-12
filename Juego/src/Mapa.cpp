#include "Mapa.h"
#include <iostream>
#include <fstream>
#include "VariablesGlobales.h"

#pragma warning(disable : 4996)

void Mapa::iniciar_nivel(int nivel)
{
    char c = NULL;
    FILE* fichero;
    int fila = 0;
    int columna = 0;

    switch (nivel)
    {
        default:
        {
            fichero = fopen("..\\src\\Nivel1.txt", "rt");
            break;
        }
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
    for (int i = 0; i < fila_max; i++)
    {
        for (int j = 0; j < columna_max; j++)
        {
            std::cout << cad[i][j];
        }
        std::cout << std::endl;
    }
}

void Mapa::dibuja()
{
    int Ix = 0;
    for (int i = fila_max - 1; i >= 0; i--)
    {
        for (int j = 0; j < columna_max; j++)
        {
            if (cad[i][j] == '#')
            {
                suelo[i][j].setPos(suelo[i][j].lado * j, Ix);
                suelo[i][j].dibuja();
            }
        }
        Ix += suelo[i][0].lado;
    }
}