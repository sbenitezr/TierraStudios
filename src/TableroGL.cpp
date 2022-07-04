#include "TableroGL.h"
#include "herramientasgl.h"
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include "freeglut.h"
#include "ETSIDI.h"
using namespace std;
int fin = 0;

TableroGL::TableroGL(Tablero* t){
	ancho = 1;
	N = t->getTamanio();
	dist = 2;
	centro_z = 0;
	modo = INICIO;
}

void TableroGL::init() {
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	m_tablero->tableroInicio();
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
}

void TableroGL::tecla(unsigned char key)
{
	//PANTALLA DE INICIO
	if (modo == INICIO) 
	{
		if (key == '1')
		{
			modo = JUGAR1;
			ETSIDI::play("sonidos/mola mucho este modo de juego.wav");
		}
		if (key == '2') {
			modo = JUGAR2;
			ETSIDI::play("sonidos/pitido futbol.mp3");
		}
		if (key == 's' || key == 'S') 
		{
			exit(0);
		}
	}

	//PANTALLA DE JUGAR
	if (modo == JUGAR1) 
	{
		modoAnterior = 1;
		ETSIDI::playMusica("sonidos/Musica para el juego.mp3", true);
		if (key == 'p' || key == 'P') 
		{
			modo = PAUSA;
			ETSIDI::stopMusica();
		}
	}

	if (modo == JUGAR2)
	{
		modoAnterior = 2;
		ETSIDI::playMusica("sonidos/estadio futbol.mp3", true);
		if (key == 'p' || key == 'P')
		{
			modo = PAUSA;
			ETSIDI::stopMusica();
		}
	}

	//PANTALLA DE PAUSA
	if (modo == PAUSA)
	{
		//Coordinador de las ventanas
		if (key == 'j' || key == 'J') {
			if (modoAnterior == 1) modo = JUGAR1;
			if (modoAnterior == 2) modo = JUGAR2;
			ETSIDI::playMusica("sonidos/Musica para el juego.mp3", true);
		}
		if (key == 'r' || key == 'R') {
			m_tablero->tableroInicio();
			m_tablero->turnos = 1;
			modo = INICIO;
			ETSIDI::playMusica("sonidos/Musica para el juego.mp3", true);
		}
		if (key == 's' || key == 'S')
			modo = FINAL;
	}

	//PANTALLA FINAL
	if (modo == FINAL)
	{
		ETSIDI::stopMusica();

		if (key == 'r' || key == 'R') {
			m_tablero->tableroInicio();
			m_tablero->turnos = 1;
			modo = INICIO;
			ETSIDI::playMusica("sonidos/Musica para el juego.mp3", true);
		}
		if (key == 's' || key == 'S') {
			exit(0);
		}
	}
}

void TableroGL::drawMatriz() {
	GLTools::Color(gltools::BLACK);
	float dist = N * ancho;
	for (int i = 0; i <= N; i++) {
		if (i % N == 0) glLineWidth(4);
		else glLineWidth(1);
		glBegin(GL_LINES);
		glVertex3f(i * ancho, 0, 0);
		glVertex3f(i * ancho, -dist, 0);
		glVertex3f(0, -i * ancho, 0);
		glVertex3f(dist, -i * ancho, 0);
		glEnd();
	}
}

void TableroGL::draw() {
	
	// PANTALLA DE INICIO

	if (modo == INICIO) 
	{
		centro_x = 0;
		centro_y = 7.5;
		centro_z = 0;
		//Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(centro_x, centro_y, -20, centro_x, centro_y, centro_z, 0, 1, 0);
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		//EL CENTRO DE LA IMAGEN ES EL (0, 7.5)
		//TIENE DIMENSIONES DE 20 ANCHO X 15 ALTO
		glTexCoord2d(0, 1); glVertex2f(10, 0);
		glTexCoord2d(1, 1); glVertex2f(-10, 0);
		glTexCoord2d(1, 0); glVertex2f(-10, 15);
		glTexCoord2d(0, 0); glVertex2f(10, 15);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		ETSIDI::playMusica("sonidos/Musica Intro.mp3", true);
	}

	//PANTALLA DE JUEGO

	else if (modo == JUGAR1) 
	{
		if ((m_tablero->mate(1) == TRUE) || m_tablero->mate(0) == TRUE) { modo = FINAL; }
		
		else {
			centro_x = N * ancho / 2;
			centro_y = -N * ancho / 2;
			centro_z = 0;

			//Borrado de la pantalla	
			glClearColor(1, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			//Para definir el punto de vista
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			if (m_tablero->turnos % 2 != 0) gluLookAt(centro_x, centro_y, -14, centro_x, centro_y, centro_z, 0, 1, 0);
			if (m_tablero->turnos % 2 == 0) gluLookAt(centro_x, centro_y, -14, centro_x, centro_y, centro_z, 0, -1, 0);
			glEnable(GL_LIGHTING);

			//PINTADO DE PIEZAS
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					m_tablero->getCas()[i][j].getPieza()->draw(1);
				}
			}

			//Pinta el tablero (casillas)
			drawMatriz();
			if (inicio == TRUE)
			{

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						glTranslatef(i, -j, 0);
						if (i % 2 == 0 && j % 2 == 0)
						{
							m_tablero->getCas()[i][j].setColor(0);
							m_tablero->getCas()[i][j].draw();
						}
						if (i % 2 != 0 && j % 2 != 0)
						{
							m_tablero->getCas()[i][j].setColor(0);
							m_tablero->getCas()[i][j].draw();
						}
						else {
							m_tablero->getCas()[i][j].setColor(1);
							m_tablero->getCas()[i][j].draw();
						}
						glTranslatef(-i, j, 0);
					}
				}
			}


			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero1.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			//EL CENTRO DE LA IMAGEN ES EL (0, 7.5)
				//TIENE DIMENSIONES DE 20 ANCHO X 15 ALTO
			glTexCoord2d(0, 1); glVertex2f(N * ancho + 4, -N * ancho - 4);
			glTexCoord2d(1, 1); glVertex2f(N * ancho + 4, 4);
			glTexCoord2d(1, 0); glVertex2f(-4, 4);
			glTexCoord2d(0, 0); glVertex2f(-4, -N * ancho - 4);
			glEnd();
			//Dibuja un rectangulo transparente sobre el tablero para capturar el raton
			//con gluUnProject
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			GLTools::Color(gltools::WHITE, 1.0f);
			glTranslatef(centro_x, centro_y, centro_z);
			glRectf(N * ancho / 2.0f, N * ancho / 2.0f, -N * ancho / 2.0f, -N * ancho / 2.0f);
			glTranslatef(-centro_x, -centro_y, -centro_z);
			glEnable(GL_LIGHTING);

			//Pintado de Turnos
			ETSIDI::setTextColor(255, 255, 255);
			ETSIDI::setFont("fuentes/1up.ttf", 18);
			if (m_tablero->turnos % 2 == 0) ETSIDI::printxy("TURNO NEGRAS ", 0, -8);
			if (m_tablero->turnos % 2 != 0) ETSIDI::printxy("TURNO BLANCAS ", 8, 0);

			//Pintado de Jaque
			ETSIDI::setTextColor(255, 255, 255);
			ETSIDI::setFont("fuentes/1up.ttf", 10);
			if (m_tablero->jaque(paridad) == 1 && paridad == 1) ETSIDI::printxy("JAQUE NEGRAS ", 5, -8);
			if (m_tablero->jaque(paridad) == 1 && paridad == 0) ETSIDI::printxy("JAQUE BLANCAS ", 3, 0);

			//Pintado MATE
			ETSIDI::setTextColor(255, 255, 255);
			ETSIDI::setFont("fuentes/1up.ttf", 10);
			if (m_tablero->mate(paridad) == 1 && paridad == 1) ETSIDI::printxy("MATE NEGRAS ", 5, -8);
			if (m_tablero->mate(paridad) == 1 && paridad == 0) ETSIDI::printxy("MATE BLANCAS ", 3, 0);

			glDisable(GL_TEXTURE_2D);
		}
	}

	else if (modo == JUGAR2)
	{
	if ((m_tablero->mate(1) == TRUE) || m_tablero->mate(0) == TRUE) { modo = FINAL; }

		else {
			centro_x = N * ancho / 2;
			centro_y = -N * ancho / 2;
			centro_z = 0;

			//Borrado de la pantalla	
			glClearColor(1, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			//Para definir el punto de vista
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			if (m_tablero->turnos % 2 != 0) gluLookAt(centro_x, centro_y, -14, centro_x, centro_y, centro_z, 0, 1, 0);
			if (m_tablero->turnos % 2 == 0) gluLookAt(centro_x, centro_y, -14, centro_x, centro_y, centro_z, 0, -1, 0);
			glEnable(GL_LIGHTING);

			//PINTADO DE PIEZAS
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					m_tablero->getCas()[i][j].getPieza()->draw(2);
				}
			}

			//Pinta el tablero (casillas)
			drawMatriz();
			if (inicio == TRUE)
			{

				for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					glTranslatef(i, -j, 0);
					if (i % 2 == 0 && j % 2 == 0)
					{
						m_tablero->getCas()[i][j].setColor(0);
						m_tablero->getCas()[i][j].draw();
					}
					if (i % 2 != 0 && j % 2 != 0)
					{
						m_tablero->getCas()[i][j].setColor(0);
						m_tablero->getCas()[i][j].draw();
					}
					else {
						m_tablero->getCas()[i][j].setColor(1);
						m_tablero->getCas()[i][j].draw();
						}
					glTranslatef(-i, j, 0);
					}
				}
			}


			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero2.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			//EL CENTRO DE LA IMAGEN ES EL (0, 7.5)
			//TIENE DIMENSIONES DE 20 ANCHO X 15 ALTO
			glTexCoord2d(0, 1); glVertex2f(N * ancho + 4, -N * ancho - 4);
			glTexCoord2d(1, 1); glVertex2f(N * ancho + 4, 4);
			glTexCoord2d(1, 0); glVertex2f(-4, 4);
			glTexCoord2d(0, 0); glVertex2f(-4, -N * ancho - 4);
			glEnd();
			//Dibuja un rectangulo transparente sobre el tablero para capturar el raton
			//con gluUnProject
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			GLTools::Color(gltools::WHITE, 1.0f);
			glTranslatef(centro_x, centro_y, centro_z);
			glRectf(N * ancho / 2.0f, N * ancho / 2.0f, -N * ancho / 2.0f, -N * ancho / 2.0f);
			glTranslatef(-centro_x, -centro_y, -centro_z);
			glEnable(GL_LIGHTING);

			//Pintado de Turnos
			ETSIDI::setTextColor(0, 0, 0);
			ETSIDI::setFont("fuentes/1up.ttf", 18);
			if (m_tablero->turnos % 2 == 0) ETSIDI::printxy("TURNO NEGRAS ", 0, -8);
			if (m_tablero->turnos % 2 != 0) ETSIDI::printxy("TURNO BLANCAS ", 8, 0);

			//Pintado de Jaque
			ETSIDI::setTextColor(0, 0, 0);
			ETSIDI::setFont("fuentes/1up.ttf", 10);
			if (m_tablero->jaque(paridad) == 1 && paridad == 1) ETSIDI::printxy("JAQUE NEGRAS ", 5, -8);
			if (m_tablero->jaque(paridad) == 1 && paridad == 0) ETSIDI::printxy("JAQUE BLANCAS ", 3, 0);

			//Pintado de mate
			ETSIDI::setTextColor(0, 0, 0);
			ETSIDI::setFont("fuentes/1up.ttf", 10);
			if (m_tablero->mate(paridad) == 1 && paridad == 1) ETSIDI::printxy("MATE NEGRAS ", 5, -8);
			if (m_tablero->mate(paridad) == 1 && paridad == 0) ETSIDI::printxy("MATE BLANCAS ", 3, 0);

			glDisable(GL_TEXTURE_2D);
		}
	}

	//PANTALLA DE PAUSA
	else if (modo == PAUSA)
	{
		ETSIDI::stopMusica();

		centro_x = 0;
		centro_y = 7.5;
		centro_z = 0;

		//Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(centro_x, centro_y, -20, centro_x, centro_y, centro_z, 0, 1, 0);
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/pausa.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		//EL CENTRO DE LA IMAGEN ES EL (0, 7.5)
		//TIENE DIMENSIONES DE 20 ANCHO X 15 ALTO
		glTexCoord2d(0, 1); glVertex2f(10, 0);
		glTexCoord2d(1, 1); glVertex2f(-10, 0);
		glTexCoord2d(1, 0); glVertex2f(-10, 15);
		glTexCoord2d(0, 0); glVertex2f(10, 15);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	//PANTALLA DE SALIDA

	else if (modo == FINAL) 
		{

		if (m_tablero->turnos % 2 == 0)  //GANAN NEGRAS
		{
		centro_x = 0;
		centro_y = 7.5;
		centro_z = 0;
		//Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(centro_x, centro_y, -20, centro_x, centro_y, centro_z, 0, 1, 0);
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/mateNegras.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		//EL CENTRO DE LA IMAGEN ES EL (0, 7.5)
		//TIENE DIMENSIONES DE 20 ANCHO X 15 ALTO
		glTexCoord2d(0, 1); glVertex2f(10, 0);
		glTexCoord2d(1, 1); glVertex2f(-10, 0);
		glTexCoord2d(1, 0); glVertex2f(-10, 15);
		glTexCoord2d(0, 0); glVertex2f(10, 15);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		ETSIDI::playMusica("sonidos/Musica Intro.mp3", true);
		}
	else //GANAN BLANCAS
		{
		centro_x = 0;
		centro_y = 7.5;
		centro_z = 0;
		//Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(centro_x, centro_y, -20, centro_x, centro_y, centro_z, 0, 1, 0);
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/mateBlancas.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		//EL CENTRO DE LA IMAGEN ES EL (0, 7.5)
		//TIENE DIMENSIONES DE 20 ANCHO X 15 ALTO
		glTexCoord2d(0, 1); glVertex2f(10, 0);
		glTexCoord2d(1, 1); glVertex2f(-10, 0);
		glTexCoord2d(1, 0); glVertex2f(-10, 15);
		glTexCoord2d(0, 0); glVertex2f(10, 15);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		ETSIDI::playMusica("sonidos/Musica Intro.mp3", true);
		}
	}
}

void TableroGL::MouseButton(int x, int y, int button, bool down, bool sKey, bool ctrlKey) {
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	//finally cell coordinates
	casillaMundo(posX, posY, xcas_sel, ycas_sel);

	///////////////////////////	
	//capture other mouse events

	if (down) {
		controlKey = ctrlKey;
		shiftKey = sKey;
	}
	else {
		controlKey = shiftKey = false;
	}
	if (button == MOUSE_LEFT_BUTTON || button == MOUSE_RIGHT_BUTTON)
		leftButton = down;

	///////////////////////////

		//***WRITE ACTIONS CONNECTED TO MOUSE STATE HERE

		//print cell coordinates after click

	if (m_tablero->turnos % 2 == 0) { paridad = TRUE; }
	else { paridad = FALSE; }

	if (down && (paridad == FALSE))
	{
		ETSIDI::play("sonidos/click.wav");
		cout << "Turno numero: " << m_tablero->turnos << endl;
		switch (seleccion)
		{
		case FALSE:
		{
			if (m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor() == Pieza::BLANCO) {
				cout << "Posicion Inicial" << endl;

				xorig = xcas_sel;
				yorig = ycas_sel;

				m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->coutPieza(xcas_sel, ycas_sel,
					m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor(), m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo());
				seleccion = TRUE;
			}
			if (m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor() == Pieza::NEGRO) {
				cout << "NO ES TU TURNO" << endl;
			}
			break;
		}

		case TRUE:
		{
			seleccion = FALSE;	//para la alternancia de clicks

			int tipo = m_tablero->getCas()[xorig][yorig].getPieza()->getTipo();
			int tipo2 = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();
			int color = m_tablero->getCas()[xorig][yorig].getPieza()->getColor();
			int color2 = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor();
			Pieza::color_p color3 = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor();
			Pieza::color_p color4 = m_tablero->getCas()[xorig][yorig].getPieza()->getColor();

			if (m_tablero->getCas()[xorig][yorig].getPieza()->mover(Vector(xorig, yorig), Vector(xcas_sel, ycas_sel), color, color2) == TRUE 
				&& m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) {
				cout << "Posicion Final:" << endl;
				if (color == Pieza::BLANCO)
				{
					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					if(modo == JUGAR1 && tipo2 > -1) ETSIDI::play("sonidos/comer.mp3");
					if (modo == JUGAR2 && tipo2 > -1) ETSIDI::play("sonidos/comer futbol.mp3");
					m_tablero->getCas()[xcas_sel][ycas_sel].creaPieza(xcas_sel - 7, ycas_sel, tipo, Pieza::BLANCO);
					m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->coutPieza(xcas_sel, ycas_sel,
						m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor(), m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo());

					if (m_tablero->jaque(color)) {
						cout << "JAQUE BLANCAS" << endl;
						m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
						m_tablero->getCas()[xcas_sel][ycas_sel].creaPieza(xcas_sel, ycas_sel, tipo2, color3);
						m_tablero->getCas()[xorig][yorig].~Casilla();
						m_tablero->getCas()[xorig][yorig].creaPieza(xorig - 7, yorig, tipo, Pieza::BLANCO);
						break;
					}
					if (m_tablero->mate(color)) {
						cout << "MATE BLANCAS" << endl;
						break;
					}
					if ((xcas_sel == 0) && (tipo == 0)) {
						m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
						m_tablero->getCas()[xcas_sel][ycas_sel].creaPieza(xcas_sel - 7, ycas_sel, 4, (Pieza::color_p) color);
						m_tablero->turnos++;
					}
					else { m_tablero->turnos++; }
				}
			}
			else { break; }
			//Pieza anterior a NoPieza
			m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
			xorig = 0;
			yorig = 0;
			break;
		}
		default:
			xcas_sel = xorig;
			ycas_sel = yorig;
			cout << "mueve el rival" << endl;
		}
	}
	if (down && (paridad == TRUE)) {
		ETSIDI::play("sonidos/click.wav");
		cout << "Turno numero: " << m_tablero->turnos << endl;
		switch (seleccion)
		{
		case FALSE:
		{
			if (m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor() == Pieza::NEGRO) {
				cout << "Posicion Inicial" << endl;

				xorig = xcas_sel;
				yorig = ycas_sel;

				m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->coutPieza(xcas_sel, ycas_sel,
					m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor(), m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo());
				seleccion = TRUE;
			}
			break;
		}

		case TRUE:
		{
			seleccion = FALSE;	//para la alternancia de clicks

			int tipo = m_tablero->getCas()[xorig][yorig].getPieza()->getTipo();
			int tipo2 = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();
			int color = m_tablero->getCas()[xorig][yorig].getPieza()->getColor();
			int color2 = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor();
			Pieza::color_p color3 = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor();

			if (m_tablero->getCas()[xorig][yorig].getPieza()->mover(Vector(xorig, yorig), Vector(xcas_sel, ycas_sel), color, color2) == TRUE
				&& m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) {
				cout << "Posicion Final:" << endl;
				if (color == Pieza::NEGRO)
				{
					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					if (modo == JUGAR1 && tipo2 > -1) ETSIDI::play("sonidos/comer.mp3");
					if (modo == JUGAR2 && tipo2 > -1) ETSIDI::play("sonidos/comer futbol.mp3");
					m_tablero->getCas()[xcas_sel][ycas_sel].creaPieza(-xcas_sel, ycas_sel, tipo, Pieza::NEGRO);
					m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->coutPieza(xcas_sel, ycas_sel,
						m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor(), m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo());

					if (m_tablero->jaque(color) == TRUE) {
						cout << "JAQUE NEGRAS" << endl;
						m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
						m_tablero->getCas()[xcas_sel][ycas_sel].creaPieza(xcas_sel - 7, ycas_sel, tipo2, color3);
						m_tablero->getCas()[xorig][yorig].~Casilla();
						m_tablero->getCas()[xorig][yorig].creaPieza(-xorig, yorig, tipo, Pieza::NEGRO);
						break;
					}
					if ((m_tablero->mate(color))) {
						cout << "MATE NEGRAS" << endl;
						break;
					}
					if ((xcas_sel == 7) && (tipo == 0)) {
						m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
						m_tablero->getCas()[xcas_sel][ycas_sel].creaPieza(-xcas_sel, ycas_sel, 4, (Pieza::color_p)color);
						m_tablero->turnos++;
					}
					else { m_tablero->turnos++; }
				}
			}
			else { break; }
			//Pieza anterior a NoPieza
			m_tablero->getCas()[xorig][yorig].creaPieza(xorig, yorig, -1, Pieza::NO_COLOR);
			xorig = 0;
			yorig = 0;
			break;
		}
		default:
			xcas_sel = xorig;
			ycas_sel = yorig;
			cout << "mueve el rival" << endl;
		}
	}
}