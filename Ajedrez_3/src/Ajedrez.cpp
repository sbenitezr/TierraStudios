#include "TableroGL.h"
#include "freeglut.h"
#include <iostream>

using namespace std;

#define GRID_SIZE	8

Tablero tab(GRID_SIZE);
TableroGL escenario(&tab);

//los callback necesarios
void OnDraw(void);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);
//void OnTimer(int value);

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez_de_diez");

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);
	//glutTimerFunc(25, OnTimer, 0);

	//Inicializamos luz y perspectiva
	escenario.init();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	escenario.draw();
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//Pilla del teclado (ya veremos si lo usamos)
	//escenario.tecla(key);

	glutPostRedisplay();
}
void OnMouseClick(int b, int state, int x, int y)
{
	//Captura los clicks del raton
	//le da el controla la escena del tablero
	bool down = (state == GLUT_DOWN);
	int button;
	if (b == GLUT_LEFT_BUTTON) {
		button = MOUSE_LEFT_BUTTON;
	}
	if (b == GLUT_RIGHT_BUTTON) {
		button = MOUSE_RIGHT_BUTTON;
		cout << "MOUSE_RIGHT_BUTTON" << endl;
	}

	int specialKey = glutGetModifiers();
	bool ctrlKey = (specialKey & GLUT_ACTIVE_CTRL) ? true : false;
	bool sKey = specialKey & GLUT_ACTIVE_SHIFT;


	escenario.MouseButton(x, y, b, down, sKey, ctrlKey);
	glutPostRedisplay();
}

/*void OnTimer(int value)
{
	escenario.draw();
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}*/
