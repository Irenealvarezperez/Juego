#include "Mapa.h"
#include <iostream>
#include <fstream>
#include "VariablesGlobales.h"

#pragma warning(disable : 4996)

void Mapa::iniciar_nivel(int nivel)
{
    char c = NULL;
    FILE* fe;
    int fila = 0;
    int columna = 0;

    switch (nivel)
    {
        default:
        {
            fe = fopen("..\\src\\Nivel1.txt", "rt");
            break;
        }
    }

    if (fe)
    {
        while (!feof(fe)) {
            fscanf(fe, "%c", &c);
            if (c != '\n' && !feof(fe))
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
        fclose(fe);
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
    double Ix = 0;
    for (int i = fila_max-1; i >=0; i--)
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