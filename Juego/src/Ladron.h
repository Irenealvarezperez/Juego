#pragma once

#include "Enemigo.h"

class Ladron :public Enemigo
{
public:
    Ladron(float altura, float anchura, float x, float y, float vx, float vy);
    void dibuja();
};
