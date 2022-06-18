#include "TableroGL.h"
#include "freeglut.h"
#include <iostream>

using namespace std;

#define GRID_SIZE	8

Tablero tab(GRID_SIZE);
static TableroGL escenario = &tab;
Tablero* TableroGL::m_tablero = &tab;

void OnDraw(void);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);

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

	//Inicializamos luz y perspectiva
	escenario.init();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	escenario.draw();
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	escenario.tecla(key);

	glutPostRedisplay();
}

void OnMouseClick(int b, int state, int x, int y)
{
	//Captura los clicks del raton le da el control a la escena del tablero
	bool down = (state == GLUT_DOWN);
	int button;
	if (b == GLUT_LEFT_BUTTON) {
		button = MOUSE_LEFT_BUTTON;
	}
	int specialKey = glutGetModifiers();
	bool ctrlKey = (specialKey & GLUT_ACTIVE_CTRL) ? true : false;
	bool sKey = specialKey & GLUT_ACTIVE_SHIFT;
	escenario.MouseButton(x, y, b, down, sKey, ctrlKey);
	glutPostRedisplay();
}