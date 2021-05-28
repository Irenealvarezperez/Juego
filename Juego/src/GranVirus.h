#pragma once
#include "Enemigo.h"
class GranVirus :
    public Enemigo
{
public:
    GranVirus(float altura,float anchura, float x, float y, float vx, float vy);
    void dibuja();
};

