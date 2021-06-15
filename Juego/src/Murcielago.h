#pragma once
#include"Enemigo.h"
class Murcielago: public Enemigo
{
public:
    Murcielago(float altura, float anchura, float x, float y, float vx, float vy);
    void dibuja();
};

