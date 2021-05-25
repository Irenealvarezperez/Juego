#pragma once

#include"ETSIDI.h"
using namespace ETSIDI;

class ObjetoMovil //clase base de los objetos móviles que usen secuencias de sprites
{
protected:
	Vector2D posicion, velocidad, aceleracion;
	SpriteSequence* sprite;
public:
	virtual void mueve(float t);
	Vector2D getPos() { return posicion; };
	virtual void setPos(float ix, float iy) { posicion.x = ix, posicion.y = iy, sprite->setPos(ix, iy); };
	virtual void setVel(float vx, float vy) { velocidad.x = vx, velocidad.y = vy, sprite->setVel(vx,vy); };
	friend class Coordinador;
};

