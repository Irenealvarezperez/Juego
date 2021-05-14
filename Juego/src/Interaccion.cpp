#include "Interaccion.h"
//IDEA- VER SI ES NECESARIO

void Interaccion::rebote(Personaje& p, Mapa m)
{
	float xmax = m.getFila_Max();
	float xmin = 0;
	float ymax = m.getColumna_Max();
	float ymin = 0;
	if (p.posicion.x > xmax)p.posicion.x = xmax;
	if (p.posicion.x < xmin)p.posicion.x = xmin;
	if (p.posicion.y > ymax)p.posicion.y = ymax;
	if (p.posicion.y < ymin)p.posicion.y = ymin;

	/*
	Posible forma de detectar colision con pared
	int px = (int)p.posicion.x;//conversion de posicion a entero para aproximar la posicion al pixel del mapa donde se encuentra
	int py = (int)p.posicion.y;
	if (m.cad[px][py] == '#')//en un futuro se deberia hacer funcion bool 'colision' que devuelva si el personaje colisiona o no
	{
		p.posicion.x = px;
		p.posicion.y = py;
		p.velocidad={0,0}
		p.aceleracion={0,0}
	}
	*/
}

bool Interaccion::rebote(Enemigo& e, Personaje p)
{
	

	return false;
}

bool Interaccion::rebote(Enemigo& e, Suelo s)
{
	Vector2D dir;
	float dif = s.distancia(e.posicion, &dir) - e.altura;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = e.velocidad;
		e.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
		e.posicion = e.posicion - dir * dif;
		return true;
	}
	return false;
}

bool Interaccion::rebote(Enemigo& enem1, Enemigo& enem2)
{
	//Vector que une los centros
	Vector2D dif = enem2.posicion - enem1.posicion;
	float d = dif.module();
	float dentro1 = d - (enem1.altura + enem2.altura);//choque en vertical
	float dentro2 = d - (enem1.ancho + enem2.ancho);//choque en horizontal

	if (dentro1 < 0.0f|| dentro2<0.0f)//si hay colision
	{
		//Cálculo módulos y argumentos velocidades ambas bolas
		float vel1 = enem1.velocidad.module();
		float angulo1 = enem1.velocidad.argument();
		float vel2 = enem2.velocidad.module();
		float angulo2 = enem2.velocidad.argument();

		//el argumento del vector que une los centros
		float angd = dif.argument();

		//Separamos los enemigos, lo que se han incrustado
		//la mitad cada una
		if (dentro1 > dentro2) {
			Vector2D desp(dentro1 / 2 * static_cast<float>(cos(angd)), dentro1 / 2 * static_cast<float>(sin(angd)));
			enem1.posicion = enem1.posicion + desp;
			enem2.posicion = enem2.posicion - desp;
		}
		if (dentro2 > dentro1) {
			Vector2D desp(dentro2 / 2 * static_cast<float>(cos(angd)), dentro2 / 2 * static_cast<float>(sin(angd)));
			enem1.posicion = enem1.posicion + desp;
			enem2.posicion = enem2.posicion - desp;
		}

		angd = angd - 3.14159f / 2;//la normal al choque

		//El angulo de las velocidades en el sistema relativo antes del choque
		float theta1 = angulo1 - angd;
		float theta2 = angulo2 - angd;

		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x = static_cast<float>(vel1 * cos(theta1));
		float u1y = static_cast<float>(vel1 * sin(theta1));
		float u2x = static_cast<float>(vel2 * cos(theta2));
		float u2y = static_cast<float>(vel2 * sin(theta2));

		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x = u1x;
		float v2x = u2x;

		//en el eje Y, rebote elastico
		float m1 = enem1.altura;//
		float m2 = enem2.altura;//
		float py = m1 * u1y + m2 * u2y;//Cantidad de movimiento inicial ejey
		float ey = m1 * u1y * u1y + m2 * u2y * u2y;//Energia cinetica inicial ejey

		//los coeficientes y discriminante de la ecuacion cuadrada
		float a = m2 * m2 + m1 * m2;
		float b = -2 * py * m2;
		float c = py * py - m1 * ey;
		float disc = b * b - 4 * a * c;
		if (disc < 0)disc = 0;

		//las nuevas velocidades segun el eje Y relativo
		float v2y = static_cast<float>((-b + sqrt(static_cast<double>(disc))) / (2 * static_cast<double>(a)));
		float v1y = (py - m2 * v2y) / m1;

		//Modulo y argumento de las velocidades en coordenadas absolutas
		float modv1, modv2, fi1, fi2;
		modv1 = static_cast<float>(sqrt(static_cast<double>(v1x) * static_cast<double>(v1x) + static_cast<double>(v1y) * static_cast<double>(v1y)));
		modv2 = static_cast<float>(sqrt(static_cast<double>(v2x) * static_cast<double>(v2x) + static_cast<double>(v2y) * static_cast<double>(v2y)));
		fi1 = static_cast<float>(angd + atan2(v1y, v1x));
		fi2 = static_cast<float>(angd + atan2(v2y, v2x));

		//Velocidades en absolutas despues del choque en componentes
		enem1.velocidad.x = static_cast<float> (modv1 * cos(fi1));
		enem1.velocidad.y = static_cast<float>(modv1 * sin(fi1));
		enem2.velocidad.x = static_cast<float>(modv2 * cos(fi2));
		enem2.velocidad.y = static_cast<float> (modv2 * sin(fi2));
	}
	return false;
}
