#include "CoordinadorAj.h"

CoordinadorAj::CoordinadorAj()
{
	modo = INICIO;
}

CoordinadorAj::~CoordinadorAj()
{
}

void CoordinadorAj::draw()
{
	if (modo == INICIO) {
		tablerogl.draw();
	}
	else if (modo == JUEGO)
	{
		tablerogl.draw();
	}
	else if (modo == PAUSA)
	{
		tablerogl.draw();
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA", -2, 10);
		ETSIDI::printxy("Pulsa C para continuar", -5, 5);
	}
	else if (modo == DERROTA)
	{
		tablerogl.draw();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (modo == VICTORIA)
	{
		tablerogl.draw();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
	else if (modo == TABLAS)
	{
		tablerogl.draw();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("TABLAS", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
}

void CoordinadorAj::teclaEspecial(int x, int y, int button, bool down, bool sKey, bool ctrlKey)
{
		if (modo == JUEGO)
			tablerogl.MouseButton(x, y, button, down, sKey, ctrlKey);
}

void CoordinadorAj::Tecla(unsigned char key)
{
	if (modo == INICIO)
	{
		if (key == 'e')
		{
			tablerogl.drawMatriz();	//funcion que dibuja el estado inicial del juego
				for (int i = 0; i < 8/*TableroGL::N*/; i++) {
					for (int j = 0; j < 8/*TableroGL::N*/; j++) {
						tablerogl.drawCasillaIni(i, j);
					}
				}
			modo = JUEGO;
		}
		if (key == 's')
			exit(0);
	}
	else if (modo == JUEGO)
	{
		//tablerogl.MouseButton();
		if (key == 'p')
			modo = PAUSA;
	}
	else if (modo == PAUSA)
	{
		modo = JUEGO;
	}
	else if (modo == DERROTA)
	{
		if (key == 'c')
			modo = INICIO;
	}
	else if (modo == VICTORIA)
	{
		if (key == 'c')
			modo = INICIO;
	}
}



