#pragma once
#include "Enemigo.h"
class Minivirus :
    public Enemigo
{
public:
    Minivirus(float altura, float anchura, float x, float y, float vx, float vy);
    void dibuja();
};

