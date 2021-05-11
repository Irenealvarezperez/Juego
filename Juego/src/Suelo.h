#pragma once

class Suelo
{
public:
	int x = 0, y = 0, lado = 3;
public:
	Suelo();
	Suelo(int x, int y);
	void dibuja();
	void setPos(int x, int y);
};

