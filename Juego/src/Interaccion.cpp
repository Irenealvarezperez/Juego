#include "Interaccion.h"
#include <iostream>

using namespace std;
static long time01 = 0;
static long time0 = 0;
void Interaccion::rebote(Personaje& p, Mapa& m)
{
	//en un futuro habria que mejorar este codigo para que solo busque los suelos que hay en su direccion de movimiento o cerca suya

	int i=0;
	while (i < m.suelos.numero)	//Para el choque personaje suelo en vertical
	{
		float p_izda = p.getPos().x - p.getLado() / 2.0;
		float p_dcha = p.getPos().x + p.getLado() / 2.0;
		float p_arriba = p.getPos().y + p.getLado() / 2.0;
		float p_abajo = p.getPos().y - p.getLado() / 2.0;

		float s_izda = m.suelos.lista[i]->getPos().x - m.suelos.lista[i]->getLado() / 2.0;
		float s_dcha = m.suelos.lista[i]->getPos().x + m.suelos.lista[i]->getLado() / 2.0;
		float s_arriba = m.suelos.lista[i]->getPos().y + m.suelos.lista[i]->getLado() / 2.0;
		float s_abajo = m.suelos.lista[i]->getPos().y - m.suelos.lista[i]->getLado() / 2.0;

		p.aceleracion.y = -10; //Afecta la gravedad pero se anula si hay choque

		if (p_dcha > s_izda && p_izda < s_dcha && p_arriba > s_abajo && p_abajo <= s_arriba)
		{
			if (abs(p.getPos().x - m.suelos.lista[i]->getPos().x) <= abs(p.getPos().y - m.suelos.lista[i]->getPos().y) ? 1 : 0)
			{
				if (p_arriba >= s_abajo && p.velocidad.y > 0)
				{
					p.setPos(p.getPos().x, s_abajo - p.getLado() / 2.0);
					p.setVel(p.getVel().x, -p.velocidad.y / 2);
				}
				else if (p_arriba >= s_abajo && p.velocidad.y < 0)
				{
					p.setPos(p.getPos().x, s_arriba + p.getLado() / 2.0);
					if (p.getVel().y <= -30) { p.vida--; }
					p.setVel(p.getVel().x / 10, 0);
					p.tecla_bloq = 0;
				}
				break;
			}
			else
			{
				if (p_dcha > s_izda && p.velocidad.x > 0)
				{
					p.setPos(s_izda - p.getLado() / 2.0, p.getPos().y);
				}
				else if (p_izda < s_dcha && p.velocidad.x < 0)
				{
				p.setPos(s_dcha + p.getLado() / 2.0, p.getPos().y);
				}
				p.setVel(0, p.getVel().y);
				break;
			}
			/*
			Vector2D dir;
			float dist = m.suelos.lista[i]->distancia(p.getPos(), &dir)-p.lado/2;
			float arg = dir.argument();
			float x =dist*sin(arg);
			float y = dist*cos(arg);


			if (x > 0) {
				p.velocidad.x = 0;
				//p.posicion.x -= x;
			}

			if (y > 0 ) {
				p.velocidad.y = 0;
				//p.posicion.y += y;
			}
			*/
			p.aceleracion.y = 0; //Sino hay gravedad se evitan muchos problemas de atravesar suelos
		}
		i++;
	}
}

void Interaccion::choque(ListaDisparos& d, ListaEnemigos& e)
{
	for (int i = 0; i < e.numero; i++)
	{
		for (int j = 0; j < d.numero; j++)
		{
			Vector2D diferencia = e.lista[i]->getPos() - d.lista[j]->getPos();
			if (diferencia.module() <= e.lista[i]->getAncho())
			{
				d.eliminar(j);
				if (e.lista[i]->vida == 1)
				{
					if (e.lista[i]->getTipo() == Enemigo::GRANVIRUS)
					{
						auto gv = dynamic_cast<GranVirus*>(e.lista[i]);
						gv->dispara(e);
					}
					e.eliminar(i);
				}
				else
				{
					e.lista[i]->vida -= 1;
					if (diferencia.x <= 0)
						e.lista[i]->posicion.x -= 2;
					if(diferencia.x >0)
						e.lista[i]->posicion.x += 2;
				}
			}
		}
	}
}

void Interaccion::choque(Personaje& p, ListaBonus& b)
{
	long int t1;
	for (int i = 0; i < b.numero; i++)
	{
		
		
		if ((b.lista[i]->getPos() - p.getPos()).module() <= b.lista[i]->getLado())
		{
			switch (b.lista[i]->getTipo()) 
			{
			case Bonus::Tipo::MASCARILLAS:
				if(p.getVida()<5)
				p.setVida(p.getVida() + 1);
				break;
			case Bonus::Tipo::BOTIQUIN:
				p.setVida(5);
				break;
			case Bonus::Tipo::PAPEL:
				p.setPapel();
				break;
			case Bonus::Tipo::VACUNA:
				p.disparos.max_disparos +=1;
				break;
			case Bonus::Tipo::ESPIRAL:
				//hacer que no le baje la vida ni el escudo en ese tiempo
				time01=getMillis();
				p.invencible = true;
				break;
			
			case Bonus::Tipo::ESCUDO:
				p.setEscudo(true);
				break;
			}
			b.eliminar(i);
		}
		if (p.invencible == true)
		{
			t1 = getMillis();
			if ((t1 - time01) > 5000)p.invencible = false;
		}
	}
}

void Interaccion::choque(ListaDisparos& d, Mapa& m)
{
	for (int i = 0; i < d.numero; i++)
	{
		for (int j = 0; j < m.suelos.numero; j++)
		{
			Vector2D posicion = d.lista[i]->getPos(); //variable auxiliar de la posicion del disparo
			if ((posicion - m.suelos.lista[j]->getPos()).module() <= m.suelos.lista[i]->getLado())
			{
				d.eliminar(i);
			}
			else if (posicion.x < -10 || posicion.y > 46 || posicion.x>200) 
			{ 
				d.eliminar(i); 
			}
		}
	}
}

void Interaccion::choque(ListaDisparos& d, Personaje& p)
{
	for (int i = 0; i < d.numero; i++)
	{
		if ((d.lista[i]->getPos() - p.getPos()).module() <= p.getLado())
		{
			d.eliminar(i);
			if (p.invencible == false) { //si está activada la espiral no disminuye la vida ni el escudo
				if (p.getEscudo() == false)
					p.setVida(p.getVida() - 1);
				else
				{
					p.restaDuracionEscudo();
					if (p.getDuracionEscudo() == 0)
						p.setEscudo(false);
				}
			}
		}
	}
}

bool Interaccion::rebote(Enemigo& e, Personaje& p)
{
	bool flag = false;
	if (abs(p.getVel().y) > 10) flag = true;

	//Vector que une los centros
	Vector2D dif = p.getPos() - e.getPos();
	float d = dif.module();
	float dentro1 = d - (e.getAncho() + p.getLado());//choque en vertical
	float dentro2 = d - (e.getAncho() + p.getLado());//choque en horizontal

	if (dentro1 < 0.0f || dentro2 < 0.0f)//si hay colision
	{
		//Cálculo módulos y argumentos velocidades ambas bolas
		float vel1 = e.getVel().module();
		float angulo1 = e.getVel().argument();
		float vel2 = p.getVel().module();
		float angulo2 = p.getVel().argument();

		//el argumento del vector que une los centros
		float angd = dif.argument();

		//Separamos los enemigos, lo que se han incrustado
		//la mitad cada una
		if (dentro1 > dentro2) {
			Vector2D desp(dentro1 / 2 * static_cast<float>(cos(angd)), dentro1 / 2 * static_cast<float>(sin(angd)));
			e.setPos(e.getPos().x + desp.x, e.getPos().y);
			p.setPos(p.getPos().x - 2*desp.x, p.getPos().y - desp.y);
		}
		if (dentro2 > dentro1) {
			Vector2D desp(dentro2 / 2 * static_cast<float>(cos(angd)), dentro2 / 2 * static_cast<float>(sin(angd)));
			e.setPos(e.getPos().x + desp.x, e.getPos().y);
			p.setPos(p.getPos().x - 2*desp.x, p.getPos().y - desp.y);
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
		float m1 = e.altura;//
		float m2 = p.lado;//
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
		p.setVel(static_cast<float>(modv2 * cos(fi2)), 5 + static_cast<float> (modv2 * sin(fi2)));
		if (flag) return true;
	}
	return false;
}

void Interaccion::atacar(ListaEnemigos& e, Personaje& p)
{
	for (int i = 0; i < e.numero; i++)
	{
		switch (e.lista[i]->getTipo())
		{
		case Enemigo::MURCIELAGO:
		{
			if (e.lista[i]->getPos().x - p.getPos().x <= 100)
			{
				auto m = dynamic_cast<Murcielago*>(e.lista[i]);
				m->setTime1(getMillis());
				if (m->getTime1() - m->getTime0() > 2000)
				{
					dynamic_cast<Murcielago*>(e.lista[i])->dispara(0, -10.0f, 180);
					m->setTime0(getMillis());
				}
			}
			Vector2D diferencia = e.lista[i]->getPos() - p.getPos();
			if (diferencia.module() <= p.getLado())
			{
				if (rebote(*(e.lista[i]), p))
				{
					if (e.lista[i]->vida == 1)
						e.eliminar(i);
					else
					{
						e.lista[i]->vida -= 1;
						if (diferencia.x <= 0)
							e.lista[i]->posicion.x -= 2;
						if (diferencia.x > 0)
							e.lista[i]->posicion.x += 2;
					}
				}
				if (p.invencible == false) { //si está activada la espiral no disminuye la vida ni el escudo
					if (p.getEscudo() == false)
						p.setVida(p.getVida() - 1);
					else
					{
						p.restaDuracionEscudo();
						if (p.getDuracionEscudo() == 0)
							p.setEscudo(false);
					}
				}
			}

			break;
		}
		case Enemigo::MINIVIRUS:
		{
			Vector2D diferencia = e.lista[i]->getPos() - p.getPos();
			if (diferencia.module() <= p.getLado())
			{
				if (rebote(*(e.lista[i]), p))
				{
					if (e.lista[i]->vida == 1)
						e.eliminar(i);
					else
					{
						e.lista[i]->vida -= 1;
						if (diferencia.x <= 0)
							e.lista[i]->posicion.x -= 2;
						if (diferencia.x > 0)
							e.lista[i]->posicion.x += 2;
					}
				}
				if (p.invencible == false) { //si está activada la espiral no disminuye la vida ni el escudo
					if (p.getEscudo() == false)
						p.setVida(p.getVida() - 1);
					else
					{
						p.restaDuracionEscudo();
						if (p.getDuracionEscudo() == 0)
					   p.setEscudo(false);
					}
				}
			}

			
			break;
		}
		case Enemigo::GRANVIRUS:
		{
			Vector2D diferencia = e.lista[i]->getPos() - p.getPos();
			if (diferencia.module() <= p.getLado())
			{
				if (rebote(*(e.lista[i]), p))
				{
					if (e.lista[i]->vida == 1)
						e.eliminar(i);
					else
					{
						e.lista[i]->vida -= 1;
						if (diferencia.x <= 0)
							e.lista[i]->posicion.x -= 2;
						if (diferencia.x > 0)
							e.lista[i]->posicion.x += 2;
					}
				}
				if (p.invencible == false) { //si está activada la espiral no disminuye la vida ni el escudo
					if (p.getEscudo() == false)
						p.setVida(p.getVida() - 1);
					else
					{
						p.restaDuracionEscudo();
						if (p.getDuracionEscudo() == 0)
							p.setEscudo(false);
					}
				}
			}
			if (e.lista[i]->getPos().x - p.getPos().x <= 100)
			{
				auto m = dynamic_cast<GranVirus*>(e.lista[i]);
				m->setTime1(getMillis());
				if (m->getTime1() - m->getTime0() > 1000)
				{
					m->dispara(-10.0f, 0.0f, 90);
					m->setTime0(getMillis());
				}
			}
			
			break;
		}
		case Enemigo::CONTAGIADO:
		{
			Vector2D diferencia = e.lista[i]->getPos() - p.getPos();
			if (diferencia.module() <= p.getLado())
			{
				if (rebote(*(e.lista[i]), p))
				{
					if (e.lista[i]->vida == 1)
						e.eliminar(i);
					else
					{
						e.lista[i]->vida -= 1;
						if (diferencia.x <= 0)
							e.lista[i]->posicion.x -= 2;
						if (diferencia.x > 0)
							e.lista[i]->posicion.x += 2;
					}
				}
				if (p.invencible == false) { //si está activada la espiral no disminuye la vida ni el escudo
					if (p.getEscudo() == false)
						p.setVida(p.getVida() - 1);
					else
					{
						p.restaDuracionEscudo();
						if (p.getDuracionEscudo() == 0)
							p.setEscudo(false);
					}
				}
			}
			break;
		}
		}
	}
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

void Interaccion::spawn(ListaEnemigos& e)
{
	
	long t1 = getMillis();
	if ((t1 - time0) > 3000) {
		e.agregar(new Minivirus(6, 6, 190, 2.5, -5, 0));
		time0 = getMillis();
	}

}