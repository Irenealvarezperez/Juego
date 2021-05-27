#pragma once

#include "Enemigo.h"

class Ladron :public Enemigo
{
public:
    Ladron(float altura, float x, float y, float vx, float vy);
    void dibuja();
    void dispara(float vx, float vy, float flip);
};
