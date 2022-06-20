#include "TableroGL.h"
#include "herramientasgl.h"
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include "freeglut.h"
#include "ETSIDI.h"
using namespace std;
int fin = 0;

TableroGL::TableroGL(Tablero* t) :m_tablero(t) {
	ancho = 1;
	N = t->getTamanio();
	dist = 2;
	centro_z = 0;
	modo = INICIO;
}

void TableroGL::selCasilla(Vector p) {
	m_tablero->getCas()[p.x][p.y].selCas();
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
		if (key == 'j' || key == 'J')
		{
			modo = JUGAR;
			ETSIDI::play("sonidos/mola mucho este modo de juego.wav");
		}
		if (key == 's' || key == 'S') 
		{
			modo = FINAL;
		}
	}

	//PANTALLA DE JUGAR
	if (modo == JUGAR) 
	{
		ETSIDI::playMusica("sonidos/Musica para el juego.mp3", true);
		if (key == 'p' || key == 'P') 
		{
			modo = PAUSA;
			ETSIDI::stopMusica();
		}
	}

	//PANTALLA DE PAUSA
	if (modo == PAUSA) 
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

		//Coordinador de las ventanas
		if (key == 'j' || key == 'J') {
			modo = JUGAR;
			ETSIDI::playMusica("sonidos/Musica para el juego.mp3", true);
		}
		if (key == 'r' || key == 'R') {
			m_tablero->tableroInicio();
			m_tablero->turnos = 1;
			modo = JUGAR;
			ETSIDI::playMusica("sonidos/Musica para el juego.mp3", true);
		}
		if (key == 'e' || key == 'E')
			exit(0);
	}

	//PANTALLA FINAL
	if (modo == FINAL) 
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/finalP.png").id);
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

		ETSIDI::stopMusica();


		if (key == 'j' || key == 'J') {
			m_tablero->tableroInicio();
			m_tablero->turnos = 1;
			modo = JUGAR;
			ETSIDI::playMusica("sonidos/Musica para el juego.mp3", true);
		}

		if (key == 'e' || key == 'E') {
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

	else if (modo == JUGAR) 
	{
		//if ((m_tablero->jaqueN() && m_tablero->turnos % 2 != 0) || (m_tablero->jaqueB() && m_tablero->turnos % 2 == 0))
		if((m_tablero->mateN()==TRUE)|| (m_tablero->mateB() == TRUE))
		{
			modo = FINAL;
		}
		else
		{
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
					m_tablero->getCas()[i][j].getPieza()->draw();
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
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero.png").id);
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
			if (m_tablero->jaqueN() == 1) ETSIDI::printxy("JAQUE NEGRAS ", 5, -8);
			if (m_tablero->jaqueB() == 1) ETSIDI::printxy("JAQUE BLANCAS ", 3, 0);

			glDisable(GL_TEXTURE_2D);
		}
		
	}

	//PANTALLA DE SALIDA

	else if (modo == FINAL) 
	{

		if ((m_tablero->mateB()==TRUE))  //GANAN NEGRAS
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
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/gameover.png").id);
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
		else if((m_tablero->mateN() == TRUE))//GANAN BLANCAS
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
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/gameover.png").id);
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
if (button == MOUSE_LEFT_BUTTON)
leftButton = down;
///////////////////////////

	//***WRITE ACTIONS CONNECTED TO MOUSE STATE HERE

	//print cell coordinates after click
bool paridad = FALSE;
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
		cout << "Posicion Inicial" << endl;

		//selCasilla(Vector(xcas_sel,ycas_sel));

		int tipo = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();
		int color = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor();

		//QUEDA MUY FEO PERO ES POR POBAR
		xorig = xcas_sel;
		yorig = ycas_sel;

		if (tipo == Pieza::REINA && color == Pieza::BLANCO)
		{
			ETSIDI::play("sonidos/la reina.wav");
			cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Reina Blanca" << endl;
			seleccion = TRUE;
		}
		if (tipo == Pieza::PEON && color == Pieza::BLANCO)
		{
			cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Peon Blanco" << endl;
			seleccion = TRUE;
		}
		if (tipo == Pieza::REY && color == Pieza::BLANCO)
		{
			cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Rey Blanco" << endl;
			seleccion = TRUE;
		}
		if (tipo == Pieza::CABALLO && color == Pieza::BLANCO)
		{
			cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Caballo Blanco" << endl;
			seleccion = TRUE;
		}
		if (tipo == Pieza::ALFIL && color == Pieza::BLANCO)
		{
			cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Alfil Blanco" << endl;
			seleccion = TRUE;
		}
		if (tipo == Pieza::TORRE && color == Pieza::BLANCO)
		{
			cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Torre Blanca" << endl;
			seleccion = TRUE;
		}
		if (tipo == Pieza::CASILLA_VACIA)
		{
			cout << "vacio" << endl;
			seleccion = TRUE;
		}
		break;
	}

	case TRUE:
	{
		seleccion = FALSE;	//para la alternancia de clicks
		cout << "Posicion Final:" << endl;
		int tipo = m_tablero->getCas()[xorig][yorig].getPieza()->getTipo();
		int tipo2= m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();
		int color = m_tablero->getCas()[xorig][yorig].getPieza()->getColor();
		int color2 = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor();

		if (tipo == Pieza::REINA)
		{
			if (((m_tablero->movalfil(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) || (m_tablero->movtorre(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) && (m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) {
				if (color == Pieza::BLANCO)
				{
					int tipoPieza = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();

					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
					cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Reina Blanca" << endl;

					if (m_tablero->jaqueB() == TRUE) {

						if (tipoPieza == 4) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Reina(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 3) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Reina(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 2) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Reina(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 1) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Reina(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						if (tipoPieza == 0) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Reina(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}

						else {
							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new NoPieza(Vector(xcas_sel, ycas_sel)));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Reina(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
					}
					else { m_tablero->turnos++; }
				}
			}

			else { break; }
		}
		if (tipo == Pieza::PEON)
		{
			if ((m_tablero->movpeon(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) && (m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) {
				
				if (color == Pieza::BLANCO)
				{
					int tipoPieza = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();

					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel - 5, ycas_sel), Pieza::BLANCO));
					cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Peon Blanco" << endl;

					if (m_tablero->jaqueB() == TRUE) {

						if (tipoPieza == 4) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Peon(Vector(xorig - 5, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 3) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Peon(Vector(xorig - 5, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 2) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Peon(Vector(xorig - 5, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 1) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Peon(Vector(xorig - 5, yorig), Pieza::BLANCO));
							break;
						}
						if (tipoPieza == 0) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Peon(Vector(xorig - 5, yorig), Pieza::BLANCO));
							break;
						}

						else {
							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new NoPieza(Vector(xcas_sel, ycas_sel)));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Peon(Vector(xorig - 5, yorig), Pieza::BLANCO));
							break;
						}
					}
					else { m_tablero->turnos++; }
				}
			}

			else { break; }
		}
		if (tipo == Pieza::REY)
		{
			if ((m_tablero->movrey(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) && (m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) {
				if (color == Pieza::BLANCO)
				{
					int tipoPieza= m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();
					
					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Rey(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
					cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Rey Blanco" << endl;

					if (m_tablero->jaqueB() == TRUE) {

						if (tipoPieza == 4) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Rey(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 3) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Rey(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 2) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Rey(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 1) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Rey(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						if (tipoPieza == 0) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Rey(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}

						else {
							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new NoPieza(Vector(xcas_sel, ycas_sel)));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Rey(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
					}
					else { m_tablero->turnos++; }
				}
			}

			else { break; }
		}
		if (tipo == Pieza::CABALLO)
		{

			if ((m_tablero->movcaballo(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) && (m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) {
				if (color == Pieza::BLANCO)
				{
					int tipoPieza = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();

					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
					cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Caballo Blanco" << endl;

					if (m_tablero->jaqueB() == TRUE) {

						if (tipoPieza == 4) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Caballo(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 3) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Caballo(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 2) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Caballo(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 1) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Caballo(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						if (tipoPieza == 0) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Caballo(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}

						else {
							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new NoPieza(Vector(xcas_sel, ycas_sel)));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Caballo(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
					}
					else { m_tablero->turnos++; }
				}
			}

			else { break; }
		}
		if (tipo == Pieza::ALFIL)
		{
			if ((m_tablero->movalfil(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) && (m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) {
				if (color == Pieza::BLANCO)
				{
					int tipoPieza = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();

					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
					cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Alfil Blanco" << endl;

					if (m_tablero->jaqueB() == TRUE) {

						if (tipoPieza == 4) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Alfil(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 3) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Alfil(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 2) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Alfil(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 1) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Alfil(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						if (tipoPieza == 0) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Alfil(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}

						else {
							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new NoPieza(Vector(xcas_sel, ycas_sel)));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Alfil(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
					}
					else { m_tablero->turnos++; }
				}
			}

			else { break; }
		}
		if (tipo == Pieza::TORRE)
		{
			if ((m_tablero->movtorre(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) && (m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) {
				if (color == Pieza::BLANCO)
				{
					int tipoPieza = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();

					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
					cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Torre Blanca" << endl;

					if (m_tablero->jaqueB() == TRUE) {

						if (tipoPieza == 4) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Torre(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 3) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Torre(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 2) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Torre(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						else if (tipoPieza == 1) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Torre(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
						if (tipoPieza == 0) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Torre(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}

						else {
							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new NoPieza(Vector(xcas_sel, ycas_sel)));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Torre(Vector(xorig - 7, yorig), Pieza::BLANCO));
							break;
						}
					}
					else { m_tablero->turnos++; }
				}
			}

			else { break; }
		}
		if (tipo == Pieza::CASILLA_VACIA)
		{
			cout << "vacio" << endl;
		}

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
		cout << "Posicion Inicial" << endl;

		//selCasilla(Vector(xcas_sel,ycas_sel));

		int tipo = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();
		int color = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor();
		int color2 = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor();

		xorig = xcas_sel;
		yorig = ycas_sel;

		if (tipo == Pieza::REINA && color == Pieza::NEGRO)
		{
			ETSIDI::play("sonidos/la reina.wav");
			cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Reina Negra" << endl;
			seleccion = TRUE;
		}
		if (tipo == Pieza::PEON && color == Pieza::NEGRO)
		{
			cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Peon Negro" << endl;
			seleccion = TRUE;
		}
		if (tipo == Pieza::REY && color == Pieza::NEGRO)
		{
			cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Rey Negro" << endl;
			seleccion = TRUE;
		}
		if (tipo == Pieza::CABALLO && color == Pieza::NEGRO)
		{
			cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Caballo Negro" << endl;
			seleccion = TRUE;
		}
		if (tipo == Pieza::ALFIL && color == Pieza::NEGRO)
		{
			cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Alfil Negro" << endl;
			seleccion = TRUE;
		}
		if (tipo == Pieza::TORRE && color == Pieza::NEGRO)
		{
			cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Torre Negra" << endl;
			seleccion = TRUE;
		}
		if (tipo == Pieza::CASILLA_VACIA)
		{
			cout << "vacio" << endl;
		}
		break;
	}

	case TRUE:
	{
		seleccion = FALSE;	//para la alternancia de clicks
		cout << "Posicion Final:" << endl;
		int tipo = m_tablero->getCas()[xorig][yorig].getPieza()->getTipo();
		int color = m_tablero->getCas()[xorig][yorig].getPieza()->getColor();
		int color2 = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getColor();

		if (tipo == Pieza::REINA)
		{
			if (((m_tablero->movalfil(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) || (m_tablero->movtorre(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) && (m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) {
				if (color == Pieza::NEGRO)
				{
					int tipoPieza = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();

					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
					cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Reina Negra" << endl;

					if (m_tablero->jaqueN() == TRUE) {

						if (tipoPieza == 4) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Reina(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 3) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Reina(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 2) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Reina(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 1) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Reina(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						if (tipoPieza == 0) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel - 5, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Reina(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}

						else {
							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new NoPieza(Vector(xcas_sel, ycas_sel)));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Reina(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
					}
					else { m_tablero->turnos++; }
				}
			}

			else { break; }
		}
		if (tipo == Pieza::PEON)
		{
			if ((m_tablero->movpeon(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) && (m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) {
				if (color == Pieza::NEGRO)
				{
					int tipoPieza = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();

					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
					cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Peon Negra" << endl;

					if (m_tablero->jaqueN() == TRUE) {

						if (tipoPieza == 4) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Peon(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 3) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Peon(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 2) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Peon(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 1) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Peon(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						if (tipoPieza == 0) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel - 5, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Peon(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}

						else {
							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new NoPieza(Vector(xcas_sel, ycas_sel)));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Peon(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
					}
					else { m_tablero->turnos++; }
				}
			}

			else { break; }
		}
		if (tipo == Pieza::REY)
		{
			if ((m_tablero->movrey(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) && (m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) {
				if (color == Pieza::NEGRO)
				{
					int tipoPieza = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();

					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Rey(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
					cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Rey Negro" << endl;

					if (m_tablero->jaqueN() == TRUE) {

						if (tipoPieza == 4) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Rey(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 3) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Rey(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 2) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Rey(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 1) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Rey(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						if (tipoPieza == 0) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel - 5, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Rey(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}

						else {
							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new NoPieza(Vector(xcas_sel, ycas_sel)));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Rey(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
					}
					else { m_tablero->turnos++; }
				}
			}

			else { break; }
		}
		if (tipo == Pieza::CABALLO)
		{

			if ((m_tablero->movcaballo(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) && (m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) {
				if (color == Pieza::NEGRO)
				{
					int tipoPieza = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();

					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
					cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Caballo Negro" << endl;

					if (m_tablero->jaqueN() == TRUE) {

						if (tipoPieza == 4) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Caballo(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 3) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Caballo(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 2) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Caballo(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 1) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Caballo(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						if (tipoPieza == 0) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel - 5, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Caballo(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}

						else {
							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new NoPieza(Vector(xcas_sel, ycas_sel)));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Caballo(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
					}
					else { m_tablero->turnos++; }
				}
			}

			else { break; }
		}
		if (tipo == Pieza::ALFIL)
		{
			if ((m_tablero->movalfil(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) && (m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) {
				if (color == Pieza::NEGRO)
				{
					int tipoPieza = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();

					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
					cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Alfil Negro" << endl;

					if (m_tablero->jaqueN() == TRUE) {

						if (tipoPieza == 4) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Alfil(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 3) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Alfil(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 2) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Alfil(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 1) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Alfil(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						if (tipoPieza == 0) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel - 5, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Alfil(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}

						else {
							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new NoPieza(Vector(xcas_sel, ycas_sel)));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Alfil(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
					}
					else { m_tablero->turnos++; }
				}
			}

			else { break; }
		}
		if (tipo == Pieza::TORRE)
		{
			if ((m_tablero->movtorre(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE) && (m_tablero->enable(xorig, xcas_sel, yorig, ycas_sel, color, color2) == TRUE)) {
				if (color == Pieza::NEGRO)
				{
					int tipoPieza = m_tablero->getCas()[xcas_sel][ycas_sel].getPieza()->getTipo();

					m_tablero->getCas()[xorig][yorig].~Casilla();
					m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
					m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
					m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel, ycas_sel), Pieza::NEGRO));
					cout << "(" << xcas_sel << "," << ycas_sel << ")" << "Torre Negra" << endl;

					if (m_tablero->jaqueN() == TRUE) {

						if (tipoPieza == 4) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Reina(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Torre(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 3) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Alfil(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Torre(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 2) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Torre(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Torre(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						else if (tipoPieza == 1) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Caballo(Vector(xcas_sel - 7, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Torre(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
						if (tipoPieza == 0) {

							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new Peon(Vector(xcas_sel - 5, ycas_sel), Pieza::BLANCO));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Torre(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}

						else {
							m_tablero->getCas()[xcas_sel][ycas_sel].~Casilla();
							m_tablero->getCas()[xcas_sel][ycas_sel].setPieza(new NoPieza(Vector(xcas_sel, ycas_sel)));
							m_tablero->getCas()[xorig][yorig].~Casilla();
							m_tablero->getCas()[xorig][yorig].setPieza(new Torre(Vector(xorig, yorig), Pieza::NEGRO));
							break;
						}
					}
					else { m_tablero->turnos++; }
				}
			}

			else { break; }
		}
		if (tipo == Pieza::CASILLA_VACIA)
		{
			cout << "vacio" << endl;
		}

		//Pieza anterior a NoPieza
		m_tablero->getCas()[xorig][yorig].setPieza(new NoPieza(Vector(xorig, yorig)));
		xorig = 0;
		yorig = 0;
		break;
	}
	default:
		;
	}
}
}