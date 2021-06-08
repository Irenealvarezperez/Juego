#pragma once
#include"Enemigo.h"
class Murcielago: public Enemigo
{
private:
    long t0 = 0;
    long t1;
public:
    Murcielago(float altura, float anchura, float x, float y, float vx, float vy);
    void dibuja();
    void dispara(float vx, float vy, float flip);
    long getTime0() { return t0; };
    long getTime1() { return t1; };
    void setTime0(long t0) { this->t0 = t0; };
    void setTime1(long t1) { this->t1 = t1; };
};

