#pragma once
#include "Enemigo.h"
#include "Minivirus.h"
#include "ListaEnemigos.h"

class GranVirus :public Enemigo
{
public:
    GranVirus(float altura,float anchura, float x, float y, float vx, float vy);
    void dibuja();
    void dispara(ListaEnemigos& enemigos);
};

