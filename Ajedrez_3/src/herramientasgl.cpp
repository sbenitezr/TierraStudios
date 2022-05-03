#include "herramientasgl.h"

#include <iostream>
#include <string>

#include "freeglut.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
using namespace gltools;

std::vector<std::string> GLTools::textures_names;
std::vector<unsigned int> GLTools::textures_ids;

void GLTools::Color(int i, float transparency)
{
	if (i == BLACK)		glColor4f(0, 0, 0, transparency);
	else if (i == WHITE)	glColor4f(1.0f, 1.0f, 1.0f, transparency);
	else if (i == RED)		glColor4f(1.0f, 0, 0, transparency);
	else if (i == GREEN)	glColor4f(0, 1.0f, 0, transparency);
	else if (i == BLUE)	glColor4f(0, 0, 1.0f, transparency);
	else if (i == MAGENTA)	glColor4f(1.0f, 0, 1.0f, transparency);
	else if (i == CYAN)	glColor4f(0.0f, 1.0f, 1.0f, transparency);
	else if (i == GREY)	glColor4f(0.5f, 0.5f, 0.5f, transparency);
	else if (i == YELLOW)  glColor4f(1.0f, 1.0f, 0.0f, transparency);
	else if (i == ORANGE)  glColor4f(1.0f, 0.5f, 0.0f, transparency);
	else if (i == PURPLE)  glColor4f(0.3, 0.3, 1.0f, transparency);
	else if (i == PINK) 	glColor4f(1.0f, 0.3, 0.3f, transparency);
}

void GLTools::BackgroundColor(int i)
{
	if (i == BLACK)		glClearColor(0, 0, 0, 0);
	else if (i == WHITE)	glClearColor(1.0f, 1.0f, 1.0f, 0);
	else if (i == RED)		glClearColor(1.0f, 0, 0, 0);
	else if (i == GREEN)	glClearColor(0, 1.0f, 0, 0);
	else if (i == BLUE)	glClearColor(0, 0, 1.0f, 0);
}

void GLTools::Print(string msg, float x, float y, float z, int fuente) {
	//only considers two fonts, use switch for different fonts
	//prints letters as bitmaps in HELVETICA FORMAT using basic
	//glut size types (10,12,18)

	glDisable(GL_LIGHTING);
	int i;	int len = (int)msg.size();
	glRasterPos3f(x, y, z);

	switch (fuente) {
	case 1:
		for (i = 0; i < len; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, msg[i]);
		}
		break;
	case 2:
		for (i = 0; i < len; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, msg[i]);
		}
		break;
	case 3:
		for (i = 0; i < len; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[i]);
		}
		break;
	default: //largest type
		for (i = 0; i < len; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[i]);
		}
	}

	glEnable(GL_LIGHTING);
}
unsigned int GLTools::LoadTexture(string nombre)
{
	for (unsigned int i = 0; i < textures_ids.size(); i++)
	{
		if (textures_names[i] == nombre)
		{
			return textures_ids[i];
		}
	}

	unsigned int textura = -1;
	glGenTextures(1, &textura);
	glBindTexture(GL_TEXTURE_2D, textura);

	int wrap = 1;
	// select modulate to mix texture with color for shading
  // glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	// when texture area is small, bilinear filter the closest mipmap
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	// when texture area is large, bilinear filter the first mipmap
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// if wrap is true, the texture wraps over at the edges (repeat)
	//       ... false, the texture ends at the edges (clamp)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap ? GL_REPEAT : GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap ? GL_REPEAT : GL_CLAMP);


	FILE* File = NULL;

	return textura;
}

void GLTools::DeleteTextures()
{
	for (unsigned int i = 0; i < textures_ids.size(); i++)
	{
		glDeleteTextures(1, &textures_ids[i]);
	}
	textures_ids.clear();
	textures_names.clear();
	glBindTexture(GL_TEXTURE_2D, NULL);
}
void GLTools::DrawFrame()
{
	glDisable(GL_LIGHTING);
	glLineWidth(2);
	glBegin(GL_LINES);
	GLTools::Color(RED);
	glVertex3f(0, 0, 0);	glVertex3f(0.5, 0, 0);
	GLTools::Color(GREEN);
	glVertex3f(0, 0, 0);	glVertex3f(0, 0.25, 0);
	GLTools::Color(BLUE);
	glVertex3f(0, 0, 0);	glVertex3f(0, 0, 0.25);
	glEnd();
	//label axis
	GLTools::Color(WHITE);
	GLTools::Print("x", 0.6F, 0, 0);
	GLTools::Print("y", 0.0, 0.35F, 0);
	GLTools::Print("z", 0.0, 0, 0.35F);
	glEnable(GL_LIGHTING);
}

void GLTools::DrawGrid(int num_cells, float size)
{
	glEnable(GL_LIGHTING);
	//WORLD FRAME
	Color(MAGENTA);

	glLineWidth(1);
	glBegin(GL_LINES);
	glNormal3f(0, 0, 1);
	for (int i = 0; i < num_cells; i++)
	{
		glVertex3f(i * size, -num_cells * size, 0);
		glVertex3f(i * size, num_cells * size, 0);
		glVertex3f(-i * size, -num_cells * size, 0);
		glVertex3f(-i * size, num_cells * size, 0);

		glVertex3f(-num_cells * size, i * size, 0);
		glVertex3f(num_cells * size, i * size, 0);
		glVertex3f(-num_cells * size, -i * size, 0);
		glVertex3f(num_cells * size, -i * size, 0);
	}
	glEnd();

	//	glEndList();
}

void GLTools::DrawGrid(int num_cells, float size, int col, float transparency)
{
	glEnable(GL_LIGHTING);

	//WORLD FRAME
	Color(col, transparency);

	glLineWidth(1);
	glBegin(GL_LINES);
	glNormal3f(0, 0, 1);
	for (int i = 0; i < num_cells; i++) {
		glVertex3f(i * size, -num_cells * size, 0);
		glVertex3f(i * size, num_cells * size, 0);

		glVertex3f(-i * size, -num_cells * size, 0);
		glVertex3f(-i * size, num_cells * size, 0);

		glVertex3f(-num_cells * size, i * size, 0);
		glVertex3f(num_cells * size, i * size, 0);


		glVertex3f(-num_cells * size, -i * size, 0);
		glVertex3f(num_cells * size, -i * size, 0);

	}
	glEnd();
}

void GLTools::DrawExactGrid(int N, float size, int col, float transparency) {
	//////////////
	// Draws an exact NxN grid centered in (0,0)
	// N should be an even number

	glEnable(GL_LIGHTING);
	Color(col, transparency);

	glLineWidth(1);
	glBegin(GL_LINES);
	int lim = N / 2;

	for (int i = 0; i <= lim; i++) {
		//horizontales
		glVertex3f(lim * size, i * size, 0);
		glVertex3f(-lim * size, i * size, 0);

		glVertex3f(lim * size, -i * size, 0);
		glVertex3f(-lim * size, -i * size, 0);

		//verticales
		glVertex3f(i * size, -lim * size, 0);
		glVertex3f(i * size, lim * size, 0);

		glVertex3f(-i * size, -lim * size, 0);
		glVertex3f(-i * size, lim * size, 0);

	}
	glEnd();
}